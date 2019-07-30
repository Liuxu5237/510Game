//
//  ThirdProtocol.h
//  GloryProject
//
//  Created by zhong on 16/9/8.
//
//

#ifndef ThirdProtocol_h
#define ThirdProtocol_h
#import <Foundation/Foundation.h>

//登陆回调
@protocol LoginDelegate <NSObject>

- (void) onLoginStart:(NSString *)plat backMsg:(NSString *)msg;
- (void) onLoginSuccess:(NSString *)plat backMsg:(NSString *)msg;
- (void) onLoginFail:(NSString *)plat backMsg:(NSString *)msg;
- (void) onLoginCancel:(NSString *)plat backMsg:(NSString *)msg;

@end

//分享回调
@protocol ShareDelegate <NSObject>

- (void) onComplete:(NSString *)plat backCode:(int) eCode backMsg:(NSString *)msg;
- (void) onError:(NSString *)plat backMsg:(NSString *)msg;
- (void) onCancel:(NSString *)plat;

@end

//goumai回调
@protocol MaiDelegate <NSObject>

- (void) onMaiSuccess:(NSString *)plat backMsg:(NSString *)msg;
- (void) onMaiFail:(NSString *)plat backMsg:(NSString *)msg;
- (void) onMaiNotify:(NSString *)plat backMsg:(NSString *)msg;
- (void) onGetMaiList:(BOOL)bOk backMsg:(NSString *)msg;

@end

//定位回调
@protocol LocationDelegate <NSObject>

- (void) onLocationResult:(BOOL)bSuccess backCode:(int)code backMsg:(NSString *)msg;

@end

#endif /* ThirdProtocol_h */
