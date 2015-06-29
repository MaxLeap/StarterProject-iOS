//
//  RNCryptor.h
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
#import <CommonCrypto/CommonCrypto.h>
#import <Security/Security.h>

extern NSString *const kLASRNCryptorErrorDomain;
extern const uint8_t kLASRNCryptorFileVersion;

typedef struct _LAS_RNCryptorKeyDerivationSettings
{
    size_t keySize;
    size_t saltSize;
    CCPBKDFAlgorithm PBKDFAlgorithm;
    CCPseudoRandomAlgorithm PRF;
    uint rounds;
    BOOL hasV2Password; // See Issue #77. V2 incorrectly handled multi-byte characters.
} LAS_RNCryptorKeyDerivationSettings;

typedef struct _LAS_RNCryptorSettings
{
    CCAlgorithm algorithm;
    size_t blockSize;
    size_t IVSize;
    CCOptions options;
    CCHmacAlgorithm HMACAlgorithm;
    size_t HMACLength;
    LAS_RNCryptorKeyDerivationSettings keySettings;
    LAS_RNCryptorKeyDerivationSettings HMACKeySettings;
} LAS_RNCryptorSettings;

static const LAS_RNCryptorSettings kLASRNCryptorAES256Settings = {
    .algorithm = kCCAlgorithmAES128,
    .blockSize = kCCBlockSizeAES128,
    .IVSize = kCCBlockSizeAES128,
    .options = kCCOptionPKCS7Padding,
    .HMACAlgorithm = kCCHmacAlgSHA256,
    .HMACLength = CC_SHA256_DIGEST_LENGTH,
    
    .keySettings = {
        .keySize = kCCKeySizeAES256,
        .saltSize = 8,
        .PBKDFAlgorithm = kCCPBKDF2,
        .PRF = kCCPRFHmacAlgSHA1,
        .rounds = 10000
    },
    
    .HMACKeySettings = {
        .keySize = kCCKeySizeAES256,
        .saltSize = 8,
        .PBKDFAlgorithm = kCCPBKDF2,
        .PRF = kCCPRFHmacAlgSHA1,
        .rounds = 10000
    }
};

enum _LAS_RNCryptorOptions
{
    kLASRNCryptorOptionHasPassword = 1 << 0,
};
typedef uint8_t LAS_RNCryptorOptions;

enum
{
    kLASRNCryptorHMACMismatch = 1,
    kLASRNCryptorUnknownHeader = 2,
};

@class LAS_RNCryptor;

typedef void (^LAS_RNCryptorHandler)(LAS_RNCryptor *cryptor, NSData *data);

///** Encryptor/Decryptor for iOS
//
//  Provides an easy-to-use, Objective-C interface to the AES functionality of CommonCrypto. Simplifies correct handling of
//  password stretching (PBKDF2), salting, and IV. For more information on these terms, see "Properly encrypting with AES
//  with CommonCrypto," and iOS 5 Programming Pushing the Limits, Chapter 11. Also includes automatic HMAC handling to integrity-check messages.
//
//  RNCryptor is abstract. Use RNEncryptor to encrypt or RNDecryptor to decrypt
// */
//

@interface LAS_RNCryptor : NSObject
@property (nonatomic, readonly, strong) NSError *error;
@property (nonatomic, readonly, getter=isFinished) BOOL finished;
@property (nonatomic, readonly, copy) LAS_RNCryptorHandler handler;
@property (nonatomic, readwrite) dispatch_queue_t responseQueue;

- (void)addData:(NSData *)data;
- (void)finish;

/** Generate key given a password and salt using a PBKDF
 *
 * @param password Password to use for PBKDF
 * @param salt Salt for password
 * @param keySettings Settings for the derivation (LAS_RNCryptorKeyDerivationSettings)
 * @returns Key
 * @throws if settings are illegal
 */
+ (NSData *)keyForPassword:(NSString *)password salt:(NSData *)salt settings:(LAS_RNCryptorKeyDerivationSettings)keySettings;

/** Generate random data
 *
 * @param length Length of data to generate
 * @returns random data
 */
+ (NSData *)randomDataOfLength:(size_t)length;

@end
