//
//  LASPush.h
//  LAS
//
//  Created by Sun Jin on 10/16/14.
//  Copyright (c) 2014 iLegendsoft. All rights reserved.
//

#import "LASConstants.h"

@class LASQuery;

/*!
 The `LASPush` class defines a push notification that can be sent from a client device.
 
 The preferred way of modifying or retrieving channel subscriptions is to use
 the <LASInstallation> class, instead of the class methods in `LASPush`.
 
 This class is currently for iOS only. LAS does not handle Push Notifications
 to LAS applications running on OS X. Push Notifications can be sent from OS X
 applications via Cloud Code or the REST API to push-enabled devices (e.g. iOS or Android).
 */
NS_EXTENSION_UNAVAILABLE("")
@interface LASPush : NSObject

///--------------------------------------
/// @name Creating a Push Notification
///--------------------------------------

+ (LASPush *)push;

///--------------------------------------
/// @name Configuring a Push Notification
///--------------------------------------

/*!
 @abstract Sets the channel on which this push notification will be sent.
 
 @param channel The channel to set for this push.
 The channel name must start with a letter and contain only letters, numbers, dashes, and underscores.
 */
- (void)setChannel:(NSString *)channel;

/*!
 @abstract Sets the array of channels on which this push notification will be sent.
 
 @param channels The array of channels to set for this push.
 Each channel name must start with a letter and contain only letters, numbers, dashes, and underscores.
 */
- (void)setChannels:(NSArray *)channels;

/*!
 @abstract Sets an installation query to which this push notification will be sent.
 
 @discussion The query should be created via <[LASInstallation query]> and should not specify a skip, limit, or order.
 
 @param query The installation query to set for this push.
 */
- (void)setQuery:(LASQuery *)query;

///--------------------------------------
/// @name Configuring iOS Notification
///--------------------------------------

/*!
 @abstract Sets an alert message for this push notification.
 
 @warning This will overwrite any data specified in setData.
 
 @param message The message to send in this push.
 */
- (void)setIOSMessage:(NSString *)message;

/*!
 @abstract Sets an arbitrary data payload for this push notification.
 
 @discussion See the guide for information about the dictionary structure.
 
 @warning This will overwrite any data specified in setMessage.
 
 @param data The data to send in this push.
 */
- (void)setIOSData:(NSDictionary *)data;

///---------------------------------------
/// @name Configuring Android Notification
///---------------------------------------

/*!
 @abstract Sets an alert message for this push notification.
 
 @warning This will overwrite any data specified in setData.
 
 @param message The message to send in this push.
 */
- (void)setAndroidMessage:(NSString *)message;

/*!
 @abstract Sets an arbitrary data payload for this push notification.
 
 @discussion See the guide for information about the dictionary structure.
 
 @warning This will overwrite any data specified in setMessage.
 
 @param data The data to send in this push.
 */
- (void)setAndroidData:(NSDictionary *)data;

@end

