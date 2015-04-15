//
//  LASObject.h
//  LAS
//
//  Created by Sun Jin on 6/23/14.
//  Copyright (c) 2014 iLegendsoft. All rights reserved.
//

#import <Foundation/Foundation.h>

@class LASACL;
@class LASRelation;

/*!
 A LAS Framework Object that is a local representation of data persisted to the LAS. This is the main class that is used to interact with objects in your app.
 */
@interface LASObject : NSObject

#pragma - mark Constructors

/*! @name Creating a LASObject */

/*!
 Creates a new LASObject with a class name.
 
 @param className A class name can be any alphanumeric string that begins with a letter. It represents an object in your app, like a User of a Document.
 
 @return Returns the object that is instantiated with the given class name.
 */
+ (instancetype)objectWithClassName:(NSString *)className;

/*!
 Creates a reference to an existing LASObject for use in creating associations between LASObjects.  Calling isDataAvailable on this object will return NO until fetchIfNeeded or refresh has been called.  No network request will be made.
 
 @param className The object's class.
 @param objectId The object id for the referenced object.
 @return A LASObject without data.
 */
+ (instancetype)objectWithoutDataWithClassName:(NSString *)className objectId:(NSString *)objectId;

/*!
 Creates a new LASObject with a class name, initialized with data constructed from the specified set of objects and keys.
 
 @param className The object's class.
 @param dictionary An NSDictionary of keys and objects to set on the new LASObject.
 @return A LASObject with the given class name and set with the given data.
 */
+ (instancetype)objectWithClassName:(NSString *)className dictionary:(NSDictionary *)dictionary;

/*!
 Initializes a new LASObject with a class name.
 
 @param newClassName A class name can be any alphanumeric string that begins with a letter. It represents an object in your app, like a User or a Document.
 @return Returns the object that is instantiated with the given class name.
 */
- (id)initWithClassName:(NSString *)newClassName;

#pragma mark -
#pragma mark Properties

/*! @name Managing Object Properties */

/*!
 The class name of the object.
 */
@property (nonatomic, readonly) NSString *lasClassName;

/*!
 The id of the object.
 */
@property (nonatomic, strong, readonly) NSString *objectId;

/*!
 When the object was last updated.
 */
@property (nonatomic, strong, readonly) NSDate *updatedAt;

/*!
 When the object was created.
 */
@property (nonatomic, strong, readonly) NSDate *createdAt;

/*!
 The ACL for this object.
 */
@property (nonatomic, strong) LASACL *ACL;

/*!
 Returns an array of the keys contained in this object. This does not include createdAt, updatedAt, authData, or objectId. It does include things like username and ACL.
 */
- (NSArray *)allKeys;



#pragma mark -
#pragma mark Get and set

/*!
 Returns the object associated with a given key.
 
 @param key The key that the object is associated with.
 @return The value associated with the given key, or nil if no value is associated with key.
 */
- (id)objectForKey:(NSString *)key;

/*!
 Sets the object associated with a given key.
 
 @param object The object.
 @param key The key.
 */
- (void)setObject:(id)object forKey:(NSString *)key;

/*!
 Unsets a key on the object.
 
 @param key The key.
 */
- (void)removeObjectForKey:(NSString *)key;

/*!
 * In LLVM 4.0 (XCode 4.5) or higher allows myLASObject[key].
 
 @param key The key.
 */
- (id)objectForKeyedSubscript:(NSString *)key;

/*!
 * In LLVM 4.0 (XCode 4.5) or higher allows myObject[key] = value
 
 @param object The object.
 @param key The key.
 */
- (void)setObject:(id)object forKeyedSubscript:(NSString *)key;

/*!
 Returns the relation object associated with the given key
 
 @param key The key that the relation is associated with.
 */
- (LASRelation *)relationForKey:(NSString *)key;

#pragma mark -
#pragma mark Array add and remove

/*!
 Adds an object to the end of the array associated with a given key.
 
 @param object The object to add.
 @param key The key.
 */
- (void)addObject:(id)object forKey:(NSString *)key;

/*!
 Adds the objects contained in another array to the end of the array associated with a given key.
 
 @param objects The array of objects to add.
 @param key The key.
 */
- (void)addObjectsFromArray:(NSArray *)objects forKey:(NSString *)key;

/*!
 Adds an object to the array associated with a given key, only if it is not already present in the array. The position of the insert is not guaranteed.
 
 @param object The object to add.
 @param key The key.
 */
- (void)addUniqueObject:(id)object forKey:(NSString *)key;

/*!
 Adds the objects contained in another array to the array associated with a given key, only adding elements which are not already present in the array. The position of the insert is not guaranteed.
 
 @param objects The array of objects to add.
 @param key The key.
 */
- (void)addUniqueObjectsFromArray:(NSArray *)objects forKey:(NSString *)key;

/*!
 Removes all occurrences of an object from the array associated with a given key.
 
 @param object The object to remove.
 @param key The key.
 */
- (void)removeObject:(id)object forKey:(NSString *)key;

/*!
 Removes all occurrences of the objects contained in another array from the array associated with a given key.
 
 @param objects The array of objects to remove.
 @param key The key.
 */
- (void)removeObjectsInArray:(NSArray *)objects forKey:(NSString *)key;

#pragma mark -
#pragma mark Increment

/*!
 Increments the given key by 1.
 
 @param key The key.
 */
- (void)incrementKey:(NSString *)key;

/*!
 Increments the given key by a number.
 
 @param key The key.
 @param amount The amount to increment.
 */
- (void)incrementKey:(NSString *)key byAmount:(NSNumber *)amount;

#pragma mark -
#pragma mark Data Availability

/*!
 Gets whether the LASObject has been fetched.
 @return YES if the LASObject is new or has been fetched or refreshed.  NO otherwise.
 */
- (BOOL)isDataAvailable;

#pragma mark -
#pragma Dirtiness

/*!
 Gets whether any key-value pair in this object (or its children) has been added/updated/removed and not saved yet.
 @return Returns whether this object has been altered and not saved yet.
 */
- (BOOL)isDirty;

/*!
 Get whether a value associated with a key has been added/updated/removed and not saved yet.
 @param key The key to check for
 @return Returns whether this key has been altered and not saved yet.
 */
- (BOOL)isDirtyForKey:(NSString *)key;
@end
