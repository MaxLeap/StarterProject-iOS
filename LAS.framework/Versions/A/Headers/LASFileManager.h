//
//  LASFileManager.h
//  LAS
//
//  Created by Sun Jin on 11/12/14.
//  Copyright (c) 2014 iLegendsoft. All rights reserved.
//

#import "LASFile.h"
/*!
 The `LASFileManager` class contains static functions that lets you create file on las servers and fetch file contents from las servers.
 */
@interface LASFileManager : NSObject

/*!
 Saves the file asynchronously and executes the given block.
 @param file The file to save.
 @param block The block should have the following argument signature: (BOOL succeeded, NSError *error)
 */
+ (void)saveFileInBackground:(LASFile *)file block:(LASBooleanResultBlock)block;

/*!
 Saves the file asynchronously and executes the given resultBlock. Executes the progressBlock periodically with the percent
 progress. progressBlock will get called with 100 before resultBlock is called.
 @param file The file to save.
 @param block The block should have the following argument signature: (BOOL succeeded, NSError *error)
 @param progressBlock The block should have the following argument signature: (int percentDone)
 */
+ (void)saveFileInBackground:(LASFile *)file block:(LASBooleanResultBlock)block progressBlock:(LASProgressBlock)progressBlock;

/*!
 Synchronously gets the data from cache if available or fetches its contents from the LAS servers. Sets an error if it occurs.
 @param error Pointer to an NSError that will be set if necessary.
 @result The data. Returns nil if there was an error in fetching.
 */
+ (NSData *)getDataOfFile:(LASFile *)file error:(NSError **)error;

/*!
 Asynchronously gets the data from cache if available or fetches its contents
 from the Parse servers. Executes the given block.
 @param file A new file or file from server which must have url.
 @param block The block should have the following argument signature: (NSData *result, NSError *error)
 */
+ (void)getDataOfFileInBackground:(LASFile *)file block:(LASDataResultBlock)block;

/*!
 This method is like getDataInBackgroundWithBlock: but avoids ever holding the
 entire LASFile's contents in memory at once. This can help applications with
 many large LASFiles avoid memory warnings.
 @param file A new file or file from server which must have url.
 @param block The block should have the following argument signature: (NSInputStream *result, NSError *error)
 */
+ (void)getDataStreamOfFileInBackground:(LASFile *)file block:(LASDataStreamResultBlock)block;

/*!
 Asynchronously gets the data from cache if available or fetches its contents
 from the Parse servers. Executes the resultBlock upon
 completion or error. Executes the progressBlock periodically with the percent progress. progressBlock will get called with 100 before resultBlock is called.
 @param file A new file or file from server which must have url.
 @param resultBlock The block should have the following argument signature: (NSData *result, NSError *error)
 @param progressBlock The block should have the following argument signature: (int percentDone)
 */
+ (void)getDataOfFileInBackground:(LASFile *)file block:(LASDataResultBlock)resultBlock progressBlock:(LASProgressBlock)progressBlock;

/*!
 This method is like getDataInBackgroundWithBlock:progressBlock: but avoids ever
 holding the entire LASFile's contents in memory at once. This can help
 applications with many large LASFiles avoid memory warnings.
 
 @param file A new file or file from server which must have url.
 @param resultBlock The block should have the following argument signature: (NSInputStream *result, NSError *error)
 @param progressBlock The block should have the following argument signature: (int percentDone)
 */
+ (void)getDataStreamOfFileInBackground:(LASFile *)file block:(LASDataStreamResultBlock)resultBlock progressBlock:(LASProgressBlock)progressBlock;

/** @name Interrupting a Transfer */

/*!
 Cancels the current request (whether upload or download of file data).
 @param file The file to cancel it's request.
 */
+ (void)cancelRequestOfFile:(LASFile *)file;

/*!
 Get file with specified name.
 @param name The name of a file.
 @param block The block will execute on main thread.
 */
+ (void)getFileWithName:(NSString *)name block:(LASFileResultBlock)block;

/*!
 Get all files uploaded by current user.
 @param block The callback, will be executed on main thread. The block should have the following argument signature: (NSArray *objects, NSError *error).
 */
+ (void)getAllInBackgroundWithBlock:(LASArrayResultBlock)block;

@end
