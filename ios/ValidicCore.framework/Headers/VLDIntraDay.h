//
//  VLDIntraDay.h
//
//  Created by Dirk Smith on 3/1/19.
//  Copyright © 2019 Validic. All rights reserved.
//

#import <ValidicCore/ValidicCore.h>

NS_ASSUME_NONNULL_BEGIN

@interface VLDIntraDay : VLDRecord

@property (nonatomic, strong) NSDate *start;
@property (nonatomic, strong) NSDate *end;
@property (nonatomic, copy) NSString *deviceSource;
@property (nonatomic, copy) NSMutableArray *entries;
@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSString *unit;
@property (nonatomic, strong) NSString *model;
@property (nonatomic, strong) NSString *manufacturer;

- (void)addValue:(double)value withStartDate:(NSDate *)startDate withEndDate:(NSDate *)endDate;

@end

NS_ASSUME_NONNULL_END
