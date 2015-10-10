//
//  MLGAVirtureCurrency.h
//  MaxLeap
//
//  Created by Sun Jin on 6/23/15.
//  Copyright (c) 2015 leap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>

@interface MLGAVirtureCurrency : NSObject

/**
 * Tracks the beginning of requesting iap purchase.
 *
 * @param transaction           The transaction
 * @param orderId               The order id, managed by yourself
 * @param currencyAmount        The cost of this transaction
 * @param currencyType          The currency code, eg. USD
 * @param virtualCurrencyAmount The virtual currency amount
 * @param paySource             The payment platform
 */
+ (void)onChargeRequest:(SKPaymentTransaction *)transaction
                orderId:(NSString *)orderId
         currencyAmount:(double)currencyAmount
           currencyType:(NSString *)currencyType
  virtualCurrencyAmount:(double)virtualCurrencyAmount
              paySource:(NSString *)paySource;

/**
 * Tracks the success of iap purchase.
 *
 * @param transaction The transaction
 * @param orderId     The order id, managed by yourself
 */
+ (void)onChargeSuccess:(SKPaymentTransaction *)transaction orderId:(NSString *)orderId;

/**
 * Tracks the cancellation of iap purchase.
 *
 * @param transaction    The transaction
 * @param orderId        The order id, managed by yourself
 */
+ (void)onChargeCancelled:(SKPaymentTransaction *)transaction orderId:(NSString *)orderId;

/**
 * Tracks the failure of iap purchase.
 *
 * @param transaction    The transaction
 * @param orderId        The order id, managed by yourself
 */
+ (void)onChargeFailed:(SKPaymentTransaction *)transaction orderId:(NSString *)orderId;

/**
 * Tracks the occurrence of rewarding virtual currency.
 *
 * @param virtualCurrencyAmount The amount of rewarding virtual currency
 * @param reason                The reason why rewarding virtual currency
 */
+ (void)onReward:(double)virtualCurrencyAmount reason:(NSString *)reason;

@end
