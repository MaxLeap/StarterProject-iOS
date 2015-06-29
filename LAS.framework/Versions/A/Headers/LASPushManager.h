//
//  LASPushManager.h
//  LAS
//
//  Created by Sun Jin on 14/12/18.
//  Copyright (c) 2014年 iLegendsoft. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <LAS/LASConstants.h>

@class LASPush, LASQuery;

/*!
 */
NS_EXTENSION_UNAVAILABLE("")
@interface LASPushManager : NSObject

/*!
 Register to receive push notifications of the specified types via Apple Push Service.
 LAS SDK handles `application:didRegisterForRemoteNotificationsWithDeviceToken:` and saves the device token.
 
 @param types A bit mask specifying the types of notifications the app accepts. For a list of values, see `UIRemoteNotificationType`.
 */
+ (void)enablePushTypes:(UIRemoteNotificationType)types NS_DEPRECATED_IOS(3_0, 8_0, "Please use enablePushWithSettings: instead");

/*!
 Register to receive push notifications of the specified types via Apple Push Service and registers your preferred options for notifying the user at the same time.
 LAS SDK handles `application:didRegisterForRemoteNotificationsWithDeviceToken:` and saves the device token.
 
 @param notificationSettings The types of notifications that your app wants to use. You also use this object to specify custom actions that can be initiated by the user from an alert displayed in response to a local or remote notification.
 */
+ (void)enablePushWithSettings:(UIUserNotificationSettings *)notificationSettings NS_AVAILABLE_IOS(8_0);

///--------------------------------------
/// @name Sending Push Notifications
///--------------------------------------

/*!
 @abstract *Asynchronously* sends a push message to a channel and calls the given block.
 
 @param message The message to send.
 @param channel The channel to send to. The channel name must start with
 a letter and contain only letters, numbers, dashes, and underscores.
 @param block The block to execute.
 It should have the following argument signature: `^(BOOL succeeded, NSError *error)`
 */
+ (void)sendPushMessageInBackground:(NSString *)message
                          toChannel:(NSString *)channel
                              block:(LASBooleanResultBlock)block;

/*!
 @abstract *Asynchronously* sends a push message to a query and calls the given block.
 
 @param message The message to send.
 @param query The query to send to. The query must be a LASInstallation query
 created with [LASInstallation query].
 @param block The block to execute.
 It should have the following argument signature: `^(BOOL succeeded, NSError *error)`
 */
+ (void)sendPushMessageInBackground:(NSString *)message
                            toQuery:(LASQuery *)query
                              block:(LASBooleanResultBlock)block;

/*!
 @abstract *Asynchronously* send this push message and executes the given callback block.
 
 @param push The `LASPush` object with push message to send.
 @param block The block to execute.
 It should have the following argument signature: `^(BOOL succeeded, NSError *error)`.
 */
+ (void)sendPushInBackground:(LASPush *)push block:(LASBooleanResultBlock)block;

///--------------------------------------
/// @name Handling Notifications
///--------------------------------------

/*!
 @abstract A default handler for push notifications while the app is active that
 could be used to mimic the behavior of iOS push notifications while the app is backgrounded or not running.
 
 @discussion Call this from `application:didFinishLaunchingWithOptions:` and `application:didReceiveRemoteNotification:`.
 
 @param userInfo The dictionary from either `didFinishLaunchingWithOptions:` or `appplication:didReceiveRemoteNotification:`.
 */
+ (void)handlePush:(NSDictionary *)userInfo;

///--------------------------------------
/// @name Managing Channel Subscriptions
///--------------------------------------

/*!
 @abstract *Asynchronously* get all the channels that this device is subscribed to.
 @param block The block to execute.
 It should have the following argument signature: `^(NSSet *channels, NSError *error)`.
 */
+ (void)getSubscribedChannelsInBackgroundWithBlock:(LASSetResultBlock)block;

/*!
 @abstract *Asynchronously* subscribes the device to a channel of push notifications and calls the given block.
 
 @param channel The channel to subscribe to. The channel name must start with
 a letter and contain only letters, numbers, dashes, and underscores.
 @param block The block to execute.
 It should have the following argument signature: `^(BOOL succeeded, NSError *error)`
 */
+ (void)subscribeToChannelInBackground:(NSString *)channel
                                 block:(LASBooleanResultBlock)block;

/*!
 @abstract *Asynchronously* unsubscribes the device from a channel of push notifications and calls the given block.
 
 @param channel The channel to unsubscribe from.
 @param block The block to execute.
 It should have the following argument signature: `^(BOOL succeeded, NSError *error)`.
 */
+ (void)unsubscribeFromChannelInBackground:(NSString *)channel
                                     block:(LASBooleanResultBlock)block;

@end



extern NSString * const LASDeviceTokenDidUpdateNotification NS_EXTENSION_UNAVAILABLE("");

