//
//  VLDSession_Private.h
//  ValidicCore
//
//  Created by Dirk Smith on 12/5/18.
//  Copyright © 2018 Validic. All rights reserved.
//

@class VLDAPIClient;

@interface VLDSession ()

@property (nonatomic, strong) VLDSessionData *sessionData;
@property (nonatomic, strong) VLDAPIClient *apiClient;

- (void)saveSessionData;

- (BOOL)licenseAuthenticated;

@end

