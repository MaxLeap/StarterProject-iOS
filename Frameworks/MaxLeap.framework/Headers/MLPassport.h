//
//  MLPassport.h
//  MaxLeap
//
//  Created by Sun Jin on 7/28/14.
//  Copyright (c) 2014 iLegendsoft. All rights reserved.
//

#ifdef EXTENSION_IOS
    #import <MaxLeapExt/MLObject.h>
    #import <MaxLeapExt/MLSubclassing.h>
#else
    #import <MaxLeap/MLObject.h>
    #import <MaxLeap/MLSubclassing.h>
#endif

@class MLUser;

/*!
 A MaxLeap Framework Passport Object that is a local representation of a passport persisted to the MaxLeap. This class is a subclass of a MLObject, and retains the same functionality of a MLObject, but also extends it with various passport specific methods, like authentication, signing up, and validation uniqueness.<br>
 */
@interface MLPassport : MLObject <MLSubclassing>

/*! The name of the MLPassport class in the REST API. This is a required MLSubclassing method */
+ (NSString *)leapClassName;

/// The session token for the `MLPassport`. This is set by the server upon successful authentication.
@property (readonly, nonatomic, strong) NSString *sessionToken;

/** @name Accessing the Current MLPassport */

/*!
 Gets the currently logged in passport from disk and returns an instance of it.
 @return Returns a MLPassport that is the currently logged in passport. If there is none, returns nil.
 */
+ (MLPassport *)currentPassport;

/*!
 Whether the passport is an authenticated object for the device. An authenticated MLPassport is one that is obtained via a signUp or logIn method. An authenticated object is required in order to save (with altered values) or delete it.
 
 @return Returns whether the passport is authenticated.
 */
- (BOOL)isAuthenticated;

/** @name Creating a New Passport */

/*!
 Creates a new MLPassport object.
 @return Returns a new MLPassport object.
 */
+ (MLPassport *)passport;

/// The username for the MLPassport.
@property (nonatomic, strong) NSString *username;

/**
 The password for the MLPassport. This will not be filled in from the server with the password. It is only meant to be set.
 */
@property (nonatomic, strong) NSString *password;

/// The email for the MLPassport.
@property (nonatomic, strong) NSString *email;

@property (nonatomic, readonly) BOOL isNew;

/**
 The linked user of the passport in this app.
 If this value is nil, you can retrieve it by calling +[MLPassportManager getLinkedUserOfPassport:block:].
 */
@property (nonatomic, readonly) MLUser *linkedUser;

/** @name Querying for passports */

/*!
 Creates a query for MLPassport objects.
 */
+ (MLQuery *)query;

/*!
 Signs up the passport asynchronously. Make sure that password, username and email are set. This will also enforce that the username and email isn't already taken.
 
 @param block The block to execute. The block should have the following argument signature: (BOOL succeeded, NSError *error)
 */
- (void)signUpInBackgroundWithBlock:(MLBooleanResultBlock)block;

/*!
 Signs up the passport asynchronously. Make sure that password, username and email are set. The capthca also cannot be nil. This will also enforce that the username and email isn't already taken.
 
 @param captcha     The captcha
 @param block       The block to execute. The block should have the following argument signature: (BOOL succeeded, NSError *error)
 */
- (void)signUpInBackgroundWithCaptcha:(NSDictionary *)captcha block:(MLBooleanResultBlock)block;

/** @name Logging in */

/*!
 Makes an asynchronous request to log in a passport with specified credentials. Returns an instance of the successfully logged in MLPassport. This will also cache the passport locally so that calls to currentPassport will use the latest logged in passport.
 
 @param loginId The username or email of the passport.
 @param password The password of the passport.
 @param block The block to execute. The block should have the following argument signature: (MLPassport *passport, NSError *error)
 */
+ (void)loginWithLoginIdInBackground:(NSString *)loginId password:(NSString *)password block:(MLPassportResultBlock)block;

/*!
 Logs out the currently logged in passport from server. If success, the cache of the passport on disk will be removed.
 
 @param block The block to execute. The block should have the following signature: (BOOL succeeded, NSError *error)
 */
+ (void)logoutInBackgroundWithBlock:(MLBooleanResultBlock)block;

#pragma mark -
///--------------------------------------
/// @name Linking User
///--------------------------------------

/*!
 Links an authenticated user with a passport asynchronously. Make sure that the user is authenticated and the passport's passport and loginId (username or email) are set.
 
 @param user        An authenticated user.
 @param block       The block to execute. The block should have the following signature: (BOOL succeeded, NSError *error)
 */
- (void)linkUserInBackground:(MLUser *)user block:(MLBooleanResultBlock)block;

/*!
 Get linked user of the passport asynchronously. Make sure that the passport is authenticated.
 
 @param block       The block to execute. The block should have the following signature: (MLUser *user, NSError *error)
 */
- (void)getLinkedUserInBackgroundWithBlock:(MLUserResultBlock)block;

/*!
 Unlinks a user with passport asynchronously. Make sure that the user is authenticated.
 
 @param user The user to unlink.
 @param block The block to execute. The block should have the following signature: (BOOL succeeded, NSError *error)
 */
+ (void)unlinkUserInBackground:(MLUser *)user block:(MLBooleanResultBlock)block;

#pragma mark -
///--------------------------------------
/// @name Coins
///--------------------------------------

/*!
 Increase coins in current app.
 
 @param coins The number of coins to increase
 @param block The block to execute when request completed. The block should have the following signature: (BOOL succeeded, NSError *error)
 */
- (void)earnAppCoin:(NSUInteger)coins block:(MLBooleanResultBlock)block;

/*!
 Consume coins in current app.
 
 @param coins The number of coins to consume.
 @param block The block to execute when request completed. The block should have the following signature: (BOOL succeeded, NSError *error)
 */
- (void)consumeAppCoin:(NSUInteger)coins block:(MLBooleanResultBlock)block;

@end
