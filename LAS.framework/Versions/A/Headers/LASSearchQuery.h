//
//  LASElasticSearchQuery.h
//  LAS
//
//  Created by Sun Jin on 12/1/14.
//  Copyright (c) 2014 iLegendsoft. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LASSearchQuery : NSObject

/** Create SearchQuery using a query_string element.
 
 @param queryStringElement the query_string element
 
 Sample for queryStringElement:
    @{@"query":@"text to search"}
 
    for more infomation about query_string, please refer to http://www.elasticsearch.org/guide/en/elasticsearch/reference/current/query-dsl-query-string-query.html#query-dsl-query-string-query
 */
+ (instancetype)queryWithQueryStringElement:(NSDictionary *)queryStringElement;

@property (nonatomic, strong) NSArray *classNames;

// Pagination of results can be done by using the from and size parameters.

// The from parameter defines the offset from the first result you want to fetch.
@property (nonatomic) NSInteger from;
// The size parameter allows you to configure the maximum amount of hits to be returned.
@property (nonatomic) NSInteger size;

// A query that uses a query parser in order to parse its content.
@property (nonatomic, strong) NSDictionary *queryStringElement;

@end
