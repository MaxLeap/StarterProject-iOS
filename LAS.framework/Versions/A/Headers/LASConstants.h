// LASConstants.h
// Copyright (c) 2014 iLegendsoft. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class LASObject, LASUser, LASPassport, LASFile, LASConfig;

// Version
#define LAS_VERSION @"1.3.0"

extern NSString *const kLASDeviceType;


// Errors
extern NSString *const LASErrorDomain;

extern NSString *const LASErrorCodeKey;
extern NSString *const LASErrorMessageKey;

/*! @abstract 1: Internal server error. No information available. */
extern NSInteger const kLASErrorInternalServer;

/*! @abstract 100: The connection to the LAS servers failed. */
extern NSInteger const kLASErrorConnectionFailed;

/*! @abstract 101: Object doesn't exist, or has an incorrect password. */
extern NSInteger const kLASErrorObjectNotFound;

/*! @abstract 102: You tried to find values matching a datatype that doesn't support exact database matching, like an array or a dictionary. */
extern NSInteger const kLASErrorInvalidQuery;

/*! @abstract 103: Missing or invalid classname. Classnames are case-sensitive. They must start with a letter, and a-zA-Z0-9_ are the only valid characters. */
extern NSInteger const kLASErrorInvalidClassName;

/*! @abstract 104: Missing ObjectId, usually the objectId no introduction in the query time, or objectId is illegal. ObjectId string can only letters, numbers. */
extern NSInteger const kLASErrorMissingObjectId;

/*! @abstract 105: Key is reserved. objectId, createdAt, updatedAt.<br> Invalid key name. Keys are case-sensitive. They must start with a letter, and a-zA-Z0-9_ are the only valid characters. */
extern NSInteger const kLASErrorInvalidKeyName;

/*! @abstract 106: Invalid format. Date, Pointer, Relation…. */
extern NSInteger const kLASErrorInvalidType;

/*! @abstract 107: Malformed json object. A json dictionary is expected. */
extern NSInteger const kLASErrorInvalidJSON;

/*! @abstract 108: Tried to access a feature only available internally. */
extern NSInteger const kLASErrorCommandUnavailable;

/** @abstract 109: LAS.initialize must be called before using the library. */
extern NSInteger const kLASErrorCommandNotInitialized;

/** @abstract 110: Update syntax error. */
extern NSInteger const kLASErrorInvalidUpdate;

/*! @abstract 111: Field set to incorrect type. */
extern NSInteger const kLASErrorIncorrectType;

/*! @abstract 112: Invalid channel name. A channel name is either an empty string (the broadcast channel) or contains only a-zA-Z0-9_ characters and starts with a letter. */
extern NSInteger const kLASErrorInvalidChannelName;

/** @abstract 113: BindTo class not found. */
extern NSInteger const kLASErrorBindToClassNotFound;

/*! @abstract 114: Invalid device token. */
extern NSInteger const kLASErrorInvalidDeviceToken;

/*! @abstract 115: Push is misconfigured. See details to find out how. */
extern NSInteger const kLASErrorPushMisconfigured;

/*! @abstract 116: The object is too large. */
extern NSInteger const kLASErrorObjectTooLarge;

/** @abstract 117: The parameters is invalid. */
extern NSInteger const kLASErrorInvalidParameter;

/** @abstract 118: ObjectId is invalid. */
extern NSInteger const kLASErrorInvalidObjectId;

/*! @abstract 119: That operation isn't allowed for clients. */
extern NSInteger const kLASErrorOperationForbidden;

/*! @abstract 120: The results were not found in the cache. */
extern NSInteger const kLASErrorCacheMiss;

/*! @abstract 121: An invalid key was used in a nested JSONObject. Keys in NSDictionary values may not include '$' or '.'. */
extern NSInteger const kLASErrorInvalidNestedKey;

/*! @abstract 123: Invalid ACL. An ACL with an invalid format was saved. This should not happen if you use LASACL. */
extern NSInteger const kLASErrorInvalidACL;

/*! @abstract 124: The request timed out on the server. Typically this indicates the request is too expensive. */
extern NSInteger const kLASErrorTimeout;

/*! @abstract 125: The email address was invalid. */
extern NSInteger const kLASErrorInvalidEmailAddress;

/** @abstract 136: Role name cannot be changed. */
extern NSInteger const kLASErrorRoleNotChangeName;

/*! @abstract 139: A unique field was given a value that is already taken. */
extern NSInteger const kLASErrorDuplicateValue;

/*! @abstract 140: Exceeded an application quota. Upgrade to resolve. */
extern NSInteger const kLASErrorExceededQuota;

/*! @abstract 141: Cloud Code script had an error. */
extern NSInteger const kLASScriptError;

/** @abstract 142: Role is not found. */
extern NSInteger const kLASErrorRoleNotFound;

/*! @abstract 142: Cloud Code validation failed. */
extern NSInteger const kLASValidationError;

/*! @abstract 143: Product purchase receipt is missing */
extern NSInteger const kLASErrorReceiptMissing;

/*! @abstract 144: Product purchase receipt is invalid */
extern NSInteger const kLASErrorInvalidPurchaseReceipt;

/*! @abstract 145: Payment is disabled on this device */
extern NSInteger const kLASErrorPaymentDisabled;

/*! @abstract 146: The product identifier is invalid */
extern NSInteger const kLASErrorInvalidProductIdentifier;

/*! @abstract 147: The product is not found in the App Store */
extern NSInteger const kLASErrorProductNotFoundInAppStore;

/*! @abstract 148: The Apple server response is not valid */
extern NSInteger const kLASErrorInvalidServerResponse;

/*! @abstract 149: Product fails to download due to file system error */
extern NSInteger const kLASErrorProductDownloadFileSystemFailure;

/*! @abstract 150: Fail to convert data to image. */
extern NSInteger const kLASErrorInvalidImageData;

/*! @abstract 151: Unsaved file. */
extern NSInteger const kLASErrorUnsavedFile;

/*! @abstract 153: Fail to delete file. */
extern NSInteger const kLASErrorFileDeleteFailure;


/** @abstract 160: Session token is invalid. */
extern NSInteger const kLASErrorInvalidToken;


/*! @abstract 200: Username is missing or empty */
extern NSInteger const kLASErrorUsernameMissing;

/*! @abstract 201: Password is missing or empty */
extern NSInteger const kLASErrorUserPasswordMissing;

/*! @abstract 202: Username has already been taken */
extern NSInteger const kLASErrorUsernameTaken;

/*! @abstract 203: Email has already been taken */
extern NSInteger const kLASErrorUserEmailTaken;

/*! @abstract 204: The email is missing, and must be specified */
extern NSInteger const kLASErrorUserEmailMissing;

/*! @abstract 205: A user with the specified email was not found */
extern NSInteger const kLASErrorUserWithEmailNotFound;

/*! @abstract 206: The user cannot be altered by a client without the session. */
extern NSInteger const kLASErrorUserCannotBeAlteredWithoutSession;

/*! @abstract 207: Users can only be created through sign up */
extern NSInteger const kLASErrorUserCanOnlyBeCreatedThroughSignUp;

/*! @abstract 208: An existing account already linked to another user. */
extern NSInteger const kLASErrorAccountAlreadyLinked;

/*! @abstract 209: User ID mismatch */
extern NSInteger const kLASErrorUserIdMismatch;

/** @abstract 210: Password does not match. */
extern NSInteger const kLASErrorPasswordMisMatch;

/** @abstract 211: User not found. */
extern NSInteger const kLASErrorUserNotFound;

/*! @abstract 250: User cannot be linked to an account because that account’s ID is not found. */
extern NSInteger const kLASErrorLinkedIdMissing;

/*! @abstract 251: A user with a linked (e.g. Facebook) account has an invalid session. */
extern NSInteger const kLASErrorInvalidLinkedSession;

/** @abstract 252: No supported account linking service found. */
extern NSInteger const kLASErrorUnsupportedSevice;

/** @abstract 253: The authData must be Hash type, not null. */
extern NSInteger const kLASErrorInvalidAuthData;

/** @abstract 301: CAPTCHA input is invalid. */
extern NSInteger const kLASCaptchaError;

/** @abstract 401: Unauthorized access, no App ID, or App ID and App key verification failed. */
extern NSInteger const kLASErrorUnauthorized;

/** @abstract 503: Rate limit exceeded. */
extern NSInteger const kLASErrorRateLimit;


extern NSInteger const kLASErrorNoPermission;


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
typedef void (^LASConfigResultBlock)(LASConfig *config, NSError *error);



#ifndef NS_EXTENSION_UNAVAILABLE
#define NS_EXTENSION_UNAVAILABLE(msg)
#endif /* NS_EXTENSION_UNAVAILABLE */

