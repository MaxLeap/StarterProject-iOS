//
//  LASReceiptManager.h
//  LAS
//
//  Created by Sun Jin on 15/3/10.
//  Copyright (c) 2015年 ilegendsoft. All rights reserved.
//

#import <LAS/LASConstants.h>

@interface LASReceiptManager : NSObject

/*!
 @discussion LAS verifies the receipt with Apple and gives the result.
 
 @code
 NSData *receipt = transaction.transactionReceipt;
 
 [LASReceiptManager verifyPaymentReceipt:receipt completion:^(BOOL isValid, NSError *error) {
    if (isValid) {
        // the receipt is valid
    } else {
        if (error) {
            // an error occured
        } else {
            // the receipt is invalid
        }
    }
 }];
 @endcode
 
 @param receiptData The receipt data contained in a transaction.
 @param block the completion block will excute on main thread.
 */
+ (void)verifyPaymentReceipt:(NSData *)receiptData completion:(LASBooleanResultBlock)block;

@end
