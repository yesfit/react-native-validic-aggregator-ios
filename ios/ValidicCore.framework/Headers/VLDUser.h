//
//  VLDUser.h
//  ValidicMobile
//
//  Created by Ameir Al-Zoubi on 5/27/15.
//  Copyright (c) 2015 Validic. All rights reserved.
//

#import "VLDModel.h"

/** VLDUser stores the Validic User ID, Organization ID and Access Token of the User.*/
@interface VLDUser : VLDModel

/** This is the user's Validic ID*/
@property (nonatomic, copy, readonly) NSString *validicUserID;

/** This is the user's Organization ID*/
@property (nonatomic, copy, readonly) NSString *organizationID;

/** This is the user's Access Token*/
@property (nonatomic, copy, readonly) NSString *accessToken;

/** This is the user's Marketplace Token*/
@property (nonatomic, copy, readonly) NSString *marketplaceToken;

/** Initializes VLDUser with a Validic User ID, Organization ID and User Access Token.
 
 @param validicUserID the user ID.
 @param organizationID the organization ID.
 @param accessToken the user access token. */
- (instancetype)initWithValidicUserID:(NSString *)validicUserID organizationID:(NSString *)organizationID accessToken:(NSString *)accessToken NS_DESIGNATED_INITIALIZER;

/** Initializes VLDUser with a Validic User ID, Organization ID, User Access Token, and Marketplace Token

@param validicUserID the user ID.
@param organizationID the organization ID.
@param accessToken the user access token.
@param marketplaceToken the user marketplace token */
- (instancetype)initWithValidicUserID:(NSString *)validicUserID organizationID:(NSString *)organizationID accessToken:(NSString *)accessToken marketplaceToken:(NSString *)marketplaceToken;

@end
