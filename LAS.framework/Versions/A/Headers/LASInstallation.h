//
//  LASInstallation.h
//  LAS
//
//  Created by Sun Jin on 7/8/14.
//  Copyright (c) 2014 iLegendsoft. All rights reserved.
//

#import "LASObject.h"
#import "LASSubclassing.h"

@class LASQuery;

/*!
 A LAS Framework Installation Object that is a local representation of an installation persisted to the LAS. This class is a subclass of a LASObject, and retains the same functionality of a LASObject, but also extends it with installation-specific fields and related immutability and validity checks.<br>
 
 A valid LASInstallation can only be instantiated via +[LASInstallation currentInstallation] because the required identifier fields are readonly. The timeZone and badge fields are also readonly properties which are automatically updated to match the device's time zone and application badge when the LASInstallation is saved, thus these fields might not reflect the latest device state if the installation has not recently been saved.<br>
 
 LASInstallation objects which have a valid deviceToken and are saved to the LAS can be used to target push notifications.<br>
 
 This class is currently for iOS only. There is no LASInstallation for LAS applications running on OS X, because they cannot receive push notifications.
 */
@interface LASInstallation : LASObject <LASSubclassing>

/** The name of the Installation class in the REST API. This is a required
 *  LASSubclassing method
 */
+ (NSString *)lasClassName;

/** @name Targeting Installations */

/*!
 Creates a query for LASInstallation objects. The resulting query can only be used for targeting a LASPush. Calling find methods on the resulting query will raise an exception.
 
 @return Return a query for LASInstallation objects.
 */
+ (LASQuery *)query;

/** @name Accessing the Current Installation */

/*!
 Gets the currently-running installation from disk and returns an instance of it. If this installation is not stored on disk, returns a LASInstallation with deviceType and installationId fields set to those of the current installation.
 
 @return Returns a LASInstallation that represents the currently-running installation.
 */
+ (instancetype)currentInstallation;

/** @name Properties */

/*!
 Sets the device token string property from an NSData-encoded token.
 @param deviceTokenData The deviceToken got from `application:didRegisterForRemoteNotificationsWithDeviceToken:` method.
 */
- (void)setDeviceTokenFromData:(NSData *)deviceTokenData;

/// The device type for the LASInstallation.
@property (nonatomic, readonly, strong) NSString *deviceType;

/// The installationId for the LASInstallation.
@property (nonatomic, readonly, strong) NSString *installationId;

/// The device token for the LASInstallation.
@property (nonatomic, strong) NSString *deviceToken;

/// The badge for the LASInstallation.
@property (nonatomic, assign) NSInteger badge;

/// The timeZone for the LASInstallation.
@property (nonatomic, readonly, strong) NSString *timeZone;

/// The channels for the LASInstallation.
@property (nonatomic, strong) NSArray *channels;

@end
