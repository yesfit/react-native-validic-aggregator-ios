//
//  VLDLogging.h
//  ValidicCore
//
//  Created by Phil Cole on 9/25/19.
//  Copyright © 2019 Validic. All rights reserved.
//

#import <Foundation/Foundation.h>

// Mask for the functional Validic frameworks where debug messages are desired
typedef NS_OPTIONS(NSUInteger, VLDLogMask) {
    VLDLogBluetooth = 1 << 0,
    VLDLogHealthKit = 1 << 1,
    VLDLogOCR       = 1 << 2,
    VLDLogCore      = 1 << 3
};

@interface VLDLogging : NSObject

// Enables or disbales loggin to the console
@property(nonatomic) BOOL isEnabled;
/*
 Mask to output debug messages from Validic Frameworks. Ex: [[VLDLogging sharedInstance] setLog:VLDLogBluetooth & VLDLogCore];
 */
@property(nonatomic) NSUInteger log;

/** sharedInstance returns the VLDLogging singleton and should be the only way VLDLogging is accessed. */
+ (instancetype)sharedInstance;

@end

