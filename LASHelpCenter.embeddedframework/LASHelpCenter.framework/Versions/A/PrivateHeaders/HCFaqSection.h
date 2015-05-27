//
//  LASFaqSection.h
//  LAS
//
//  Created by Sun Jin on 14/12/23.
//  Copyright (c) 2014年 ilegendsoft. All rights reserved.
//

#import <LAS/LASObject.h>
#import <LAS/LASSubclassing.h>

@interface HCFaqSection : LASObject <LASSubclassing>

@property (nonatomic) NSString *title;
@property (nonatomic) NSString *appId;
@property (nonatomic) NSString *langName;
@property (nonatomic) NSString *langCode;
@property (nonatomic) double seq;

+ (instancetype)sectionFromDictionary:(NSDictionary *)dictionary;

+ (void)sortFaqSections:(NSMutableArray *)sections;

@end
