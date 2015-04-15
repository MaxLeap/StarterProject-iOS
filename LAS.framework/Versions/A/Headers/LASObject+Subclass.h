//
//  LASObject+Subclass.h
//  LAS
//
//  Created by Sun Jin on 7/7/14.
//  Copyright (c) 2014 iLegendsoft. All rights reserved.
//

#import "LASObject.h"

@class LASQuery;

/*!
 <h3>Subclassing Notes</h3>
 
 Developers can subclass LASObject for a more native object-oriented class structure. Strongly-typed subclasses of LASObject must conform to the LASSubclassing protocol and must call registerSubclass to be returned by LASQuery and other LASObject factories. All methods in LASSubclassing except for +[LASSubclassing lasClassName] are already implemented in the LASObject(Subclass) category. Inculding LASObject+Subclass.h in your implementation file provides these implementations automatically.<br>
 
 Subclasses support simpler initializers, query syntax, and dynamic synthesizers. The following shows an example subclass:<br>
 
 @code
 @interface MYGame : LASObject< LASSubclassing >
 // Accessing this property is the same as objectForKey:@"title"
 @property (retain) NSString *title;
 + (NSString *)lasClassName;
 @end
 
 @implementation MYGame
 @dynamic title;
 + (NSString *)lasClassName {
    return @"Game";
 }
 @end
 
 MYGame *game = [[MYGame alloc] init];
 game.title = @"Bughouse";
 [LASDataManager saveObjectInBackground:game block:^(BOOL succeeded, NSError *error) {
    if (succeeded) {
 
    } else {
 
    }
 }];
 @endcode
 
 */
@interface LASObject (Subclass)

/*! @name Methods for Subclasses */

/*!
 Designated initializer for subclasses.<br>
 This method can only be called on subclasses which conform to LASSubclassing.<br>
 This method should not be overridden.
 */
- (id)init;

/*!
 Creates an instance of the registered subclass with this class's lasClassName.<br>
 
 This helps a subclass ensure that it can be subclassed itself. For example, [LASUser object] will return a MyUser object if MyUser is a registered subclass of LASUser. For this reason, [MyClass object] is preferred to [[MyClass alloc] init].<br>
 
 This method can only be called on subclasses which conform to LASSubclassing.<br>
 
 A default implementation is provided by LASObject which should always be sufficient.
 */
+ (instancetype)object;

/*! The name of the class as seen in the REST API. */
+ (NSString *)lasClassName;

/*!
 Creates a reference to an existing LASObject for use in creating associations between LASObjects.  Calling isDataAvailable on this object will return NO until fetchIfNeeded has been called.  No network request will be made.<br>
 
 This method can only be called on subclasses which conform to LASSubclassing.<br>
 
 A default implementation is provided by LASObject which should always be sufficient.
 
 @param objectId The object id for the referenced object.
 @return A LASObject without data.
 */
+ (id)objectWithoutDataWithObjectId:(NSString *)objectId;

/*!
 Registers an Objective-C class for LAS to use for representing a given LAS class.<br>
 
 Once this is called on a LASObject subclass, any LASObject LAS creates with a class name matching [self lasClassName] will be an instance of subclass.<br>
 
 This method can only be called on subclasses which conform to LASSubclassing.<br>
 
 A default implementation is provided by LASObject which should always be sufficient.
 */
+ (void)registerSubclass;

/*!
 Returns a query for objects of type +lasClassName.<br>
 
 This method can only be called on subclasses which conform to LASSubclassing.<br>
 
 A default implementation is provided by LASObject which should always be sufficient.
 */
+ (LASQuery *)query;

@end
