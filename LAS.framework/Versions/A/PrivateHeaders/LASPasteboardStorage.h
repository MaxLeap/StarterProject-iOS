//
//  ILSPasteboardStorage.h
//  ILSCrossPromotion
//
//  Created by 周和生 on 13-7-31.
//  Copyright (c) 2013年 周和生. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LASPasteboardStorage : NSObject

+ (LASPasteboardStorage*)sharedInstance123;

- (void)storePasteboardContent: (NSDictionary *)dict;

@property (nonatomic, readonly) NSMutableDictionary *pasteboardContent;

@end
