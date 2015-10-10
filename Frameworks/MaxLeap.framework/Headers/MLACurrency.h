//
//  MLACurrency.h
//  MaxLeap
//
//  Created by Sun Jin on 6/23/15.
//  Copyright (c) 2015 leap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class SKPaymentTransaction;

@interface MLACurrency : NSObject

/**
 * Tracks the beginning of requesting iap purchase.
 *
 * @param transaction    The transaction
 * @param isSubscription Whether the transaction is a subscription
 */
+ (void)onPurchaseRequest:(SKPaymentTransaction *)transaction isSubscription:(BOOL)isSubscription;

/**
 * Tracks the success of iap purchase.
 *
 * @param transaction    The transaction
 * @param isSubscription Whether the transaction is a subscription
 */
+ (void)onPurchaseSuccess:(SKPaymentTransaction *)transaction isSubscription:(BOOL)isSubscription;

/**
 * Tracks the occurrence of cancelling iap purchase.
 *
 * @param transaction    The transaction
 * @param isSubscription Whether the transaction is a subscription
 */
+ (void)onPurchaseCancelled:(SKPaymentTransaction *)transaction isSubscription:(BOOL)isSubscription;

/**
 * Tracks the failure of iap purchase.
 *
 * @param transaction    The transaction
 * @param isSubscription Whether the transaction is a subscription
 */
+ (void)onPurchaseFailed:(SKPaymentTransaction *)transaction isSubscription:(BOOL)isSubscription;

@end
