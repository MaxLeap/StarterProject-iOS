//
//  LASPassportManager.h
//  LAS
//
//  Created by Sun Jin on 7/28/14.
//  Copyright (c) 2014 iLegendsoft. All rights reserved.
//

#import "LASConstants.h"
@class LASPassport;

/*!
  The helper class of LASPassport. This class extends the behaviour of LASObject, like signing up, login, and validation uniqueness.
 */
@interface LASPassportManager : NSObject

/*!
 Signs up the passport asynchronously. Make sure that password, username and email are set. This will also enforce that the username and email isn't already taken.
 
 @param passport The new passport to create.
 @param block The block to execute. The block should have the following argument signature: (BOOL succeeded, NSError *error)
 */
+ (void)signUpInBackground:(LASPassport *)passport block:(LASBooleanResultBlock)block;

/*!
 Signs up the passport asynchronously. Make sure that password, username and email are set. The capthca also cannot be nil. This will also enforce that the username and email isn't already taken.
 
 @param passport    The new passport to create.
 @param captcha     The captcha
 @param block       The block to execute. The block should have the following argument signature: (BOOL succeeded, NSError *error)
 */
+ (void)signUpInBackground:(LASPassport *)passport withCaptcha:(NSDictionary *)captcha block:(LASBooleanResultBlock)block;

/** @name Logging in */

/*!
 Makes an asynchronous request to log in a passport with specified credentials. Returns an instance of the successfully logged in LASPassport. This will also cache the passport locally so that calls to currentPassport will use the latest logged in passport.
 
 @param loginId The username or email of the passport.
 @param password The password of the passport.
 @param block The block to execute. The block should have the following argument signature: (LASPassport *passport, NSError *error)
 */
+ (void)loginWithLoginIdInBackground:(NSString *)loginId password:(NSString *)password block:(LASPassportResultBlock)block;

/*!
 Logs out the currently logged in passport from server. If success, the cache of the passport on disk will be removed.
 
 @param block The block to execute. The block should have the following signature: (BOOL succeeded, NSError *error)
 */
+ (void)logoutInBackgroundWithBlock:(LASBooleanResultBlock)block;

/*!
 Links an authenticated user with a passport asynchronously. Make sure that the user is authenticated and the passport's passport and loginId (username or email) are set.
 
 @param user        An authenticated user.
 @param passport    The passport to link with.
 @param block       The block to execute. The block should have the following signature: (BOOL succeeded, NSError *error)
 */
+ (void)linkUser:(LASUser *)user withPassport:(LASPassport *)passport block:(LASBooleanResultBlock)block;

/*!
 Get linked user of the passport asynchronously. Make sure that the passport is authenticated.
 
 @param passport    The passport to get linked user
 @param block       The block to execute. The block should have the following signature: (LASUser *user, NSError *error)
 */
+ (void)getLinkedUserOfPassport:(LASPassport *)passport block:(LASUserResultBlock)block;

/*!
 Unlinks a user with passport asynchronously. Make sure that the user is authenticated.
 
 @param user The user to unlink.
 @param block The block to execute. The block should have the following signature: (BOOL succeeded, NSError *error)
 */
+ (void)unlinkUser:(LASUser *)user block:(LASBooleanResultBlock)block;

/*!
 Increase coins in current app.
 
 @param coins The number of coins to increase
 @param block The block to execute when request completed. The block should have the following signature: (BOOL succeeded, NSError *error)
 */
+ (void)earnAppCoin:(NSUInteger)coins block:(LASBooleanResultBlock)block;

/*!
 Consume coins in current app.
 
 @param coins The number of coins to consume.
 @param block The block to execute when request completed. The block should have the following signature: (BOOL succeeded, NSError *error)
 */
+ (void)consumeAppCoin:(NSUInteger)coins block:(LASBooleanResultBlock)block;

@end
