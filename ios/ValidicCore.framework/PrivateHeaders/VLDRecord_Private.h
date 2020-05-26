//
//  VLDRecord_Private.h
//  ValidicMobile
//
//  Created by Ameir Al-Zoubi on 7/1/16.
//  Copyright © 2016 Validic. All rights reserved.
//

@class VLDRecord;

extern NSString * const kVLDRawDataKey;
extern NSString * const kVLDRawDataValueKey;
extern NSString * const kVLDRawDataUnitKey;

extern VLDGlucoseUnit const kVLDStandardGlucoseUnit;
extern VLDWeightUnit const kVLDStandardWeightUnit;
extern VLDTemperatureUnit const kVLDStandardTemperatureUnit;

extern NSInteger const kVLDNoUnitFlag;


@class VLDMeasurement;

@interface VLDRecord ()

- (void)setMeasurementValue:(NSNumber *)value forField:(NSString *)field;
- (void)setMeasurementValue:(NSNumber *)value withUnit:(NSUInteger)unit forField:(NSString *)field;

- (NSDictionary *)rawData;
- (void)setRawMeasurement:(VLDMeasurement *)measurement forField:(NSString *)field;
- (VLDMeasurement *)rawMeasurementForField:(NSString *)field;

- (void)associatePeripheral:(VLDPeripheral *)peripheral;

@end
