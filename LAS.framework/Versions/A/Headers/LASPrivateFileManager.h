//
//  LASPrivateFileManager.h
//  LAS
//
//  Created by Sun Jin on 15/4/8.
//  Copyright (c) 2015年 ilegendsoft. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LASConstants.h"

@class LASPrivateFile;

@interface LASPrivateFileManager : NSObject

/**
 *  *Asynchronously* encrypted and upload file at file.localPath to LAS file servers.
 *
 *  @note <br>
 *  1. The file will be encrypted using AES256. <br>
 *  2. If the file's fileHash is not set, the md5 of file will be calculated and used.<br>
 *  3. Metadata of saved file will be set on the 'file' object.
 *
 *  @param file            The file to save, if file remote path is nil, this operation will failed.
 *  @param shouldOverwrite Overwrite the file at remotePath or not.
 *  @param block           Block to excute on main thread after uploading file, it should have the following argument signature: (BOOL success, NSError *error)
 */
+ (void)saveFileInBackground:(LASPrivateFile *)file overwrite:(BOOL)shouldOverwrite block:(LASBooleanResultBlock)block;

/**
 *  *Asynchronously* encrypted and upload file at file.localPath to LAS file servers.
 *
 *  @note <br>
 *  1. The file will be encrypted using AES256. <br>
 *  2. If the file's fileHash is not set, the md5 of file will be calculated and used.<br>
 *  3. Metadata of saved file will be set on the 'file' object.
 *
 *  @param file            The file to save, if file remote path is nil, this operation will failed.
 *  @param shouldOverwrite Overwrite the file at remotePath or not.
 *  @param block           Block to excute on main thread after uploading file, it should have the following argument signature: (BOOL success, NSError *error)
 *  @param progressBlock   Block to notify the upload progress, it should have the following argument signature: (int percentDone)
 */
+ (void)saveFileInBackground:(LASPrivateFile *)file overwrite:(BOOL)shouldOverwrite block:(LASBooleanResultBlock)block progressBlock:(LASProgressBlock)progressBlock;

/**
 *  Get the default path for downloading the file on LAS file servers which located at the remotePath.
 *
 *  @param remotePath The remote path.
 *
 *  @return default local path
 */
+ (NSString *)defaultLocalPathForFileAtRemotePath:(NSString *)remotePath;

/**
 *  Download the file to default path. After the downloading complete, the block excuted with the local file path or an error.
 *
 *  @param file  The file to download, file's remote path shouldn't be nil.
 *  @param block Block to excute after file downloading. It should have the following argument signature: (NSString *filePath, NSError *error)
 */
+ (void)downloadContentsOfFile:(LASPrivateFile *)file block:(LASStringResultBlock)block;

/**
 *  Download the file to default path. After the downloading complete, the block excuted with the local file path or an error.
 *
 *  @param file          The file to download, file's remote path shouldn't be nil.
 *  @param block         Block to excute after file downloading. It should have the following argument signature: (NSString *filePath, NSError *error)
 *  @param progressBlock Block to notify the upload progress, it should have the following argument signature: (int percentDone)
 */
+ (void)downloadContentsOfFile:(LASPrivateFile *)file block:(LASStringResultBlock)block progressBlock:(LASProgressBlock)progressBlock;

/**
 *  Download a file to a specifed directory.
 *
 *  @discussion local file path = dirPath + file.remotePath
 *
 *  @param file          The file to download, file's remote path shouldn't be nil.
 *  @param dirPath       The path of a directory to save downloaded file.
 *  @param block         Block to excute after file downloading. It should have the following argument signature: (NSString *filePath, NSError *error)
 */
+ (void)downloadContentsOfFile:(LASPrivateFile *)file toDirectory:(NSString *)dirPath block:(LASStringResultBlock)block;

/**
 *  Download a file to a specified directory.
 *
 *  @discussion local file path = dirPath + file.remotePath
 *
 *  @param file          The file to download, file's remote path shouldn't be nil.
 *  @param dirPath       The path of a directory to save downloaded file.
 *  @param block         Block to excute after file downloading. It should have the following argument signature: (NSString *filePath, NSError *error)
 *  @param progressBlock Block to notify the upload progress, it should have the following argument signature: (int percentDone)
 */
+ (void)downloadContentsOfFile:(LASPrivateFile *)file toDirectory:(NSString *)dirPath block:(LASStringResultBlock)block progressBlock:(LASProgressBlock)progressBlock;

/**
 *  Download the file to a specified path.
 *
 *  @param remotePath The remote path of the file.
 *  @param localPath  The local path to save the downloaded file.
 *  @param block      Block to excute after file downloading complete, it should have the following argument signature: (BOOL success, NSError *error)
 */
+ (void)downloadFileAtRemotePath:(NSString *)remotePath toLocalPath:(NSString *)localPath block:(LASBooleanResultBlock)block;

/**
 *  Download the file to a specified path.
 *
 *  @param remotePath    The remote path of the file.
 *  @param localPath     The local path to save the downloaded file.
 *  @param block         Block to excute after file downloading complete, it should have the following argument signature: (BOOL success, NSError *error)
 *  @param progressBlock Block to notify the upload progress, it should have the following argument signature: (int percentDone)
 */
+ (void)downloadFileAtRemotePath:(NSString *)remotePath toLocalPath:(NSString *)localPath block:(LASBooleanResultBlock)block progressBlock:(LASProgressBlock)progressBlock;

/**
 *  Delete the file at file.remotePath from remote server.
 *
 *  @param file  The file to delete, file's remotePath shouldn't be nil.
 *  @param block Block to excute after deleting, it should have the following argument signature: (BOOL success, NSError *error)
 */
+ (void)deleteFileInBackground:(LASPrivateFile *)file block:(LASBooleanResultBlock)block;

/**
 *  Deletes a collection of files all at once asynchronously and excutes the block when done.
 *
 *  @param fileList A collection of files to delete.
 *  @param block    The block should have the following argument signature: (BOOL success, NSError *error)
 */
+ (void)deleteAllInBackground:(NSArray *)fileList block:(LASBooleanResultBlock)block;

/**
 *  Gets the metadata of a file and excutes the block when done.
 *
 *  @discussion The metadata will be set on the 'file' object automatically.
 *
 *  @param file              The file's remote path shouldn't be nil.
 *  @param shouldGetContents Whether to get the contents of a directory.
 *  @param block             The block should have the following argument signature: (BOOL success, NSError *error)
 */
+ (void)getMetaDataInBackground:(LASPrivateFile *)file shouldGetContents:(BOOL)shouldGetContents block:(LASBooleanResultBlock)block;

/**
 *  Gets the metadata of a file and excutes the block when done.
 *
 *  @discussion The metadata will be set on the 'file' object automatically.
 *
 *  @param file     The file's remote path shouldn't be nil.
 *  @param skip     The number of file metadata to skip before returning any.
 *  @param limit    A limit on the number of file metadata to return. The default limit is 200, with a maximum of 2000 results being returned at a time.
 *  @param block    The block should have the following argument signature: (BOOL success, NSError *error)
 */
+ (void)getMetaDataInBackground:(LASPrivateFile *)file skip:(int)skip limit:(int)limit block:(LASBooleanResultBlock)block;

/**
 *  Get the usage of current user.
 *
 *  @param block The block parameter represents usage of current user. It has 3 parameters. 1. fileCount: How many private files the current user save on LAS file servers. 2. usedCapacity: The capacity current user used in bytes. 3. error: If there is an error, both fileCount and usedCapacity are -1.
 */
+ (void)getUsage:(LASUsageResultBlock)block;

/**
 *  Copys a file to another remote path. After copy, the block will give you the new file.
 *
 *  @discussion This method will overwrite dstPath.
 *
 *  @param scrFile The source file to copy, its remote path shouldn't be empty.
 *  @param dstPath The destination remote path.
 *  @param block   Block should have the following argument signature: (LASPrivateFile *newFile, NSError *error)
 */
+ (void)copyFileInBackground:(LASPrivateFile *)scrFile toPath:(NSString *)dstPath block:(LASPrivateFileResultBlock)block;

/**
 *  Copys a file to another remote path. After copying, the block will give you the new file.
 *
 *  @param scrFile         The source file to copy, its remote path shouldn't be empty.
 *  @param dstPath         The destination remote path.
 *  @param shouldOverwrite Whether to overwrite file at dstPath.
 *  @param block           Block should have the following argument signature: (LASPrivateFile *newFile, NSError *error)
 */
+ (void)copyFileInBackground:(LASPrivateFile *)scrFile toPath:(NSString *)dstPath overwrite:(BOOL)shouldOverwrite block:(LASPrivateFileResultBlock)block;

/**
 *  Moves a file to another remote path. After moving, the block will give you the new file.
 *
 *  @discussion This method will overwrite dstPath.
 *
 *  @param scrFile The source file to move, its remote path shouldn't be empty.
 *  @param dstPath The destination remote path.
 *  @param block   Block should have the following argument signature: (LASPrivateFile *newFile, NSError *error)
 */
+ (void)moveFileInBackground:(LASPrivateFile *)scrFile toPath:(NSString *)dstPath block:(LASPrivateFileResultBlock)block;

/**
 *  Moves a file to another remote path. After moving, the block will give you the new file.
 *
 *  @param scrFile         The source file to move, its remote path shouldn't be empty.
 *  @param dstPath         The destination remote path.
 *  @param shouldOverwrite Whether to overwrite file at dstPath.
 *  @param block           Block should have the following argument signature: (LASPrivateFile *newFile, NSError *error)
 */
+ (void)moveFileInBackground:(LASPrivateFile *)scrFile toPath:(NSString *)dstPath overwrite:(BOOL)shouldOverwrite block:(LASPrivateFileResultBlock)block;

/**
 *  Create a folder at remote path file.remotePath.
 *
 *  @param file  The file representing a directory.
 *  @param block Block should have the following argument signature: (BOOL success, NSError *error)
 */
+ (void)createFolderInBackground:(LASPrivateFile *)file block:(LASBooleanResultBlock)block;

/**
 *  Share a file or directory.
 *
 *  @param file  The item to share
 *  @param block Block should have the following argument signature: (BOOL success, NSError *error)
 */
+ (void)shareFileInBackground:(LASPrivateFile *)file block:(LASBooleanResultBlock)block;

/** @name encrypt/decrpyt data util */

/**
 *  *Synchronously* encrypt data using current user's masterKey as the password.
 *
 *  @param data  The data to be encrypted.
 *  @param error If an error occurs, upon returns contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in NULL.
 *
 *  @return The encrypted data, or return nil if an error occured.
 */
+ (NSData *)encryptData:(NSData *)data error:(NSError **)error;

/**
 *  *Synchronously* decrypt data using current user's masterKey as the password.
 *
 *  @param data  The data to be decrypted.
 *  @param error If an error occurs, upon returns contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in NULL.
 *
 *  @return The decrypted data, or return nil if an error occured.
 */
+ (NSData *)decryptData:(NSData *)data error:(NSError **)error;

@end
