//
//  LASSubclassing.h
//  LAS
//
//  Created by Sun Jin on 7/7/14.
//  Copyright (c) 2014 iLegendsoft. All rights reserved.
//

#import <Foundation/Foundation.h>

@class LASQuery;

/*!
 If a subclass of LASObject conforms to LASSubclassing and calls registerSubclass, LAS will be able to use that class as the native class for a LAS object.<br>
 
 Classes conforming to this protocol should subclass LASObject and include LASObject+Subclass.h in their implementation file. This ensures the methods in the Subclass category of LASObject are exposed in its subclasses only.
 */
@protocol LASSubclassing <NSObject>

/*!
 Constructs an object of the most specific class known to implement +lasClassName. This method takes care to help LASObject subclasses be subclassed themselves. For example, [LASUser object] returns a LASUser by default but will return an object of a registered subclass instead if one is known. A default implementation is provided by LASObject which should always be sufficient.
 
 @return Returns the object that is instantiated.
 */
+ (instancetype)object;

/*!
 Creates a reference to an existing LASObject for use in creating associations between LASObjects.  Calling isDataAvailable on this object will return NO until fetchIfNeeded or refresh has been called.  No network request will be made. A default implementation is provided by LASObject which should always be sufficient.
 
 @param objectId The object id for the referenced object.
 @return A LASObject without data.
 */
+ (instancetype)objectWithoutDataWithObjectId:(NSString *)objectId;

/*! The name of the class as seen in the REST API. */
+ (NSString *)lasClassName;

/*!
 Create a query which returns objects of this type.<br>
 A default implementation is provided by LASObject which should always be sufficient.
 */
+ (LASQuery *)query;

/*!
 Lets LAS know this class should be used to instantiate all objects with class type lasClassName.<br>
 This method must be called before +[LAS setApplicationId:clientKey:]
 */
+ (void)registerSubclass;

@end
