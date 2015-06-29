//
//  LASUserManager.h
//  LAS
//
//  Created by Sun Jin on 7/8/14.
//  Copyright (c) 2014 iLegendsoft. All rights reserved.
//

#import "LASConstants.h"

/*!
 The helper class of LASUser. This class extends the behaviour of LASObject, like signing up, login, and validation uniqueness.
 */
@interface LASUserManager : NSObject

/*!
 Enables automatic creation of anonymous users.  After calling this method, [LASUser currentUser] will always have a value. The user will only be created on the server once the user has been saved, or once an object with a relation to that user or an ACL that refers to the user has been saved.<br>
 
 Note: saveEventually will not work if an item being saved has a relation to an automatic user that has never been saved.
 */
+ (void)enableAutomaticUser;

/*!
 Signs up the user asynchronously. Make sure that password and username are set. This will also enforce that the username isn't already taken.
 
 @param newUser The new user to create.
 @param block The block to execute. The block should have the following argument signature: (BOOL succeeded, NSError *error)
 */
+ (void)signUpInBackground:(LASUser *)newUser block:(LASBooleanResultBlock)block;

/** @name Logging in */

/*!
 Makes an asynchronous request to log in a user with specified credentials. Returns an instance of the successfully logged in LASUser. This will also cache the user locally so that calls to currentUser will use the latest logged in user.
 
 @param username The username of the user.
 @param password The password of the user.
 @param block The block to execute. The block should have the following argument signature: (LASUser *user, NSError *error)
 */
+ (void)logInWithUsernameInBackground:(NSString *)username
                             password:(NSString *)password
                                block:(LASUserResultBlock)block;

/** @name Becoming a user */
/*!
 Makes an asynchronous request to become a user with the given session token. Returns an instance of the successfully logged in LASUser. This also caches the user locally so that calls to currentUser will use the latest logged in user. The selector for the callback should look like: myCallback:(LASUser *)user error:(NSError **)error
 
 @param sessionToken The session token for the user.
 @param block The block to execute. The block should have the following argument signature: (LASUser *user, NSError *error)
 */
+ (void)becomeInBackgroundWithSessionToken:(NSString *)sessionToken block:(LASUserResultBlock)block;

/** @name Logging Out */

/*!
 Logs out the currently logged in user on disk.
 */
+ (void)logOut;

/** @name change password  */

/**
 *  Verify the current password and then change password with the new password.
 *
 *  @param newPassword a new password
 *  @param oldPassword the current password
 *  @param block       The block to execute. The block should have the following argument signature: (BOOL success, NSError *error)
 */
+ (void)changePasswordWithNewPassword:(NSString *)newPassword oldPassword:(NSString *)oldPassword block:(LASBooleanResultBlock)block;

/** @name Requesting a Password Reset */

/*!
 Send a password reset request asynchronously for a specified email. If a user account exists with that email, an email will be sent to that address with instructions on how to reset their password.
 
 @param email Email of the account to send a reset password request.
 @param block The block to execute. The block should have the following argument signature: (BOOL succeeded, NSError *error)
 */
+ (void)requestPasswordResetForEmailInBackground:(NSString *)email
                                           block:(LASBooleanResultBlock)block;

/** @name Requesting a Email Verify */

/*!
 Send a email verify request asynchronously for a specified email. If a user account exists with that email, an email will be sent to that address with instructions on how to verify their email.
 
 @param email Email of the account to verify.
 @param block The block to execute. The block should have the following argument signature: (BOOL succeeded, NSError *error)
 */
+ (void)requestEmailVerifyForEmailInBackground:(NSString *)email
                                         block:(LASBooleanResultBlock)block;

/**
 *  Check if the password matches current user.
 *
 *  @param password a password
 *  @param block    The block to execute. The block should have the following argument signature: (BOOL isMatch, NSError *error)
 */
+ (void)checkPassword:(NSString *)password block:(LASBooleanResultBlock)block;

/**
 *  Check the username is exist or not.
 *
 *  @discussion Empty username is not exist becuause it's not valid.
 *
 *  @param username The username to check
 *  @param block    The block to execute. The block should have the following argument signature: (BOOL isExist, NSError *error)
 */
+ (void)checkUsernameExists:(NSString *)username block:(LASBooleanResultBlock)block;

#pragma mark Getting Users

/*! @name Getting User Objects */

/*!
 Returns a LASUser with a given class and id and sets an error if necessary.
 
 @param userId The objectId of a user that is being requested.
 @param block The block to execute. The block should have the following argument signature: (LASUser *user, NSError *error)
 */
+ (void)getUserObjectWithId:(NSString *)userId block:(LASUserResultBlock)block;

@end



