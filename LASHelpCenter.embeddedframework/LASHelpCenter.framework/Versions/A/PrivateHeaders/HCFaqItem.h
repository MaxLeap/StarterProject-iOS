//
//  LASFaqItem.h
//  LAS
//
//  Created by Sun Jin on 14/12/24.
//  Copyright (c) 2014年 ilegendsoft. All rights reserved.
//

#import <LAS/LASObject.h>
#import <LAS/LASSubclassing.h>

@interface HCFaqItem : LASObject <LASSubclassing>

@property (nonatomic) NSString *sectionId;
@property (nonatomic) NSString *title;
@property (nonatomic) NSString *content;
@property (nonatomic) NSArray *attach;

@property (nonatomic) NSArray *platform;
@property (nonatomic) NSArray *tags;

@property (nonatomic) NSString *langName;
@property (nonatomic) NSString *langCode;

@property (nonatomic) double seq;

+ (instancetype)itemFromDictionsry:(NSDictionary *)dictionary;

+ (void)sortFaqItems:(NSMutableArray *)items;

@end
