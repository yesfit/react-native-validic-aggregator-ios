//
//  RCTConvert+SubscriptionsEnums.m
//  RNValidicHealthkit
//
//  Created by Griffin Wilson on 2/15/19.
//  Copyright © 2019 Facebook. All rights reserved.
//

#import "RCTConvert+SubscriptionsEnums.h"
#import <ValidicHealthKit/ValidicHealthKit.h>

@implementation RCTConvert(ValidicSubscriptionEnums)

RCT_ENUM_CONVERTER(VLDHealthKitHistoricalSet, (@{
                                                 @"HistoricalSetRoutine": @(VLDHealthKitHistoricalSetRoutine),
                                                 @"HistoricalSetFitness" : @(VLDHealthKitHistoricalSetFitness)
                                                 }),-1, integerValue);

RCT_ENUM_CONVERTER(VLDRecordType, (@{
                                    @"RecordTypeBiometrics": @(VLDRecordTypeBiometrics),
                                    @"RecordTypeDiabetes" : @(VLDRecordTypeDiabetes),
                                    @"RecordTypeWeight" : @(VLDRecordTypeWeight),
                                    @"RecordTypeRoutine" : @(VLDRecordTypeRoutine),
                                    @"RecordTypeNutrition" : @(VLDRecordTypeNutrition),
                                    @"RecordTypeFitness" : @(VLDRecordTypeFitness),
                                    @"RecordTypeSleep" : @(VLDRecordTypeSleep)
                                    }), VLDRecordTypeNone, integerValue);

@end
