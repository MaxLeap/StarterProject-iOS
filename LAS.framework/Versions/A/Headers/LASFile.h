//
//  LASFile.h
//  LAS
//
//  Created by Sun Jin on 11/10/14.
//  Copyright (c) 2014 iLegendsoft. All rights reserved.
//

#import "LASConstants.h"

/*!
 A file of binary data stored on the Parse servers. This can be a image, video, or anything else
 that an application needs to reference in a non-relational way.
 */
@interface LASFile : NSObject

/** @name Creating a LASFile */

/*!
 Creates a file with given data. A name will be assigned to it by the server.
 @param data The contents of the new LASFile.
 @result A LASFile.
 */
+ (instancetype)fileWithData:(NSData *)data;

/*!
 Creates a file with given data and name.
 @param name The name of the new LASFile.
 @param data The contents of hte new LASFile.
 @result A LASFile.
 */
+ (instancetype)fileWithName:(NSString *)name data:(NSData *)data;

/*!
 Creates a file with the contents of another file.
 @param name The name of the new LASFile
 @param path The path to the file that will be uploaded to Parse
 */
+ (instancetype)fileWithName:(NSString *)name contentsAtPath:(NSString *)path;

/*!
 The name of the file.
 */
@property (readonly) NSString *name;

/*!
 The url of the file.
 */
@property (readonly) NSString *url;

@property (readonly) long long size;

/*!
 Whether the file has been uploaded for the first time.
 */
@property (readonly) BOOL isDirty;

/*!
 Whether the data is available in memory or needs to be downloaded.
 */
@property (assign, readonly) BOOL isDataAvailable;

@end
