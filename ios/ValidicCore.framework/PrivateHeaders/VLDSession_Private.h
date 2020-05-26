//
//  VLDSession_Private.h
//  ValidicCore
//
//  Created by Dirk Smith on 12/5/18.
//  Copyright © 2018 Validic. All rights reserved.
//

@interface VLDSession ()

@property (nonatomic, strong) VLDSessionData *sessionData;

- (void)saveSessionData;

- (BOOL)licenseAuthenticated;

@end

