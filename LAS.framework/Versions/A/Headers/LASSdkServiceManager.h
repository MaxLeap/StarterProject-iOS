//
//  LASSdkServiceManager.h
//  LAS
//
//  Created by Sun Jin on 15/3/26.
//  Copyright (c) 2015年 ilegendsoft. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <LAS/LASSdkService.h>

@interface LASSdkServiceManager : NSObject

+ (void)registerService:(id<LASSdkService>)service;
+ (BOOL)handleOpenURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication;
+ (BOOL)handleLaunchOptions:(NSDictionary *)launchOptions;

@end
