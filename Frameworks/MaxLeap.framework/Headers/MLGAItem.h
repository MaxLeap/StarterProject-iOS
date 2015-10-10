//
//  MLGAItem.h
//  MaxLeap
//
//  Created by Sun Jin on 6/24/15.
//  Copyright (c) 2015 leap. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MLGAItem : NSObject

/**
 * Tracks the occurrence of purchasing item.
 *
 * @param itemId                The customize item id.
 * @param count                 The purchase number of items.
 * @param type                  The customize item type.
 * @param virtualCurrencyAmount The virtual currency amount.
 */
+ (void)onPurchase:(NSString *)item itemCount:(int)count itemType:(NSString *)type virtualCurrency:(double)virtualCurrencyAmount;

/**
 * Tracks the occurrence of using item.
 *
 * @param itemId The customize item id.
 * @param type   The item type
 * @param count  The used number of items.
 */
+ (void)onUse:(NSString *)item itemType:(NSString *)type itemCount:(int)count;

/**
 * Tracks the occurrence of rewarding item.
 *
 * @param itemId The customize item id.
 * @param type   The customize item type.
 * @param count The purchase number of items.
 * @param reason The reason why rewarding the item.
 */
+ (void)onReward:(NSString *)item itemType:(NSString *)itemType itemCount:(int)count reason:(NSString *)reason;

@end
