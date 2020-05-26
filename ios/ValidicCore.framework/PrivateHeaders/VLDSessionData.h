//
//  VLDSessionData.h
//  ValidicMobile
//
//  Created by Ameir Al-Zoubi on 6/26/15.
//  Copyright (c) 2015 Validic. All rights reserved.
//

#import <ValidicCore/VLDModel.h>

@class VLDUser;
@class VLDRecord;
@class UIImage;
@class VLDBluetoothPeripheral;

@interface VLDSessionData : VLDModel

@property (nonatomic, strong) VLDUser *user;
@property (nonatomic, copy) NSDictionary *queryDates;
@property (nonatomic, copy) NSDictionary *anchors;
@property (nonatomic, strong) NSDate *routineQueryTimestamp;
@property (nonatomic, strong) NSDate *routineFetchTimestamp;
@property (nonatomic, strong) NSDate *intradayStepsQueryTimestamp;
@property (nonatomic, strong) NSDate *intradayStepsFetchTimestamp;
@property (nonatomic, copy) NSArray <NSNumber *> *passivePeripheralIDs;

// Bluetooth
@property (nonatomic, copy) NSDictionary *bluetoothPeripheralData;

- (instancetype)initWithUser:(VLDUser *)user NS_DESIGNATED_INITIALIZER;

// Record queue
- (void)addRecord:(VLDRecord *)record;
- (void)addRecords:(NSArray <__kindof VLDRecord*> *)records;
- (void)removeNextRecordIfMatch:(VLDRecord *)record;
- (VLDRecord *)peekNextRecord;  // Retrieve but do not remove record at head of queue
- (BOOL)hasRecords;

// Image related methods

// Accessors
- (UIImage *)imageForRecord:(VLDRecord *)record;
- (BOOL)hasImageForRecord:(VLDRecord *)record;
- (BOOL)hasImages;
- (VLDRecord *)findNextImageRecordWithRecordID;

// Modifiers
- (void)addRecord:(VLDRecord *)record image:(UIImage *)image;
- (void)removeImageForRecord:(VLDRecord *)record;
- (void)replaceImageRecord:(VLDRecord *)oldRecord newRecord:(VLDRecord *)newRecord;

// Directory management
- (void)verifyImageDirectory;
- (NSString *)imageDirectory;
- (void)eraseImageDirectoryContents;

// Bluetooth related
- (NSDictionary *)dataForBluetoothPeripheralID:(NSUInteger)peripheralID;
- (void)setData:(NSDictionary *)data forBluetoothPeripheralID:(NSUInteger)peripheralID;

@end
