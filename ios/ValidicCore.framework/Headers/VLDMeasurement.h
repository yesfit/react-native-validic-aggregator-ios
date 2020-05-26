//
//  VLDMeasurement.h
//  ValidicMobile
//
//  Created by Ameir Al-Zoubi on 7/7/16.
//  Copyright © 2016 Validic. All rights reserved.
//

#import <ValidicCore/ValidicCore.h>

/**
    Wrapper class for VLDRecord's value and unit
 */

@interface VLDMeasurement : VLDModel
/// String representation of the value taken.
@property (nonatomic, copy) NSString *value;
/// String representation of the metric unit.
@property (nonatomic, copy) NSString *unit;
/// Readonly property returning instance of decimalNumberWithString:(nullable NSString *)numberValue.
@property (nonatomic, readonly) NSDecimalNumber *decimalValue;

/// Destignated initalizer
- (instancetype)initWithValue:(NSString *)value unit:(NSString *)unit NS_DESIGNATED_INITIALIZER;
/// Convience initalizer
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;
/// Dictionary containing value and unit. Access with kVLDRawDataValueKey and kVLDRawDataUnitKey
- (NSDictionary *)dictionaryRepresentation;

@end
