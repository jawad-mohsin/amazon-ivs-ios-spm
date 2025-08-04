//
// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
//

#import <Foundation/Foundation.h>
#import <AmazonIVSBroadcast/IVSBase.h>

NS_ASSUME_NONNULL_BEGIN

/// Configuration for an `IVSMixedAudioDevice`.
IVS_EXPORT
@interface IVSMixedAudioDeviceConfiguration : NSObject

/// The number of channels for the output audio stream.
/// By default this is `2`.
@property (nonatomic, readonly) NSInteger channels;

/// Set the number of audio channels for the output stream.
/// Currently this must be 1 or 2, otherwise the provided outError will be set.
/// @param channels the number of channels for the audio output stream
/// @param outError On input, a pointer to an error object. If an error occurs, the pointer is an NSError object that describes the error. If you don’t want error information, pass in nil.
/// @return if the set operation is successful or not.
- (BOOL)setChannels:(NSInteger)channels error:(NSError *__autoreleasing *)outError;

@end

NS_ASSUME_NONNULL_END
