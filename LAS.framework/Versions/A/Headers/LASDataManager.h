//
//  LASDataManager.h
//  LAS
//
//  Created by Sun Jin on 6/25/14.
//  Copyright (c) 2014 iLegendsoft. All rights reserved.
//

#import "LASConstants.h"

/*!
 The helper class for LASObject. This class provides CRUD APIs for LASObject. You can use the methods bellow to create, update, delete and find objects on the LAS server.
 */
@interface LASDataManager : NSObject

#pragma mark -
#pragma mark Save

/*! @name Saving an Object to LAS */

/*!
 Saves the LASObject asynchronously and executes the given callback block.
 
 @param object The object to save.
 @param block The block to execute. The block should have the following argument signature: (BOOL succeeded, NSError *error)
 */
+ (void)saveObjectInBackground:(LASObject *)object block:(LASBooleanResultBlock)block;

/*! @name Saving Many Objects to LAS */

/*!
 Saves a collection of objects all at once asynchronously and the block when done.
 
 @param objects The array of objects to save.
 @param block The block to execute. The block should have the following argument signature: (BOOL succeeded, NSError *error)
 */
+ (void)saveAllInBackground:(NSArray *)objects block:(LASBooleanResultBlock)block;

#pragma mark -
#pragma mark Delete

/*! @name Removing an Object from LAS */

/*!
 Deletes the LASObject asynchronously and executes the given callback block.
 
 @param object The object to delete.
 @param block The block to execute. The block should have the following argument signature: (BOOL succeeded, NSError *error)
 */
+ (void)deleteObjectInBackground:(LASObject *)object block:(LASBooleanResultBlock)block;

/*! @name Delete Many Objects from LAS */

/*!
 Deletes a collection of objects all at once asynchronously and excutes the block when done.
 
 @param objects The array of objects to delete.
 @param block The block to execute. The block should have the following argument signature: (BOOL succeeded, NSError *error)
 */
+ (void)deleteAllInBackground:(NSArray *)objects block:(LASBooleanResultBlock)block;

//+ (void)deleteAllObjectsWithClassName:(NSString *)className completionBlock:(LASIntegerResultBlock)block;

#pragma mark -
#pragma mark Fetch

/*! @name Getting an Object from LAS */

/**
 *  Fetches the LASObject asynchronously and executes the given callback block.
 *
 *  @param object The object
 *  @param block  The block to execute. The block should have the following argument signature: (LASObject *object, NSError *error)
 */
+ (void)fetchDataOfObjectInBackground:(LASObject *)object block:(LASObjectResultBlock)block;

/**
 *  Fetches the LASObject's data asynchronously if isDataAvailable is false, then calls the callback block.
 *
 *  @param object The object
 *  @param block  block The block to execute.  The block should have the following argument signature: (LASObject *object, NSError *error)
 */
+ (void)fetchDataOfObjectIfNeededInBackground:(LASObject *)object block:(LASObjectResultBlock)block;


/*! @name Getting Many Objects from LAS */

/**
 *  Fetches all of the LASObjects with the current data from the server asynchronously and calls the given block.
 *
 *  @param objects An NSArray of LASObjects.
 *  @param block   The block to execute. The block should have the following argument signature: (NSArray *objects, NSError *error)
 */
+ (void)fetchAllInBackground:(NSArray *)objects block:(LASArrayResultBlock)block;

/**
 *  Fetches all of the LASObjects with the current data from the server asynchronously and calls the given block.
 *
 *  @param objects The list of objects to fetch.
 *  @param block   The block to execute. The block should have the following argument signature: (NSArray *objects, NSError *error)
 */
+ (void)fetchAllIfNeededInBackground:(NSArray *)objects block:(LASArrayResultBlock)block;

@end
