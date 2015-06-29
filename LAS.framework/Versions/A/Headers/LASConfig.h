//
//  LASConfig.h
//  LAS
//
//  Created by Sun Jin on 15/2/9.
//  Copyright (c) 2015年 ilegendsoft. All rights reserved.
//

#import <Foundation/Foundation.h>

@class LASGeoPoint, LASFile;

/*!
 `LASConfig` is a representation of the remote configuration object.
 It enables you to add things like feature gating, a/b testing or simple "Message of the day".
 */
@interface LASConfig : NSObject

///--------------------------------------
/// @name Parameters
///--------------------------------------

/*!
 @abstract Returns the object associated with a given key.
 
 @param key The key for which to return the corresponding configuration value.
 
 @returns The value associated with `key`, or `nil` if there is no such value.
 */
- (id)objectForKey:(NSString *)key;

/*!
 @abstract Returns the object associated with a given key.
 
 @discussion This method enables usage of literal syntax on `LASConfig`.
 E.g. `NSString *value = config[@"key"];`
 
 @see objectForKey:
 
 @param keyedSubscript The keyed subscript for which to return the corresponding configuration value.
 
 @returns The value associated with `key`, or `defaultValue` if there is no such value.
 */
- (id)objectForKeyedSubscript:(NSString *)keyedSubscript;

/*!
 @abstract Returns the object as string value associated with a given key.
 
 @param key The key for which to return the corresponding configuration value.
 @param defaultValue The default value will be returned if there is no such value
 
 @returns The value associated with `key`, or `defaultValue` if there is no such value.
 */
- (NSString *)stringForKey:(NSString *)key defaultValue:(NSString *)defaultValue;

/*!
 @abstract Returns the object associated with a given key.
 
 @param key The key for which to return the corresponding configuration value.
 @param defaultValue The default value will be returned if there is no such value
 
 @returns The value associated with `key`, or `defaultValue` if there is no such value.
 */
- (NSDate *)dateForKey:(NSString *)key defaultValue:(NSDate *)defaultValue;

/*!
 @abstract Returns the object associated with a given key.
 
 @param key The key for which to return the corresponding configuration value.
 @param defaultValue The default value will be returned if there is no such value
 
 @returns The value associated with `key`, or `defaultValue` if there is no such value.
 */
- (NSArray *)arrayForKey:(NSString *)key defaultValue:(NSArray *)defaultValue;

/*!
 @abstract Returns the object associated with a given key.
 
 @param key The key for which to return the corresponding configuration value.
 @param defaultValue The default value will be returned if there is no such value
 
 @returns The value associated with `key`, or `defaultValue` if there is no such value.
 */
- (NSDictionary *)dictionaryForKey:(NSString *)key defaultValue:(NSDictionary *)defaultValue;

/*!
 @abstract Returns the object associated with a given key.
 
 @param key The key for which to return the corresponding configuration value.
 @param defaultValue The default value will be returned if there is no such value
 
 @returns The value associated with `key`, or `defaultValue` if there is no such value.
 */
- (LASFile *)fileForKey:(NSString *)key defaultValue:(LASFile *)defaultValue;

/*!
 @abstract Returns the object associated with a given key.
 
 @param key The key for which to return the corresponding configuration value.
 @param defaultValue The default value will be returned if there is no such value
 
 @returns The value associated with `key`, or `defaultValue` if there is no such value.
 */
- (LASGeoPoint *)geoPointForKey:(NSString *)key defaultValue:(LASGeoPoint *)defaultValue;

/*!
 @abstract Returns the object associated with a given key.
 
 @param key The key for which to return the corresponding configuration value.
 @param defaultValue The default value will be returned if there is no such value
 
 @returns The value associated with `key`, or `defaultValue` if there is no such value.
 */
- (BOOL)boolForKey:(NSString *)key defaultValue:(BOOL)defaultValue;

/*!
 @abstract Returns the object associated with a given key.
 
 @param key The key for which to return the corresponding configuration value.
 @param defaultValue The default value will be returned if there is no such value
 
 @returns The value associated with `key`, or `defaultValue` if there is no such value.
 */
- (NSNumber *)numberForKey:(NSString *)key defaultValue:(NSNumber *)defaultValue;

/*!
 @abstract Returns the object associated with a given key.
 
 @param key The key for which to return the corresponding configuration value.
 @param defaultValue The default value will be returned if there is no such value
 
 @returns The value associated with `key`, or `defaultValue` if there is no such value.
 */
- (NSInteger)integerForKey:(NSString *)key defaultValue:(NSInteger)defaultValue;

/*!
 @abstract Returns the object associated with a given key.
 
 @param key The key for which to return the corresponding configuration value.
 @param defaultValue The default value will be returned if there is no such value
 
 @returns The value associated with `key`, or `defaultValue` if there is no such value.
 */
- (float)floatForKey:(NSString *)key defaultValue:(float)defaultValue;

/*!
 @abstract Returns the object associated with a given key.
 
 @param key The key for which to return the corresponding configuration value.
 @param defaultValue The default value will be returned if there is no such value
 
 @returns The value associated with `key`, or `defaultValue` if there is no such value.
 */
- (double)doubleForKey:(NSString *)key defaultValue:(double)defaultValue;

@end
