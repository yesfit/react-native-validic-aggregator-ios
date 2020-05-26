//
//  VLDFormatter.h
//  ValidicMobile
//
//  Created by Ameir Al-Zoubi on 5/14/15.
//  Copyright (c) 2015 Validic. All rights reserved.
//

#import <Foundation/Foundation.h>

/** Class providing basic date formatters */

@interface VLDFormatter : NSObject


/// DateFormatter with UTC timezone and format of yyyy-MM-dd'T'HH:mm:ssxxx
@property (nonatomic, strong) NSDateFormatter *ISO8601DateTimeFormatter;
/// DateFormatter with Local timezone and format of yyyy-MM-dd'T'HH:mm:ssxxx
@property (nonatomic, strong) NSDateFormatter *ISO8601LocalDateTimeFormatter;
/// DateFormatter with UTC timezone and format of yyyy-MM-dd
@property (nonatomic, strong) NSDateFormatter *ISO8601DateFormatter;
/// DateFormatter with xxx timezone
@property (nonatomic, strong) NSDateFormatter *timeZoneFormatter;
/// NumberFormatter with no format set
@property (nonatomic, strong) NSNumberFormatter *numberFormatter;

/// Singleton
+ (instancetype)sharedFormatter;

@end
