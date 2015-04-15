//
//  SSKeychainFix.h
//  LAS
//
//  Created by Sun Jin on 11/5/14.
//  Copyright (c) 2014 iLegendsoft. All rights reserved.
//

#import "LAS_SSKeychain.h"

#ifndef LAS_SSKeychainFix_h
#define LAS_SSKeychainFix_h

typedef LAS_SSKeychain                          SSKeychain;
typedef LAS_SSKeychainQuery                     SSKeychainQuery;

typedef LAS_SSKeychainErrorCode                 SSKeychainErrorCode;
#define SSKeychainErrorBadArguments             LAS_SSKeychainErrorBadArguments

typedef LAS_SSKeychainQuerySynchronizationMode  SSKeychainQuerySynchronizationMode;
#define SSKeychainQuerySynchronizationModeAny   LAS_SSKeychainQuerySynchronizationModeAny
#define SSKeychainQuerySynchronizationModeNo    LAS_SSKeychainQuerySynchronizationModeNo
#define SSKeychainQuerySynchronizationModeYes   LAS_SSKeychainQuerySynchronizationModeYes

#define kSSKeychainErrorDomain                  LAS_kSSKeychainErrorDomain
#define kSSKeychainAccountKey                   LAS_kSSKeychainAccountKey
#define kSSKeychainCreatedAtKey                 LAS_kSSKeychainCreatedAtKey
#define kSSKeychainClassKey                     LAS_kSSKeychainClassKey
#define kSSKeychainDescriptionKey               LAS_kSSKeychainDescriptionKey
#define kSSKeychainLabelKey                     LAS_kSSKeychainLabelKey
#define kSSKeychainLastModifiedKey              LAS_kSSKeychainLastModifiedKey
#define kSSKeychainWhereKey                     LAS_kSSKeychainWhereKey

#endif
