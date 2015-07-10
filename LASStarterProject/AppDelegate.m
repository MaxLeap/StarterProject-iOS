//
//  AppDelegate.m
//  LASStarterProject
//
//  Created by Sun Jin on 11/19/14.
//  Copyright (c) 2014 LAS. All rights reserved.
//

#import "AppDelegate.h"
#import <LAS/LAS.h>

// If you are using Facebook, uncomment this line
//#import <LASFacebookUtils/LASFacebookUtils.h>

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // ****************************************************************************
    // Uncomment and fill in with your LAS credentials:
    // [LAS setApplicationId:@"your_application_id" clientKey:@"yout_client_key"];
    // ****************************************************************************
    
    // ****************************************************************************
    // If you want deliver in-app messages to your users, uncomment this line.
    // [LASMarketingManager enable];
    // Uncomment this line to test your in-app message;
    // [LASMarketingManager enableTestMode];
    // ****************************************************************************
    
    // ****************************************************************************
    // If you are using Facebook, uncomment and add your FacebookAppID to your bundle's plist as
    // described here: https://developers.facebook.com/docs/getting-started/facebook-sdk-for-ios/
    // [LASFacebookUtils initializeFacebook];
    // ****************************************************************************
    
    [LASUserManager enableAutomaticUser];
    
    LASACL *defaultACL = [LASACL ACL];
    
    // If you would like all objects to be private by default, remove this line.
    [defaultACL setPublicReadAccess:YES];
    
    [LASACL setDefaultACL:defaultACL withAccessForCurrentUser:YES];
    
    // Override point for customization after application launch.
    
//#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 80000
//    if ([application respondsToSelector:@selector(registerUserNotificationSettings:)]) {
//        UIUserNotificationType userNotificationTypes = (UIUserNotificationTypeAlert |
//                                                        UIUserNotificationTypeBadge |
//                                                        UIUserNotificationTypeSound);
//        UIUserNotificationSettings *settings = [UIUserNotificationSettings settingsForTypes:userNotificationTypes
//                                                                                 categories:nil];
//        [LASPushManager enablePushWithSettings:settings];
//    } else
//#endif
//    {
//        [LASPushManager enablePushTypes:(UIRemoteNotificationTypeBadge |
//                                         UIRemoteNotificationTypeAlert |
//                                         UIRemoteNotificationTypeSound)];
//    }
    
    return YES;
}

/*
 
 ///////////////////////////////////////////////////////////
 // Uncomment this method if you are using Facebook
 ///////////////////////////////////////////////////////////
 
 - (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
     return [FBAppCall handleOpenURL:url sourceApplication:sourceApplication withSession:[LASFacebookUtils session]];
 }
 
 */

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo {
    NSLog(@"application did receive remote notification: %@", userInfo);
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
    
//    [FBAppCall handleDidBecomeActiveWithSession:[LASFacebookUtils session]];
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
    
//    [[LASFacebookUtils session] close];
}

@end
