//
//  WXApiManager.m
//  SDKSample
//
//  Created by Jeason on 16/07/2015.
//
//

#import "WXApiManager.h"
#import "AFHTTPRequestOperationManager.h"
#import "AFHTTPSessionManager.h"
#import "Constant.h"

@implementation WXApiManager

#pragma mark - LifeCycle
+(instancetype)sharedManager {
    static dispatch_once_t onceToken;
    static WXApiManager *instance;
    dispatch_once(&onceToken, ^{
        instance = [[WXApiManager alloc] init];
    });
    return instance;
}

- (void)dealloc {
    self.delegate = nil;
    [super dealloc];
}

#pragma mark - WXApiDelegate
- (void)onResp:(BaseResp *)resp {
    if ([resp isKindOfClass:[SendMessageToWXResp class]]) {
        if (_delegate
            && [_delegate respondsToSelector:@selector(managerDidRecvMessageResponse:)]) {
            SendMessageToWXResp *messageResp = (SendMessageToWXResp *)resp;
            [_delegate managerDidRecvMessageResponse:messageResp];
        }
    } else if ([resp isKindOfClass:[SendAuthResp class]]) {
        if (_delegate
            && [_delegate respondsToSelector:@selector(managerDidRecvAuthResponse:)]) {
            SendAuthResp *authResp = (SendAuthResp *)resp;
            [_delegate managerDidRecvAuthResponse:authResp];
        }
        // 向微信请求授权后,得到响应结果
        if ([resp isKindOfClass:[SendAuthResp class]]) {
            SendAuthResp *temp = (SendAuthResp *)resp;
            
            NSLog(@"temp code: %@",temp.code);
            [[NSNotificationCenter defaultCenter] postNotificationName:@"kOcNotifyWxOpenIdResult" object:temp.code];
            return;
            
        }
    } else if ([resp isKindOfClass:[AddCardToWXCardPackageResp class]]) {
        if (_delegate
            && [_delegate respondsToSelector:@selector(managerDidRecvAddCardResponse:)]) {
            AddCardToWXCardPackageResp *addCardResp = (AddCardToWXCardPackageResp *)resp;
            [_delegate managerDidRecvAddCardResponse:addCardResp];
        }
    }else if([resp isKindOfClass:[PayResp class]]){
        //支付返回结果，实际支付结果需要去微信服务器端查询
        NSString *strMsg,*strTitle = [NSString stringWithFormat:@"支付结果"];
        
        switch (resp.errCode) {
            case WXSuccess:
                strMsg = @"支付结果：成功！";
                NSLog(@"支付成功－PaySuccess，retcode = %d", resp.errCode);
                [[NSNotificationCenter defaultCenter] postNotificationName:@"kOcNotifyWxpaySuccess" object:self];
                break;
                
            default:
                strMsg = [NSString stringWithFormat:@"支付结果：失败！"];
                NSLog(@"错误，retcode = %d, retstr = %@", resp.errCode,resp.errStr);
                [[NSNotificationCenter defaultCenter] postNotificationName:@"kOcNotifyWxpayFail" object:self];
                break;
        }
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:strTitle message:strMsg delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
        [alert show];
        [alert release];
    }
    /*
    else if ([resp isKindOfClass:[WXChooseCardResp class]]) {
        if (_delegate
            && [_delegate respondsToSelector:@selector(managerDidRecvChooseCardResponse:)]) {
            WXChooseCardResp *chooseCardResp = (WXChooseCardResp *)resp;
            [_delegate managerDidRecvChooseCardResponse:chooseCardResp];
        }
    }*/
}

// 获取用户个人信息（UnionID机制）
- (void)wechatLoginByRequestForUserInfo {
    AFHTTPRequestOperationManager *manager = [AFHTTPRequestOperationManager manager];
    NSString *accessToken = [[NSUserDefaults standardUserDefaults] objectForKey:WX_ACCESS_TOKEN];
    NSString *openID = [[NSUserDefaults standardUserDefaults] objectForKey:WX_OPEN_ID];
    NSString *userUrlStr = [NSString stringWithFormat:@"%@/userinfo?access_token=%@&openid=%@", WX_BASE_URL, accessToken, openID];
    // 请求用户数据
    [manager GET:userUrlStr parameters:nil success:^(AFHTTPRequestOperation *operation, id responseObject) {
        NSLog(@"请求用户信息的response = %@", responseObject);
        // NSMutableDictionary *userDict = [NSMutableDictionary dictionaryWithDictionary:responseObject];
    } failure:^(AFHTTPRequestOperation *operation, NSError *error) {
        NSLog(@"获取用户信息时出错 = %@", error);
    }];
}

- (void)onReq:(BaseReq *)req {
    if ([req isKindOfClass:[GetMessageFromWXReq class]]) {
        if (_delegate
            && [_delegate respondsToSelector:@selector(managerDidRecvGetMessageReq:)]) {
            GetMessageFromWXReq *getMessageReq = (GetMessageFromWXReq *)req;
            [_delegate managerDidRecvGetMessageReq:getMessageReq];
        }
    } else if ([req isKindOfClass:[ShowMessageFromWXReq class]]) {
        if (_delegate
            && [_delegate respondsToSelector:@selector(managerDidRecvShowMessageReq:)]) {
            ShowMessageFromWXReq *showMessageReq = (ShowMessageFromWXReq *)req;
            [_delegate managerDidRecvShowMessageReq:showMessageReq];
        }
    } else if ([req isKindOfClass:[LaunchFromWXReq class]]) {
        if (_delegate
            && [_delegate respondsToSelector:@selector(managerDidRecvLaunchFromWXReq:)]) {
            LaunchFromWXReq *launchReq = (LaunchFromWXReq *)req;
            [_delegate managerDidRecvLaunchFromWXReq:launchReq];
        }
    }
}

@end
