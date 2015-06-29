//
//  LASMarketingManager.h
//  LAS
//
//  Created by Sun Jin on 5/29/15.
//  Copyright (c) 2015 leapas. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, LASInAppMessageDismissButtonLocation){
    LASInAppMessageDismissButtonLocationLeft,
    LASInAppMessageDismissButtonLocationRight
};

@interface LASMarketingManager : NSObject

/** Enable the marketing module to recieve In-App messages.
 
 Now, marketing will be enabled automatically when setApplicationId:clientKey: get called.
 */
+ (void)enable;

/** Enable LAS SDK In-App message test mode. In test mode a small
 LAS tab will appear on the left side of the screen, enabling a developer to see/test
 all campaigns currently available to this customer.
 */
+ (void)enableTestMode;

/** Set the image to be used for dimissing an In-App message
 @param image The image to be used for dismissing an In-App message. By default this is a
 circle with an 'X' in the middle of it
 */
+ (void)setInAppMessageDismissButtonImage:(UIImage *)image;

/** Set the image to be used for dimissing an In-App message by providing the name of the
 image to be loaded and used
 @param imageName The name of an image to be loaded and used for dismissing an In-App
 message. By default the image is a circle with an 'X' in the middle of it
 */
+ (void)setInAppMessageDismissButtonImageWithName:(NSString *)imageName;

/** Set the location of the dismiss button on an In-App msg
 @param location The location of the button (left or right)
 @see InAppDismissButtonLocation
 */
+ (void)setInAppMessageDismissButtonLocation:(LASInAppMessageDismissButtonLocation)location;

/** Returns the location of the dismiss button on an In-App msg
 @return InAppDismissButtonLocation
 @see InAppDismissButtonLocation
 */
+ (LASInAppMessageDismissButtonLocation)inAppMessageDismissButtonLocation;

+ (void)triggerInAppMessage:(NSString *)triggerName;
+ (void)triggerInAppMessage:(NSString *)triggerName withAttributes:(NSDictionary *)attributes;

+ (void)dismissCurrentInAppMessage;

@end
