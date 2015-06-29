//
//  LASEmail.h
//  LAS
//
//  Created by Sun Jin on 15/4/21.
//  Copyright (c) 2015年 ilegendsoft. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LASEmail : NSObject

@property (nonatomic, strong) NSString *templateName;
@property (nonatomic, strong) NSString *locale; // charset ???

// provider
@property (nonatomic, strong) NSString *from;
@property (nonatomic, strong) NSArray *to;
@property (nonatomic, strong) NSDictionary *subjectArgs;
@property (nonatomic, strong) NSDictionary *textArgs;
@property (nonatomic, strong) NSDictionary *htmlArgs;

- (instancetype)initWithTemplateName:(NSString *)templateName;

@end
