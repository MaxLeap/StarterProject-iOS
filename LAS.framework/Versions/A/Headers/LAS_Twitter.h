//
//  LAS_Twitter.h
//  LAS
//
//  Created by Sun Jin on 7/16/14.
//  Copyright (c) 2014 iLegendsoft. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Social/Social.h>
#import <Accounts/Accounts.h>

/*!
 A simple interface for interacting with the Twitter REST API, automating sign-in and OAuth signing of requests against the API.
 */
@interface LAS_Twitter : NSObject

@property (nonatomic, copy) NSString *consumerKey;
@property (nonatomic, copy) NSString *consumerSecret;
@property (nonatomic, copy) NSString *authToken;
@property (nonatomic, copy) NSString *authTokenSecret;
@property (nonatomic, copy) NSString *userId;
@property (nonatomic, copy) NSString *screenName;

/*!
 Displays an auth dialog and populates the authToken, authTokenSecret, userId, and screenName properties if the Twitter user grants permission to the application.
 
 @param success     Invoked upon successful authorization.
 @param failure     Invoked upon an error occurring in the authorization process.
 @param cancelBlock Invoked when the user cancels authorization.
 */
- (void)authorizeWithSuccess:(void (^)(void))success failure:(void (^)(NSError *error))failure cancel:(void (^)(void))cancelBlock;

/**
 *  Adds a 3-legged OAuth signature to an NSMutableURLRequest based upon the properties set for the Twitter object.  Use this function to sign requests being made to the Twitter API.
 *
 *  @param request The request to be sign.
 */
- (void)signRequest:(NSMutableURLRequest *)request;

@end
