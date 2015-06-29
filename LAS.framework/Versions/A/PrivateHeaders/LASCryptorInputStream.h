//
//  CryptorInputStream.h
//  CryptPic
//
//  Created by Sun Jin on 15/4/7.
//  Copyright (c) 2015年 ilegendsoft. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LASCryptorInputStream : NSInputStream

- (instancetype)initWithData:(NSData *)data password:(NSString *)password;
- (instancetype)initWithURL:(NSURL *)url password:(NSString *)password;
- (instancetype)initWithFileAtPath:(NSString *)path password:(NSString *)password;

@end
