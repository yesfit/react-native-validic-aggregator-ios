#import "RNValidicHealthkit.h"


static NSString * const kSampleTypes        = @"sampleTypes";
static NSString * const kSampleTypeObjects  = @"sampleTypeObjects";
static NSString * const kUnknownIdentifiers = @"unknownIdentifiers";
static NSString * const kOnRecordsEvent = @"validic:healthkit:onrecords";

@implementation RNValidicHealthkit{
    bool hasListeners;
}

RCT_EXPORT_MODULE()

- (dispatch_queue_t)methodQueue
{
    return dispatch_get_main_queue();
}


RCT_EXPORT_METHOD(observeCurrentSubscriptions)
{
    [[VLDHealthKitManager sharedInstance] observeCurrentSubscriptions];
}

RCT_EXPORT_METHOD(currentSubscriptions:(RCTResponseSenderBlock)callback)
{
    NSArray<NSString*> *current = [RNValidicHealthkit identifersFromSampleTypes:[[VLDHealthKitManager sharedInstance] subscriptions]];
    if(current == nil){
        current = @[];
    }
    callback(@[current]);
}

RCT_EXPORT_METHOD(setSubscriptions:(NSArray<NSString *> *) subscriptions){
    NSDictionary *result = [RNValidicHealthkit sampleTypesFromIdentifiers:subscriptions];
    NSArray <NSString *> *unknownIdentifiers = result[kUnknownIdentifiers];
    NSArray <HKSampleType *>*sampleTypes = result[kSampleTypeObjects];
    [[VLDHealthKitManager sharedInstance] setSubscriptions:sampleTypes completion:nil];
}

RCT_EXPORT_METHOD(fetchHistory:(NSArray<NSNumber*> *) subscriptionSets resolver: (RCTResponseSenderBlock)resolve){
    [[VLDHealthKitManager sharedInstance] fetchHistoricalSets:subscriptionSets completion:^(NSDictionary * _Nullable results, NSError * _Nullable error) {
        if(results){
            NSMutableDictionary *convertedResults = [NSMutableDictionary new];
            // Convert numberic keys to strings for JSON
            for (NSNumber *resultKey in [results allKeys]) {
                [convertedResults setObject:[results objectForKey:resultKey] forKey:resultKey.stringValue];
            }
            resolve(@[convertedResults]);
        }else{
            resolve(@[error, [NSNull null]]);
        }
    }];
}

- (NSArray<NSString *> *)supportedEvents
{
    return @[kOnRecordsEvent];
}

- (void)onRecordsProcessed:(NSNotification*) notification {
    if(hasListeners){
        NSMutableDictionary *convertedResults = [NSMutableDictionary new];
        // Convert numberic keys to strings for JSON
        for (NSString *resultKey in [notification.userInfo allKeys]) {
            [convertedResults setObject:[notification.userInfo objectForKey:resultKey] forKey:resultKey];
        }
        [self sendEventWithName:kOnRecordsEvent body:convertedResults];
    }
}

- (void)startObserving {
    hasListeners = YES;
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onRecordsProcessed:) name:kVLDHealthKitRecordsProcessedNotification object:nil];
}

- (void)stopObserving {
    hasListeners = NO;
    [[NSNotificationCenter defaultCenter]removeObserver:self name:kVLDHealthKitRecordsProcessedNotification object:nil];
}

-(NSDictionary*) constantsToExport
{
    return @{
             @"HistoricalSetRoutine" : @(VLDHealthKitHistoricalSetRoutine),
             @"HistoricalSetFitness" : @(VLDHealthKitHistoricalSetFitness),
             @"RecordTypeBiometrics": @(VLDRecordTypeBiometrics),
             @"RecordTypeDiabetes" : @(VLDRecordTypeDiabetes),
             @"RecordTypeWeight" : @(VLDRecordTypeWeight),
             @"RecordTypeRoutine" : @(VLDRecordTypeRoutine),
             @"RecordTypeNutrition" : @(VLDRecordTypeNutrition),
             @"RecordTypeSleep" : @(VLDRecordTypeNutrition),
             @"RecordTypeFitness" : @(VLDRecordTypeFitness),
             @"onrecordsevent" : kOnRecordsEvent
             };
}
+(BOOL) requiresMainQueueSetup{
    return YES;
}

#pragma mark Private methods

+ (NSArray <NSString *>*)identifersFromSampleTypes:(NSArray <HKSampleType *>*)types {
    NSMutableArray <NSString *>*result = [NSMutableArray array];
    for (HKSampleType *type in types) {
        NSString *identifier = [self identifierForSampleType:type];
        if (identifier) {
            [result addObject:identifier];
        }
    }
    return result;
}

+ (NSDictionary <NSString *, NSArray *>*)sampleTypesFromIdentifiers:(NSArray <NSString *>*)identifiers {
    NSMutableArray <HKSampleType *>*result = [NSMutableArray array];
    NSMutableArray <NSString *> *unknown = [NSMutableArray array];
    for (NSString *identifier in identifiers) {
        HKSampleType *sampleType = [self sampleTypeForIdentifier:identifier];
        if (sampleType) {
            [result addObject:sampleType];
        } else {
            [unknown addObject:identifier];
        }
    }
    return @{kSampleTypeObjects: result, kUnknownIdentifiers: unknown};
}

+ (NSString *)identifierForSampleType:(HKSampleType *)type {
    return type.identifier;
}

+ (HKSampleType *)sampleTypeForIdentifier:(NSString *)identifier {
    HKSampleType *result;
    result = [HKSampleType quantityTypeForIdentifier:identifier];
    if (!result) {
        result = [HKSampleType categoryTypeForIdentifier:identifier];
        if (!result) {
            result = [HKSampleType correlationTypeForIdentifier:identifier];
            if (!result) {
                if ([identifier isEqualToString:HKWorkoutTypeIdentifier]) {
                    result = [HKSampleType workoutType];
                }
            }
        }
    }
    return result;
}

@end
