//
//  VLDBiometrics_Private.h
//  ValidicMobile
//
//  Created by David Melgar on 4/24/16.
//  Copyright © 2016 Validic. All rights reserved.
//

@interface VLDBiometrics ()

@property (nonatomic, strong) NSNumber *arterialPressure;

- (void)setMinHeartRate:(NSNumber *)min;
- (void)setMaxHeartRate:(NSNumber *)max;
- (void)setAverageHeartRate:(NSNumber *)average;
- (void)setMedianHeartRate:(NSNumber *)median;

@end
