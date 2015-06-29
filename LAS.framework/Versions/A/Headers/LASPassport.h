//
//  LASPassport.h
//  LAS
//
//  Created by Sun Jin on 7/28/14.
//  Copyright (c) 2014 iLegendsoft. All rights reserved.
//

#import "LASObject.h"
#import "LASSubclassing.h"

@class LASUser;

/*!
 A LAS Framework Passport Object that is a local representation of a passport persisted to the LAS. This class is a subclass of a LASObject, and retains the same functionality of a LASObject, but also extends it with various passport specific methods, like authentication, signing up, and validation uniqueness.<br>
 */
@interface LASPassport : LASObject <LASSubclassing>

/*! The name of the LASPassport class in the REST API. This is a required LASSubclassing method */
+ (NSString *)lasClassName;

/// The session token for the `LASPassport`. This is set by the server upon successful authentication.
@property (readonly, nonatomic, strong) NSString *sessionToken;

/** @name Accessing the Current LASPassport */

/*!
 Gets the currently logged in passport from disk and returns an instance of it.
 @return Returns a LASPassport that is the currently logged in passport. If there is none, returns nil.
 */
+ (LASPassport *)currentPassport;

/*!
 Whether the passport is an authenticated object for the device. An authenticated LASPassport is one that is obtained via a signUp or logIn method. An authenticated object is required in order to save (with altered values) or delete it.
 
 @return Returns whether the passport is authenticated.
 */
- (BOOL)isAuthenticated;

/** @name Creating a New Passport */

/*!
 Creates a new LASPassport object.
 @return Returns a new LASPassport object.
 */
+ (LASPassport *)passport;

/// The username for the LASPassport.
@property (nonatomic, strong) NSString *username;

/**
 The password for the LASPassport. This will not be filled in from the server with the password. It is only meant to be set.
 */
@property (nonatomic, strong) NSString *password;

/// The email for the LASPassport.
@property (nonatomic, strong) NSString *email;

@property (nonatomic, readonly) BOOL isNew;

/**
 The linked user of the passport in this app.
 If this value is nil, you can retrieve it by calling +[LASPassportManager getLinkedUserOfPassport:block:].
 */
@property (nonatomic, readonly) LASUser *linkedUser;

/** @name Querying for passports */

/*!
 Creates a query for LASPassport objects.
 */
+ (LASQuery *)query;

@end
