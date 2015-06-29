//
//  RNEncryptor
//
//  Copyright (c) 2012 Rob Napier
//
//  This code is licensed under the MIT License:
//
//  Permission is hereby granted, free of charge, to any person obtaining a
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//  DEALINGS IN THE SOFTWARE.
//

#import <Foundation/Foundation.h>
#import "LAS_RNCryptor.h"

@interface LAS_RNEncryptor : LAS_RNCryptor
- (LAS_RNEncryptor *)initWithSettings:(LAS_RNCryptorSettings)settings
                    encryptionKey:(NSData *)encryptionKey
                          HMACKey:(NSData *)HMACKey
                          handler:(LAS_RNCryptorHandler)handler;


- (LAS_RNEncryptor *)initWithSettings:(LAS_RNCryptorSettings)settings
                         password:(NSString *)password
                          handler:(LAS_RNCryptorHandler)handler;

// This form with manual IV is generally only used for testing
- (LAS_RNEncryptor *)initWithSettings:(LAS_RNCryptorSettings)theSettings
                    encryptionKey:(NSData *)anEncryptionKey
                          HMACKey:(NSData *)anHMACKey
                               IV:(NSData *)anIV
                          handler:(LAS_RNCryptorHandler)aHandler;

// This form with manual IV and salts is generally only used for testing
- (LAS_RNEncryptor *)initWithSettings:(LAS_RNCryptorSettings)settings
                         password:(NSString *)password
                               IV:(NSData *)anIV
                   encryptionSalt:(NSData *)anEncryptionSalt
                         HMACSalt:(NSData *)anHMACSalt
                          handler:(LAS_RNCryptorHandler)handler;


+ (NSData *)encryptData:(NSData *)data withSettings:(LAS_RNCryptorSettings)settings password:(NSString *)password error:(NSError **)error;
+ (NSData *)encryptData:(NSData *)data withSettings:(LAS_RNCryptorSettings)settings encryptionKey:(NSData *)encryptionKey HMACKey:(NSData *)HMACKey error:(NSError **)error;

// This form with manual IV is generally only used for testing
+ (NSData *)encryptData:(NSData *)thePlaintext
           withSettings:(LAS_RNCryptorSettings)theSettings
          encryptionKey:(NSData *)anEncryptionKey
                HMACKey:(NSData *)anHMACKey
                     IV:(NSData *)anIV
                  error:(NSError **)anError;

// This form with manual IV and salts is generally only used for testing
+ (NSData *)encryptData:(NSData *)data
           withSettings:(LAS_RNCryptorSettings)settings
               password:(NSString *)password
                     IV:(NSData *)anIV
         encryptionSalt:(NSData *)anEncryptionSalt
               HMACSalt:(NSData *)anHMACSalt
                  error:(NSError **)error;

@end
