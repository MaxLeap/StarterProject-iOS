//
//  MLGAMission.h
//  MaxLeap
//
//  Created by Sun Jin on 6/24/15.
//  Copyright (c) 2015 leap. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MLGAMission : NSObject

/**
 * Tracks the occurrence of beginning a specified mission.
 *
 * @param missionId The customize mission id.
 * @param type      The mission type
 */
+ (void)onBegin:(NSString *)missionId type:(NSString *)type;

/**
 * Pause the mission tracking.
 *
 * @param missionId The mission id
 */
+ (void)onPause:(NSString *)missionId;

/**
 * Pause all the mission trackings.
 */
+ (void)pauseAll;

/**
 * Resume the tracking of the mission with id `missionId`.
 *
 * @param missionId The customize mission id.
 */
+ (void)onResume:(NSString *)missionId;

/**
 * Resume all the mission trackings.
 */
+ (void)resumeAll;

/**
 * Tracks the occurrence of completion a specified mission.
 *
 * @param missionId The customize mission id.
 */
+ (void)onCompleted:(NSString *)missionId;

/**
 * Tracks the occurrence of failure a specified mission.
 *
 * @param missionId The customize mission id.
 * @param cause     Reason of the mission failure
 */
+ (void)onFailed:(NSString *)missionId failedCause:(NSString *)cause;

@end
