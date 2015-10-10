//
//  MaxLeap.h
//  MaxLeap
//
//  Created by Sun Jin on 6/23/14.
//  Copyright (c) 2014 iLegendsoft. All rights reserved.
//

#import <MaxLeap/MLConstants.h>
#import <MaxLeap/MLRelation.h>
#import <MaxLeap/MLACL.h>
#import <MaxLeap/MLGeoPoint.h>
#import <MaxLeap/MLObject.h>
#import <MaxLeap/MLSubclassing.h>
#import <MaxLeap/MLObject+Subclass.h>
#import <MaxLeap/MLQuery.h>
#import <MaxLeap/MLSearchQuery.h>
#import <MaxLeap/MLInstallation.h>
#import <MaxLeap/MLUser.h>
#import <MaxLeap/MLAnonymousUtils.h>
#import <MaxLeap/MLPassport.h>
#import <MaxLeap/MLCloudCode.h>
#import <MaxLeap/MLFile.h>
#import <MaxLeap/MLPrivateFile.h>
#import <MaxLeap/MLConfig.h>
#import <MaxLeap/MLEmail.h>
#import <MaxLeap/MLReceiptManager.h>
#import <MaxLeap/MLMarketingManager.h>
#import <MaxLeap/MLLogger.h>
#import <MaxLeap/MLAnalytics.h>
#import <MaxLeap/MLACurrency.h>
#import <MaxLeap/MLGAItem.h>
#import <MaxLeap/MLGAMission.h>
#import <MaxLeap/MLGAVirtureCurrency.h>

/*!
 The `MaxLeap` class contains static functions that handle global configuration for the MaxLeap framework.
 */
@interface MaxLeap : NSObject

/**
 *  Sets the applicationId and clientKey of your application.
 *
 *  @param applicationId The application id for your MaxLeap application.
 *  @param clientKey     The client key for your MaxLeap application.
 */
+ (void)setApplicationId:(NSString *)applicationId clientKey:(NSString *)clientKey;

/*!
 The current application id that was used to configure MaxLeap framework.
 */
+ (NSString *)applicationId;

/*!
 The current client key that was used to configure MaxLeap framework.
 */
+ (NSString *)clientKey;

/**
 *  get the timeout interval for MaxLeap request
 *
 *  @return timeout interval
 */
+ (NSTimeInterval)networkTimeoutInterval;

/**
 *  set the timeout interval for MaxLeap request
 *
 *  @param timeoutInterval timeout interval
 */
+ (void)setNetworkTimeoutInterval:(NSTimeInterval)timeoutInterval;

@end

