//
//  LuaObjectCBridge.m
//  GloryProject
//
//  Created by zhong on 16/8/31.
//
//
#import "Utils.h"

//iOS中获取网卡mac信息
#include <sys/socket.h> // Per msqr
#include <sys/sysctl.h>
#include <net/if.h>
#include <net/if_dl.h>
#include <ifaddrs.h>
#include <arpa/inet.h>
#import "SSKeychain.h"
#import <CommonCrypto/CommonDigest.h>

using namespace cocos2d;

@implementation Utils

+(NSString*) getUUID
{
    /*NSString *macaddress = [[[UIDevice currentDevice] identifierForVendor] UUIDString];
    
    NSString *bundleIdentifier = [[NSBundle mainBundle] bundleIdentifier];
    NSLog(@"uuid:%@", [NSString stringWithFormat:@"%@%@",macaddress,bundleIdentifier]);
    return [NSString stringWithFormat:@"%@%@",macaddress,bundleIdentifier];*/
    NSString* bundleid = [[NSBundle mainBundle] bundleIdentifier];
    NSLog(@"%@",bundleid);
    NSString* pKey=[SSKeychain passwordForService:bundleid account:@"deviceid"];
    NSLog(@"%@",pKey);
    if(!pKey || [pKey length]<1)
    {
        CFUUIDRef puuid = CFUUIDCreate(nil);
        CFStringRef uuidString = CFUUIDCreateString( nil, puuid );
        NSString * pResultString = (NSString *)CFStringCreateCopy( NULL, uuidString);
        CFRelease(puuid);
        CFRelease(uuidString);
        [pResultString autorelease];
        
        const char* cStr = [pResultString UTF8String];
        u_char result[16];
        CC_MD5(cStr, (int)strlen(cStr), result);
        
        pKey = [NSString stringWithFormat:@"%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
                result[0], result[1], result[2], result[3],
                result[4], result[5], result[6], result[7],
                result[8], result[9], result[10],result[11],
                result[12],result[13],result[14],result[15]];
        
        //保存deviceid
        [SSKeychain setPassword:pKey forService:bundleid account:@"deviceid"];
    }
    NSLog(@"%@ ",pKey);
    return [pKey copy];
}

+(NSString*) getHostAdress
{
    //return @"192.168.1.1";
    NSString *address = @"192.168.1.1";
    struct ifaddrs *interfaces = nil;
    struct ifaddrs *temp_addr = nil;
    int success = 0;
    success = getifaddrs(&interfaces);
    if (0 == success)
    {
        temp_addr = interfaces;
        while (nil != temp_addr)
        {
            if ( AF_INET == temp_addr->ifa_addr->sa_family )
            {
                if ([[NSString stringWithUTF8String:temp_addr->ifa_name] isEqualToString:@"en0"])
                {
                    address = [NSString stringWithUTF8String:inet_ntoa(((struct sockaddr_in*)temp_addr->ifa_addr)->sin_addr)];
                }
            }
            temp_addr = temp_addr->ifa_next;
        }
    }
    freeifaddrs(interfaces);
    return address;
}
@end
