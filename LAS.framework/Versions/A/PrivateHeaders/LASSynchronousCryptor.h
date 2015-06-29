//
//  LASSynchronousCryptor.h
//  LAS
//
//  Created by Sun Jin on 15/4/15.
//  Copyright (c) 2015年 ilegendsoft. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LAS_RNEncryptor.h"
#import "LAS_RNDecryptor.h"

typedef NS_ENUM(NSUInteger, LASCryptorType) {
    LASCryptorTypeEncrypt,
    LASCryptorTypeDecrypt
};

@interface LASSynchronousCryptor : NSObject

- (instancetype)initWithType:(LASCryptorType)type settings:(LAS_RNCryptorSettings)settings password:(NSString *)password;

/**
 *  Get some encrypted/decrypted data by input some new data;
 *
 *  @param inData The new data to input, if nil, no output data will be returned.
 *
 *  @return The encrypted/decrypted data.
 */
- (NSData *)outDataByConsumingData:(NSData *)inData error:(NSError **)error;

/**
 *  !!!IMPORTANT!!! When all data was consumed, call this method to get the final data.
 *
 *  @return the final data
 */
- (NSData *)finishAndReturnsFinalData:(NSError **)error;

/**
 *  @return YES is an error occurred or is finished, NO otherwise
 */
- (BOOL)isFinished;

@end
