//
//  LASQueryManager.h
//  LAS
//
//  Created by Sun Jin on 12/1/14.
//  Copyright (c) 2014 iLegendsoft. All rights reserved.
//

#import "LASConstants.h"

@class LASQuery, LASSearchQuery;

@interface LASQueryManager : NSObject

#pragma mark -
#pragma mark Query

/** @name Getting Objects by ID */

/*!
 Gets a LASObject asynchronously and calls the given block with the result.
 
 @param objectClass The class name for the object that is being requested.
 @param objectId The id of the object that is being requested.
 @param block The block to execute. The block should have the following argument signature: (NSArray *object, NSError *error)
 */
+ (void)getObjectInBackgroundWithClass:(NSString *)objectClass
                              objectId:(NSString *)objectId
                                 block:(LASObjectResultBlock)block;

#pragma mark Find methods

/** @name Getting all Matches for a Query */

/**
 *  Finds objects with the provided query asynchronously and calls the given block with the results.
 *
 *  @param query The query to find objects.
 *  @param block The block to execute. The block should have the following argument signature:(NSArray *objects, NSError *error)
 */
+ (void)findObjectsInBackgroundWithQuery:(LASQuery *)query
                                   block:(LASArrayResultBlock)block;

+ (void)findObjectsUsingElasticSearch:(LASSearchQuery *)query block:(LASDictionaryResultBlock)block;

/** @name Getting the First Match in a Query */

/**
 *  Gets an object asynchronously and calls the given block with the result.<br>
 *
 *  This mutates the LASQuery.
 *
 *  @param query The query.
 *  @param block The block to execute. The block should have the following argument signature:(LASObject *object, NSError *error) result will be nil if error is set OR no object was found matching the query. error will be nil if result is set OR if the query succeeded, but found no results.
 */
+ (void)getFirstObjectInBackgroundWithQuery:(LASQuery *)query
                                      block:(LASObjectResultBlock)block;

#pragma mark Count methods

/** @name Counting the Matches in a Query */

/*!
 Counts objects asynchronously and calls the given block with the counts.
 
 @param query The query
 @param block The block to execute. The block should have the following argument signature: (int count, NSError *error)
 */
+ (void)countObjectsInBackgroundWithQuery:(LASQuery *)query
                                    block:(LASIntegerResultBlock)block;

#pragma mark Cancel methods

/** @name Cancelling a Query */

/**
 *  Cancels the current network request (if any). Ensures that callbacks won't be called.
 *
 *  @param query The query to cancel
 */
+ (void)cancelQuery:(LASQuery *)query;

@end
