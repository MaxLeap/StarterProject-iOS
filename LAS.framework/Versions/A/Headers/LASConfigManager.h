//
//  LASConfigManager.h
//  LAS
//
//  Created by Sun Jin on 15/2/9.
//  Copyright (c) 2015年 ilegendsoft. All rights reserved.
//

#import "LASConstants.h"

typedef void (^LASConfigValueChangedBlock)(id newValue, id oldValue);

/*!
 `LASConfigManager` helps you retrieve config and observe the current config value changes.
 */
@interface LASConfigManager : NSObject

///--------------------------------------
/// @name Current Config
///--------------------------------------

/*!
 @abstract Returns the most recently fetched config.
 
 @discussion If there was no config fetched - this method will return an empty instance of `LASConfig`.
 
 @returns Current, last fetched instance of LASConfig.
 */
+ (LASConfig *)currentConfig;

///--------------------------------------
/// @name Retrieving Config
///--------------------------------------

/*!
 @abstract Gets the `LASConfig` *asynchronously* and executes the given callback block.
 
 @param block The block to execute. It should have the following argument signature: `^(LASConfig *config, NSError *error)`.
 */
+ (void)getConfigInBackgroundWithBlock:(LASConfigResultBlock)block;

/**
 *  Gets the `LASConfig` *asynchronously* for the given keys from LAS servers and executes the given callback block.
 *
 *  @param keys  The keys to get, pass `nil` to get all key-values.
 *  @param block The block to execute. It should have the following argument signature: `^(LASConfig *config, NSError *error)`.
 */
+ (void)getValuesForKeys:(NSArray *)keys inBackgroundWithBlock:(LASConfigResultBlock)block;

///--------------------------------------
/// @name Observe Config Changes
///--------------------------------------

/**
 *  Registers anObserver to receive config value changed notifications for the specified key relative to the current config.
 *  The observer is not retained.
 *
 *  @param observer The object to register for config value changed notifications.
 *  @param key      The key, relative to the current config, of the property to observe. This value must not be nil.
 *  @param block    The callback to be excuted when value for the specified key changed. It should have the following argument signature: `^(id newValue, id oldValue)`.
 */
+ (void)addObserver:(NSObject *)observer forKey:(NSString *)key valueChangedHandler:(LASConfigValueChangedBlock)block;

/**
 *  Stops a given object from receiving config value change notifications for the property specified by a given key relative to the current config.
 *  Be sure to invoke this method (or removeObserver:) before any object specified in addObserver:forKey:valueChangedHandler: is deallocated.
 *
 *  @param observer The object to remove as an observer.
 *  @param key      A key, relative to the current config, for which anObserver is registered to receive config value change notifications.
 */
+ (void)removeObserver:(NSObject *)observer forKey:(NSString *)key;

/**
 *  Stops a given object from receiving config value change notifications.
 *  Be sure to invoke this method (or removeObserver:forKey:) before any object specified in addObserver:forKey:valueChangedHandler: is deallocated.
 *
 *  @param observer The object to remove as an observer.
 */
+ (void)removeObserver:(NSObject *)observer;

@end
