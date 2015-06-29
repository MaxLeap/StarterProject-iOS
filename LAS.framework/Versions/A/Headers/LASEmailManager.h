//
//  LASEmailManager.h
//  LAS
//
//  Created by Sun Jin on 15/4/21.
//  Copyright (c) 2015年 ilegendsoft. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LASConstants.h"

@class LASEmail;

@interface LASEmailManager : NSObject

+ (void)sendEmail:(LASEmail *)email block:(LASBooleanResultBlock)block;

@end
