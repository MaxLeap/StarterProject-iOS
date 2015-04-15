//
//  LASConfig.h
//  LAS
//
//  Created by Sun Jin on 15/2/4.
//  Copyright (c) 2015年 ilegendsoft. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, LASEnvironment) {
    LASEnvironmentProd,
    LASEnvironmentDev,
    LASEnvironmentUat
};

extern NSString * const kLASSessionDebugSwitchKey;
extern NSString * const kLASAppLifeCycleLoggerSwitchKey;
extern NSString * const kLASEventBackupSwitchKey;


@class LASACL, LASUser, LASInstallation;

@interface LASSDKConfig : NSObject

+ (instancetype)sharedInstance;

@property (nonatomic, strong) dispatch_group_t gloable_group;
@property (nonatomic) int sessionContinueSeconds;
@property (nonatomic) NSInteger bgTaskId;

@property (nonatomic) LASEnvironment environment;
- (void)setEnvironmentWithString:(NSString *)environment;

@property (nonatomic) BOOL httpsDisabled;
- (NSString *)lasServerBaseUrl;

@property (nonatomic, strong) LASACL *defaultACL;

@property (nonatomic, strong) NSMutableDictionary *subclassesOfObject;
@property (nonatomic, strong) NSMutableSet *knownValidlasClassNames;
+ (void)addInternalClassName:(NSString *)lasClassName;
+ (BOOL)isInternalClass:(NSString *)lasClassName;

@property (nonatomic) NSTimeInterval networkTimeoutInterval;


#pragma mark - Private Special Debugger
+ (void)enableSessionDebug:(BOOL)yesOrNo;
+ (void)enableLifecycleLogger:(BOOL)yesOrNo;
+ (void)enableEventBackup:(BOOL)yesOrNo;

@end
