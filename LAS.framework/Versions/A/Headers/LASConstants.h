// LASConstants.h
// Copyright (c) 2014 iLegendsoft. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class LASObject, LASUser, LASPassport, LASFile, LASPrivateFile, LASConfig;

// Version
#define LAS_VERSION @"1.5.0"

extern NSString *const kLASDeviceType;


// Errors
extern NSString *const LASErrorDomain;

extern NSString *const LASErrorCodeKey;
extern NSString *const LASErrorMessageKey;

typedef NS_ENUM(NSInteger, LASErrorCode) {
    
    /*! @abstract 1: Internal server error. No information available. */
    kLASErrorInternalServer = 1,
    
    /*! @abstract 100: The connection to the LAS servers failed. */
    kLASErrorConnectionFailed = 100,
    
    /*! @abstract 101: Object doesn't exist, or has an incorrect password. */
    kLASErrorObjectNotFound = 101,
    
    /*! @abstract 102: You tried to find values matching a datatype that doesn't support exact database matching, like an array or a dictionary. */
    kLASErrorInvalidQuery = 102,
    
    /*! @abstract 103: Missing or invalid classname. Classnames are case-sensitive. They must start with a letter, and a-zA-Z0-9_ are the only valid characters. */
    kLASErrorInvalidClassName = 103,
    
    /*! @abstract 104: Missing ObjectId, usually the objectId no introduction in the query time, or objectId is illegal. ObjectId string can only letters, numbers. */
    kLASErrorMissingObjectId = 104,
    
    /*! @abstract 105: Key is reserved. objectId, createdAt, updatedAt.<br> Invalid key name. Keys are case-sensitive. They must start with a letter, and a-zA-Z0-9_ are the only valid characters. */
    kLASErrorInvalidKeyName = 105,
    
    /*! @abstract 106: Invalid format. Date, Pointer, Relation…. */
    kLASErrorInvalidType = 106,
    
    /*! @abstract 107: Malformed json object. A json dictionary is expected. */
    kLASErrorInvalidJSON = 107,
    
    /*! @abstract 108: Tried to access a feature only available internally. */
    kLASErrorCommandUnavailable = 108,
    
    /** @abstract 109: LAS.initialize must be called before using the library. */
    kLASErrorCommandNotInitialized = 109,
    
    /** @abstract 110: Update syntax error. */
    kLASErrorInvalidUpdate = 110,
    
    /*! @abstract 111: Field set to incorrect type. */
    kLASErrorIncorrectType = 111,
    
    /*! @abstract 112: Invalid channel name. A channel name is either an empty string (the broadcast channel) or contains only a-zA-Z0-9_ characters and starts with a letter. */
    kLASErrorInvalidChannelName = 112,
    
    /** @abstract 113: BindTo class not found. */
    kLASErrorBindToClassNotFound = 113,
    
    /*! @abstract 115: Push is misconfigured. See details to find out how. */
    kLASErrorPushMisconfigured = 115,
    
    /*! @abstract 116: The object is too large. */
    kLASErrorObjectTooLarge = 116,
    
    /** @abstract 117: The parameters is invalid. */
    kLASErrorInvalidParameter = 117,
    
    /** @abstract 118: ObjectId is invalid. */
    kLASErrorInvalidObjectId = 118,
    
    /*! @abstract 119: That operation isn't allowed for clients. */
    kLASErrorOperationForbidden = 119,
    
    /*! @abstract 120: The results were not found in the cache. */
    kLASErrorCacheMiss = 120,
    
    /*! @abstract 121: An invalid key was used in a nested JSONObject. Keys in NSDictionary values may not include '$' or '.'. */
    kLASErrorInvalidNestedKey = 121,
    
    /*! @abstract 122: Invalid file name. A file name contains only a-zA-Z0-9_. characters and is between 1 and 36 characters. */
    kLASErrorInvalidFileName = 122,
    
    /*! @abstract 123: Invalid ACL. An ACL with an invalid format was saved. This should not happen if you use LASACL. */
    kLASErrorInvalidACL = 123,
    
    /*! @abstract 124: The request timed out on the server. Typically this indicates the request is too expensive. */
    kLASErrorTimeout = 124,
    
    /*! @abstract 125: The email address was invalid. */
    kLASErrorInvalidEmailAddress = 125,
    
    /** @abstract 136: Role name cannot be changed. */
    kLASErrorRoleNotChangeName = 136,
    
    /*! @abstract 137: A unique field was given a value that is already taken. */
    kLASErrorDuplicateValue = 137,
    
    /*! @abstract 139: Role's name is invalid. */
    kLASErrorInvalidRoleName = 139,
    
    /*! @abstract 140: Exceeded an application quota. Upgrade to resolve. */
    kLASErrorExceededQuota = 140,
    
    /*! @abstract 141: Cloud Code script had an error. */
    kLASScriptError = 141,
    
    /** @abstract 142: Role is not found. */
    kLASErrorRoleNotFound = 142,
    
    /** @abstract 143: The cloud code is not deployed. */
    kLASErrorCloudCodeNotDeployed = 143,
    
    /** @abstract 160: Session token is invalid. */
    kLASErrorInvalidToken = 160,
    
    /*! @abstract 200: Username is missing or empty */
    kLASErrorUsernameMissing = 200,
    
    /*! @abstract 201: Password is missing or empty */
    kLASErrorUserPasswordMissing = 201,
    
    /*! @abstract 202: Username has already been taken */
    kLASErrorUsernameTaken = 202,
    
    /*! @abstract 203: Email has already been taken */
    kLASErrorUserEmailTaken = 203,
    
    /*! @abstract 204: The email is missing, and must be specified */
    kLASErrorUserEmailMissing = 204,
    
    /*! @abstract 205: A user with the specified email was not found */
    kLASErrorUserWithEmailNotFound = 205,
    
    /*! @abstract 206: The user cannot be altered by a client without the session. */
    kLASErrorUserCannotBeAlteredWithoutSession = 206,
    
    /*! @abstract 207: Users can only be created through sign up */
    kLASErrorUserCanOnlyBeCreatedThroughSignUp = 207,
    
    /*! @abstract 208: An existing account already linked to another user. */
    kLASErrorAccountAlreadyLinked = 208,
    
    /** @abstract 210: Password does not match. */
    kLASErrorPasswordMisMatch = 210,
    
    /** @abstract 211: User not found. */
    kLASErrorUserNotFound = 211,
    
    /*! @abstract 250: User cannot be linked to an account because that account’s ID is not found. */
    kLASErrorLinkedIdMissing = 250,
    
    /*! @abstract 251: A user with a linked (e.g. Facebook) account has an invalid session. */
    kLASErrorInvalidLinkedSession = 251,
    
    /** @abstract 252: No supported account linking service found. */
    kLASErrorUnsupportedSevice = 252,
    
    /** @abstract 253: The authData must be Hash type, not null. */
    kLASErrorInvalidAuthData = 253,
    
    /** @abstract 301: CAPTCHA input is invalid. */
    kLASErrorInvalidCaptcha = 301,
    
    /** @abstract 401: Unauthorized access, no App ID, or App ID and App key verification failed. */
    kLASErrorUnauthorized = 401,
    
    /** @abstract 503: Rate limit exceeded. */
    kLASErrorRateLimit = 503,
    
    /* @abstract 600: The path has already been taken. */
    kLASErrorPathTaken = 600,
    
    /* @abstract 601: The path does not exists. */
    kLASErrorPathNotExist = 601,
    
    /* @abstract 602: Unexpected error. No infomation available. */
    kLASErrorUnexpected = 602,
    
    /** @abstract 90000: Unkown error */
    kLASErrorUnkown = 90000
};


typedef void (^LASBooleanResultBlock)(BOOL succeeded, NSError *error);
typedef void (^LASIntegerResultBlock)(int number, NSError *error);
typedef void (^LASArrayResultBlock)(NSArray *objects, NSError *error);
typedef void (^LASDictionaryResultBlock)(NSDictionary *result, NSError *error);
typedef void (^LASObjectResultBlock)(LASObject *object, NSError *error);
typedef void (^LASSetResultBlock)(NSSet *channels, NSError *error);
typedef void (^LASUserResultBlock)(LASUser *user, NSError *error);
typedef void (^LASPassportResultBlock)(LASPassport *passport, NSError *error);
typedef void (^LASDataResultBlock)(NSData *data, NSError *error);
typedef void (^LASDataStreamResultBlock)(NSInputStream *stream, NSError *error);
typedef void (^LASStringResultBlock)(NSString *string, NSError *error);
typedef void (^LASIdResultBlock)(id object, NSError *error);
typedef void (^LASProgressBlock)(int percentDone);
typedef void (^LASFileResultBlock)(LASFile *file, NSError *error);
typedef void (^LASPrivateFileResultBlock)(LASPrivateFile *file, NSError *error);
typedef void (^LASConfigResultBlock)(LASConfig *config, NSError *error);
typedef void (^LASUsageResultBlock)(NSInteger fileCount, long usedCapacity, NSError *error);


#ifndef NS_EXTENSION_UNAVAILABLE
#define NS_EXTENSION_UNAVAILABLE(msg)
#endif /* NS_EXTENSION_UNAVAILABLE */

