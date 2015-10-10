//
//  MLACL.h
//  MaxLeap
//
//  Created by Sun Jin on 6/30/14.
//  Copyright (c) 2014 iLegendsoft. All rights reserved.
//

#import <Foundation/Foundation.h>

FOUNDATION_EXPORT NSString * const MLAccessTypeOrgUser;
FOUNDATION_EXPORT NSString * const MLAccessTypeMasterKey;
FOUNDATION_EXPORT NSString * const MLAccessTypeAppUser;
FOUNDATION_EXPORT NSString * const MLAccessTypeAPIKey;

/**
 *  A MLACL is used to control which users can access or modify a particular object.
 */
@interface MLACL : NSObject <NSCopying, NSCoding>

- (NSString *)accessType;

/**
 * The id of user who have access. 
 * If accessType is OrgUser, it returns the org user id.
 * If acessType is AppUser, it returns the app user id.
 * Otherwise, it returns nil
 */
- (NSString *)userId;

/**
 * returns app user id
 */
- (NSString *)appUserId;

/**
 * returns org user id
 */
- (NSString *)orgUserId;

@end
