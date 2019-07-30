//
//  ThirdData.h
//  GloryProject
//
//  Created by zhong on 16/9/9.
//
//

#ifndef ThirdData_h
#define ThirdData_h

#import <Foundation/Foundation.h>

//分享配置
@interface ShareConfig : NSObject
{
    
}
@property BOOL Configed;
//友盟appkey
@property (nonatomic, copy) NSString *AppKey;
//分享链接
@property (nonatomic, copy) NSString *ShareUrl;
//分享标题
@property (nonatomic, copy) NSString *ShareTitle;
//分享内容
@property (nonatomic, copy) NSString *ShareContent;
//分享图片
@property (nonatomic, copy) NSString *ShareMediaPath;

@end

//微信配置
@interface WeChatConfig : NSObject
{
    
}
@property BOOL Configed;
//appid
@property (nonatomic, copy) NSString* WeChatAppID;
//secret
@property (nonatomic, copy) NSString* WeChatAppSecret;
//商户id
@property (nonatomic, copy) NSString* WeChatPartnerID;
//支付秘钥
@property (nonatomic, copy) NSString* WeChatPayKey;
//分享url
@property (nonatomic, copy) NSString* WeChatURL;
@end


#endif /* ThirdData_h */
