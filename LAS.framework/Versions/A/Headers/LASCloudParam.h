//
//  LASCloudParam.h
//  LAS
//
//  Created by Sun Jin on 7/25/14.
//  Copyright (c) 2014 iLegendsoft. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LASCloudParam : NSObject

+ (NSString *)getValueWithName:(NSString *)paramName defaultValue:(NSString *)defaultValue;
+ (NSInteger)getIntValueWithName:(NSString *)paramName defaultValue:(NSInteger)defaultValue;
+ (BOOL)getBooleanValueWithName:(NSString *)paramName defaultValue:(BOOL)defaultValue;

/*
 * 用该方法设置observer后，每次CloudyParameter loading结束都会在主线程调用handler
 */
+ (void)addObserverWithIdentifier:(id)identifier handler:(void(^)(void))handler;

/*
 * 用该方法清除CloudyParameter的observer
 */
+ (void)removeObserverWithIdentifier:(id)identifier;

@end
