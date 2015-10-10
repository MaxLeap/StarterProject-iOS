//
//  MLEmail.h
//  MaxLeap
//
//  Created by Sun Jin on 15/4/21.
//  Copyright (c) 2015年 ilegendsoft. All rights reserved.
//

#ifdef EXTENSION_IOS
    #import <MaxLeapExt/MLConstants.h>
#else
    #import <MaxLeap/MLConstants.h>
#endif

/**
 * `MLEmail` is a representation of an email.
 */
@interface MLEmail : NSObject

/**
 * The e-mail template name
 */
@property (nonatomic, strong) NSString *templateName;

@property (nonatomic, strong) NSString *locale;

/**
 * The e-mail sender
 */
@property (nonatomic, strong) NSString *from;

/**
 * The e-mail recievers
 */
@property (nonatomic, strong) NSArray<NSString*> *to;

/**
 * The arguments in email subject, defined in the template.
 */
@property (nonatomic, strong) NSDictionary<NSString*, NSString*> *subjectArgs;

/**
 * The text arguments
 */
@property (nonatomic, strong) NSDictionary<NSString*, NSString*> *textArgs;

/**
 * The html arguments
 */
@property (nonatomic, strong) NSDictionary<NSString*, NSString*> *htmlArgs;

/**
 * Create an email with the templateName.
 *
 * @param templateName The template name
 */
- (instancetype)initWithTemplateName:(NSString *)templateName;

/**
 * Send this email.
 */
- (void)sendInBackgroundWithBlock:(MLBooleanResultBlock)block;

@end
