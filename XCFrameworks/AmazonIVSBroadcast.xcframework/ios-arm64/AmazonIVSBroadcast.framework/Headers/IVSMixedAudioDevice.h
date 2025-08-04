//
// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
//

#import <Foundation/Foundation.h>
#import <AmazonIVSBroadcast/IVSAudioDevice.h>
#import <AmazonIVSBroadcast/IVSBase.h>
#import <AmazonIVSBroadcast/IVSMixedDevice.h>

@class IVSMixedAudioDeviceSource;

NS_ASSUME_NONNULL_BEGIN

/// A mixed audio device that can accept multiple audio sources to be mixed together to produce a final output.
/// A mixed audio device with no input sources will still produce output, but the output will be silent.
///
/// @note Multiple audio sources will have their audio added together. If there are too many loud sources sending samples at
/// the same time, the output may be clipped. Turn down the gain on individual sources to compensate if necessary.
/// 
/// This can be created through `IVSDeviceDiscovery`.
IVS_EXPORT
@protocol IVSMixedAudioDevice <IVSAudioDevice, IVSMixedDevice>

/// Adds a source to this mixed device. If this `source` has already been added, this will be a no-op.
/// - Parameter source: The source to add.
- (void)addSource:(IVSMixedAudioDeviceSource *)source;

/// Removes a source from the mixed device. If this `source` isn't currently attached, this will be a no-op.
- (void)removeSource:(IVSMixedAudioDeviceSource *)source;

/// Returns an array of the sources attached to this device.
- (NSArray<IVSMixedAudioDeviceSource *> *)sources;

@end

NS_ASSUME_NONNULL_END
