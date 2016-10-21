//
//  AppDelegate.m
//  MaxLeapStarterProject
//
//  Created by Sun Jin on 11/19/14.
//  Copyright (c) 2014 MaxLeap. All rights reserved.
//

#import "AppDelegate.h"
#import <MaxLeap/MaxLeap.h>

// If you are using Facebook, uncomment this line
//#import <MLFacebookUtilsV4/MLFacebookUtils.h>

@interface AppDelegate ()

@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // ****************************************************************************
#error Uncomment and fill in with your MaxLeap credentials:
    // [MaxLeap setApplicationId:@"your_application_id" clientKey:@"yout_client_key" site:MLSiteUS];
    //
    // ****************************************************************************
    // If you are using Facebook, uncomment and add your FacebookAppID to your bundle's plist as
    // described here: https://developers.facebook.com/docs/getting-started/facebook-sdk-for-ios/
    // [MLFacebookUtils initializeFacebookWithApplicationLaunchOptions:launchOptions];
    // ****************************************************************************
    
    // ****************************************************************************
    // enable marketing to receive
    // [MLMarketingManager enable];
    //
    // Register Remote Notifications
    // [self registerRemoteNotifications];
    //
    // Record performance data for push notifications
    //
    // NSDictionary *aps = launchOptions[UIApplicationLaunchOptionsRemoteNotificationKey];
    // if (aps) {
    //     NSLog(@"app was opened by remote notification: %@", aps);
    //     if (NO == [self respondsToSelector:@selector(application:didReceiveRemoteNotification:fetchCompletionHandler:)]) {
    //         [MLMarketingManager handlePushNotificationOpened:aps];
    //     }
    // }
    // ****************************************************************************
    
    // Override point for customization after application launch.
    
    // ****************************************************************************
    // test the connection
    // MLObject *obj = [MLObject objectWithoutDataWithClassName:@"Test" objectId:@"561c83c0226"];
    // [obj fetchIfNeededInBackgroundWithBlock:^(MLObject * _Nullable object, NSError * _Nullable error) {
    //     if (error.code == kMLErrorInvalidObjectId) {
    //         NSLog(@"已经能够正确连接上您的云端应用");
    //     } else {
    //         NSLog(@"应用访问凭证不正确，请检查。");
    //     }
    // }];
    // ****************************************************************************
    
    return YES;
}

/*
 
 ///////////////////////////////////////////////////////////
 // Uncomment these methods if you are using remote notification
 ///////////////////////////////////////////////////////////
 
- (void)registerRemoteNotifications {
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 80000
    if ([[UIApplication sharedApplication] respondsToSelector:@selector(registerUserNotificationSettings:)]) {
        UIUserNotificationType userNotificationTypes = (UIUserNotificationTypeAlert |
                                                        UIUserNotificationTypeBadge |
                                                        UIUserNotificationTypeSound);
        UIUserNotificationSettings *settings = [UIUserNotificationSettings settingsForTypes:userNotificationTypes
                                                                                 categories:nil];
        [[UIApplication sharedApplication] registerUserNotificationSettings:settings];
    } else
#endif
    {
        [[UIApplication sharedApplication] registerForRemoteNotificationTypes:(UIRemoteNotificationTypeBadge |
                                                                               UIRemoteNotificationTypeAlert |
                                                                               UIRemoteNotificationTypeSound)];
    }
}

- (void)application:(UIApplication *)application didRegisterUserNotificationSettings:(UIUserNotificationSettings *)notificationSettings {
    [application registerForRemoteNotifications];
}

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
    // Save deviceToken on MaxLeap servers.
    [[MLInstallation currentInstallation] setDeviceTokenFromData:deviceToken];
    [[MLInstallation currentInstallation] saveInBackgroundWithBlock:nil];
}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo {
    // handle the remote notification
    // Record performance data for push notifications
    [MLMarketingManager handlePushNotificationOpened:userInfo];
}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler {
    // handle the remote notification
    // Record performance data for push notifications
    [MLMarketingManager handlePushNotificationOpened:userInfo];
    completionHandler(UIBackgroundFetchResultNewData);
}
 */

/*
 
 ///////////////////////////////////////////////////////////
 // Uncomment this method if you are using Facebook
 ///////////////////////////////////////////////////////////
 
 - (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
     return [[FBSDKApplicationDelegate sharedInstance] application:application openURL:url sourceApplication:sourceApplication annotation:annotation];
 }
 
 */

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
    
    /*
     ///////////////////////////////////////////////////////////
     // Uncomment this method if you are using Facebook
     ///////////////////////////////////////////////////////////
    
    [FBSDKAppEvents activateApp];
     
     */
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
