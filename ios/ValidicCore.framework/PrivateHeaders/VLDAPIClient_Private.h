//
//  VLDAPIClient_Private.h
//  ValidicMobile
//
//  Created by Ameir Al-Zoubi on 8/14/15.
//  Copyright © 2015 Validic. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <ValidicCore/VLDAPIClient.h>

@interface VLDAPIClient ()

- (void)uploadImage:(UIImage *)image completion:(void (^)(id responseObject, NSError *error))completion;

@end
