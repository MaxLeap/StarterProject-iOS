//
//  LASRelation.h
//  LAS
//
//  Created by Sun Jin on 6/23/14.
//  Copyright (c) 2014 iLegendsoft. All rights reserved.
//

#import <Foundation/Foundation.h>

@class LASQuery, LASObject;

/*!
 A class that is used to access all of the children of a many-to-many relationship. Each instance of LASRelation is associated with a particular parent object and key.
 */
@interface LASRelation : NSObject

@property (readonly, nonatomic, strong) NSString *targetClass;


#pragma mark Accessing objects
/*!
 @return A LASQuery that can be used to get objects in this relation.
 */
- (LASQuery *)query;


#pragma mark Modifying relations

/*!
 Adds a relation to the passed in object.
 
 @param object LASObject to add relation to.
 */
- (void)addObject:(LASObject *)object;

/*!
 Removes a relation to the passed in object.
 
 @param object LASObject to add relation to.
 */
- (void)removeObject:(LASObject *)object;

@end
