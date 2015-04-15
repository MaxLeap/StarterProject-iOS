//
//  LASGeoPoint.h
//  LAS
//
//  Created by Sun Jin on 6/30/14.
//  Copyright (c) 2014 iLegendsoft. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/*!
 Object which may be used to embed a latitude / longitude point as the value for a key in a LASObject. LASObjects with a LASGeoPoint field may be queried in a geospatial manner using LASQuery's whereKey:nearGeoPoint:.<br>
 
 This is also used as a point specifier for whereKey:nearGeoPoint: queries.<br>
 
 Currently, object classes may only have one key associated with a GeoPoint type.
 */
@interface LASGeoPoint : NSObject

/** @name Creating a LASGeoPoint */
/*!
 Create a LASGeoPoint object.  Latitude and longitude are set to 0.0.
 
 @return Returns a new LASGeoPoint.
 */
+ (LASGeoPoint *)geoPoint;

/*!
 Creates a new LASGeoPoint object for the given CLLocation, set to the location's coordinates.
 
 @param location CLLocation object, with set latitude and longitude.
 @return Returns a new LASGeoPoint at specified location.
 */
+ (LASGeoPoint *)geoPointWithLocation:(CLLocation *)location;

/*!
 Creates a new LASGeoPoint object with the specified latitude and longitude.
 
 @param latitude Latitude of point in degrees.
 @param longitude Longitude of point in degrees.
 
 @return New point object with specified latitude and longitude.
 */
+ (LASGeoPoint *)geoPointWithLatitude:(double)latitude longitude:(double)longitude;

/*!
 Fetches the user's current location and returns a new LASGeoPoint object via the provided block.
 
 @param geoPointHandler A block which takes the newly created LASGeoPoint as an argument.
 */
+ (void)geoPointForCurrentLocationInBackground:(void(^)(LASGeoPoint *geoPoint, NSError *error))geoPointHandler;

/** @name Controlling Position */

/// Latitude of point in degrees.  Valid range [-90.0, 90.0].
@property (nonatomic) double latitude;
/// Longitude of point in degrees.  Valid range [-180.0, 180.0].
@property (nonatomic) double longitude;

/** @name Calculating Distance */

/*!
 Get distance in radians from this point to specified point.
 
 @param point LASGeoPoint location of other point.
 @return distance in radians
 */
- (double)distanceInRadiansTo:(LASGeoPoint*)point;

/*!
 Get distance in miles from this point to specified point.
 
 @param point LASGeoPoint location of other point.
 @return distance in miles
 */
- (double)distanceInMilesTo:(LASGeoPoint*)point;

/*!
 Get distance in kilometers from this point to specified point.
 
 @param point LASGeoPoint location of other point.
 @return distance in kilometers
 */
- (double)distanceInKilometersTo:(LASGeoPoint*)point;

@end
