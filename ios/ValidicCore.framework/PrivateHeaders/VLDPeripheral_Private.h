//
//  VLDPeripheral_Private.h
//  ValidicMobile
//
//  Created by David Melgar on 1/18/16.
//  Copyright © 2016 Validic. All rights reserved.
//

@class VLDRecord;

@interface VLDPeripheral ()

/** Return VLDRecord type for this VLDPeripheral */
+ (VLDRecordType)recordTypeForPeripheralType:(VLDPeripheralType)pType;

#pragma Virtual base class methods intended to be used by subclasses

/** Returns the VLDPeripheral for the given ID */
+ (VLDPeripheral *)peripheralForID:(NSUInteger)deviceID;

@end
