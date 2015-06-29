//
//  LASCryptorOutputStream.h
//  CryptPic
//
//  Created by Sun Jin on 15/4/7.
//  Copyright (c) 2015年 ilegendsoft. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LASCryptorOutputStream : NSOutputStream <NSCopying>

- (instancetype)initToMemoryWithPassword:(NSString *)password;
- (instancetype)initToBuffer:(uint8_t *)buffer capacity:(NSUInteger)capacity password:(NSString *)password;
- (instancetype)initWithURL:(NSURL *)url append:(BOOL)shouldAppend password:(NSString *)password;

+ (instancetype)outputStreamToFileAtPath:(NSString *)path append:(BOOL)shouldAppend password:(NSString *)password;

@end
