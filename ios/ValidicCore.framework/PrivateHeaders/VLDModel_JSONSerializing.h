//
//  VLDModel_JSONSerializing.h
//  ValidicMobile
//
//  Created by Ameir Al-Zoubi on 5/14/15.
//  Copyright (c) 2015 Validic. All rights reserved.
//

@class VLDModel;

@interface VLDModel ()

+ (NSDictionary *)JSONKeyPaths;

+ (instancetype)modelFromJSONObject:(NSDictionary *)JSONObject;
- (NSDictionary *)JSONObject;

@end
