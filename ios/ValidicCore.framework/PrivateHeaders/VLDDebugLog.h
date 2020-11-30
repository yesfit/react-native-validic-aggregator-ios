//
//  VLDDebugLog.h
//  ValidicMobile
//
//  Created by David Melgar on 8/30/16.
//  Copyright © 2016 Validic. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ValidicCore/VLDLogging.h>

extern void VLDLog(VLDLogMask mask, NSString *format, ...) NS_FORMAT_FUNCTION(2,3) NS_NO_TAIL_CALL;

/**
 Set DEBUGMASK to the functional area of the library for which debug messages are desired.
 */
#define DEBUGMASK   VLDLogBluetooth | VLDLogHealthKit | VLDLogOCR | VLDLogCore

#ifndef __dbg_h__
#define __dbg_h__

#define dlog(mask, M, ...) if (mask & DEBUGMASK) VLDLog(mask, @"%s " M, __PRETTY_FUNCTION__, ##__VA_ARGS__)

#endif

