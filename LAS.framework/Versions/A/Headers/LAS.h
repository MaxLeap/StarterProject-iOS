//
//  LASCloud.h
//  LAS
//
//  Created by Sun Jin on 6/23/14.
//  Copyright (c) 2014 iLegendsoft. All rights reserved.
//

#import <LAS/LASConstants.h>
#import <LAS/LASRelation.h>
#import <LAS/LASACL.h>
#import <LAS/LASGeoPoint.h>
#import <LAS/LASObject.h>
#import <LAS/LASSubclassing.h>
#import <LAS/LASObject+Subclass.h>
#import <LAS/LASDataManager.h>
#import <LAS/LASQuery.h>
#import <LAS/LASSearchQuery.h>
#import <LAS/LASQueryManager.h>
#import <LAS/LASPush.h>
#import <LAS/LASPushManager.h>
#import <LAS/LASInstallation.h>
#import <LAS/LASRole.h>
#import <LAS/LASUser.h>
#import <LAS/LASUserManager.h>
#import <LAS/LASAnonymousUtils.h>
#import <LAS/LAS_Twitter.h>
#import <LAS/LASTwitterUtils.h>
#import <LAS/LASPassport.h>
#import <LAS/LASPassportManager.h>
#import <LAS/LASAnalytics.h>
#import <LAS/LASCloudParam.h>
#import <LAS/LASCloudCode.h>
#import <LAS/LASFile.h>
#import <LAS/LASFileManager.h>
#import <LAS/LASPrivateFile.h>
#import <LAS/LASPrivateFileManager.h>
#import <LAS/LASConfig.h>
#import <LAS/LASConfigManager.h>
#import <LAS/LASSdkService.h>
#import <LAS/LASSdkServiceManager.h>
#import <LAS/LASEmail.h>
#import <LAS/LASEmailManager.h>
#import <LAS/LASReceiptManager.h>
#import <LAS/LASMarketingManager.h>

/*!
 The `LAS` class contains static functions that handle global configuration for the LAS framework.
 */
@interface LAS : NSObject

/**
 *  Sets the applicationId and clientKey of your application.
 *
 *  @param applicationId The application id for your LAS application.
 *  @param clientKey     The client key for your LAS application.
 */
+ (void)setApplicationId:(NSString *)applicationId clientKey:(NSString *)clientKey;

/*!
 The current application id that was used to configure LAS framework.
 */
+ (NSString *)applicationId;

/*!
 The current client key that was used to configure LAS framework.
 */
+ (NSString *)clientKey;

/**
 *  get the timeout interval for LAS request
 *
 *  @return timeout interval
 */
+ (NSTimeInterval)networkTimeoutInterval;

/**
 *  set the timeout interval for LAS request
 *
 *  @param timeoutInterval timeout interval
 */
+ (void)setNetworkTimeoutInterval:(NSTimeInterval)timeoutInterval;

@end
