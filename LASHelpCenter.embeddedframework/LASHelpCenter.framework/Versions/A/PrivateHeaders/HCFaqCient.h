//
//  LASFaqManager.h
//  LAS
//
//  Created by Sun Jin on 14/12/23.
//  Copyright (c) 2014年 ilegendsoft. All rights reserved.
//

#import "HCFaqSection.h"
#import "HCFaqItem.h"

@class LASQuery;

@interface HCFaqCient : NSObject

+ (void)getFaqSectionsWithBlock:(LASArrayResultBlock)block;

+ (void)findFaqItemsWithQuery:(LASQuery *)query block:(LASArrayResultBlock)block;
+ (void)getFaqItemWithItemId:(NSString *)itemId block:(void(^)(HCFaqItem *item, NSError *error))block;
+ (void)getFaqItemsInSection:(HCFaqSection *)section block:(LASArrayResultBlock)block;
+ (void)getFaqItemsWithSectionId:(NSString *)sectionId block:(LASArrayResultBlock)block;
+ (void)getAllFaqItemsWithBlock:(LASArrayResultBlock)block;

+ (void)searchFaqItemWithString:(NSString *)string block:(LASArrayResultBlock)block;

@end
