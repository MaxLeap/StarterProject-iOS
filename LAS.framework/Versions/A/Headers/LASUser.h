//
//  LASUser.h
//  LAS
//
//  Created by Sun Jin on 6/23/14.
//  Copyright (c) 2014 iLegendsoft. All rights reserved.
//

#import "LASObject.h"
#import "LASConstants.h"
#import "LASSubclassing.h"

@class LASQuery;

/*!
 A LAS Framework User Object that is a local representation of a user persisted to the LAS. This class is a subclass of a LASObject, and retains the same functionality of a LASObject. You can also user LASDataManager's api to update a user.<br>
 */
@interface LASUser : LASObject <LASSubclassing>

/*! The name of the LASUser class in the REST API. This is a required
 *  LASSubclassing method 
 */
+ (NSString *)lasClassName;

/// The session token for the LASUser. This is set by the server upon successful authentication.
@property (nonatomic, strong) NSString *sessionToken;

/// Whether the LASUser was just created from a request. This is only set after a Facebook or Twitter login.
@property (readonly, nonatomic) BOOL isNew;

/** @name Accessing the Current User */

/*!
 Gets the currently logged in user from disk and returns an instance of it.
 @return Returns a LASUser that is the currently logged in user. If there is none, returns nil.
 */
+ (LASUser *)currentUser;

/*!
 Whether the user is an authenticated object for the device. An authenticated LASUser is one that is obtained via a signUp or logIn method. An authenticated object is required in order to save (with altered values) or delete it.
 
 @return Returns whether the user is authenticated.
 */
- (BOOL)isAuthenticated;

/** @name Creating a New User */

/*!
 Creates a new LASUser object.
 @return Returns a new LASUser object.
 */
+ (LASUser *)user;

/**
 *  The username for the LASUser.
 */
@property (nonatomic, strong) NSString *username;

/**
 The password for the LASUser. This will not be filled in from the server with the password. It is only meant to be set.
 */
@property (nonatomic, strong) NSString *password;

/**
 *  The email for the LASUser.
 */
@property (nonatomic, strong) NSString *email;

/**
 *  Whether the email is veriified.
 */
@property (nonatomic, readonly) BOOL emailVerified;

/**
 *  The linked passport's objectId
 */
@property (nonatomic, strong, readonly) NSString *passportId;

/** @name Querying for Users */

/**
 *  Creates a query for LASUser objects.
 *
 *  @return a query for LASUser objects.
 */
+ (LASQuery *)query;

@end
