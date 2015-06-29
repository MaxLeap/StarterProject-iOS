//
//  LASPrivateFile.h
//  LAS
//
//  Created by Sun Jin on 15/4/8.
//  Copyright (c) 2015年 ilegendsoft. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LASPrivateFile : NSObject

/**
 *  A formated string representing the item size, eg: "1.1 MB", "832.5 KB".
 */
@property (nonatomic, readonly) NSString *size;

/**
 *  A number indicates the size of item in bytes.
 */
@property (nonatomic, readonly) NSUInteger bytes;

/**
 *  The file's MIMEType.
 */
@property (nonatomic, readonly) NSString *MIMEType;

/**
 *  When the file or directory was created.
 */
@property (nonatomic, readonly) NSDate *createdAt;

/**
 *  When the file or directory was last updated.
 */
@property (nonatomic, readonly) NSDate *updatedAt;

/**
 *  The item's path on remote server.
 */
@property (nonatomic, readonly) NSString *remotePath;

/**
 *  The local path of the item.
 */
@property (nonatomic, copy) NSString *localPath;

/**
 *  Whether this item is a directory.
 */
@property (nonatomic, readonly) BOOL isDirectory;

/**
 *  The contents of the dir. If this item is not a directory, contents is nil.
 */
@property (nonatomic, readonly) NSArray *contents;

/**
 *  Whether the item is deleted from remote server.
 */
@property (nonatomic, readonly) BOOL isDeleted;

/**
 *  Whether the item is shared from another user.
 */
@property (nonatomic, readonly) BOOL isShared;

/**
 *  The id of user who shared this item.
 */
@property (nonatomic, readonly) NSString *shareFrom;

/**
 *  The share url.
 */
@property (nonatomic, readonly) NSURL *url;

/**
 *  Hash of the file.
 */
@property (nonatomic, copy) NSString *fileHash;

/**
 *  Initialize a privateFile with localPath and remotePath.
 *
 *  @param localPath  The path of the file on local disk.
 *  @param remotePath The path of the file on remote server, shouldn't be nil.
 *
 *  @return A private file instance.
 */
- (instancetype)initWithLocalFileAtPath:(NSString *)localPath remotePath:(NSString *)remotePath;

/**
 *  Initialize a privateFile with remotePath.
 *
 *  @param remotePath The path of the file on remote server, shouldn't be nil.
 *
 *  @return A private file instance
 */
- (instancetype)initWithRemotePath:(NSString *)remotePath;

@end
