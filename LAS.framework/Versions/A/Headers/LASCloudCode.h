//
//  LASCloudCode.h
//  LAS
//
//  Created by Sun Jin on 10/13/14.
//  Copyright (c) 2014 iLegendsoft. All rights reserved.
//

#import "LASConstants.h"

/*!
 The `LASCloudCode` class provides methods for interacting with LAS Functions.
 */
@interface LASCloudCode : NSObject

/*!
 Calls the given cloud function with the parameters provided asynchronously and calls the given block when it is done.
 @param function The function name to call.
 @param parameters The parameters to send to the function.
 @param block The block to execute. The block should have the following argument signature:(id object, NSError *error).
 */
+ (void)callFunctionInBackground:(NSString *)function withParameters:(NSDictionary *)parameters block:(LASIdResultBlock)block;

@end
