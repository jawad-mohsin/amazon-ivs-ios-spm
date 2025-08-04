//
// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
//

#import <Foundation/Foundation.h>
#import <AmazonIVSBroadcast/IVSBase.h>

NS_ASSUME_NONNULL_BEGIN

/// Configuration for an `IVSMixedAudioDeviceSource`.
IVS_EXPORT
@interface IVSMixedAudioDeviceSourceConfiguration : NSObject

/// The gain of the source
/// By default this is `1`.
@property (nonatomic, readonly) float gain;

/// Sets the gain applied to the output of the associated source. This must be between 0 and 2.
/// A gain of 1 means no change. A gain less than 1 will suppress, and greater than 1 will amplify.
/// If the provided gain falls outside this range, the gain will not be set and the provided outError will be set.
/// @param gain The gain applied to the output of the associated source.
/// @param outError On input, a pointer to an error object. If an error occurs, the pointer is an NSError object that describes the error. If you don’t want error information, pass in nil.
/// @return if the set operation is successful or not.
- (BOOL)setGain:(float)gain error:(NSError *__autoreleasing *)outError;

@end

NS_ASSUME_NONNULL_END
