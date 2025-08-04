//
// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
//

#import <Foundation/Foundation.h>
#import <AmazonIVSBroadcast/IVSBase.h>
#import <AmazonIVSBroadcast/IVSImageDevice.h>
#import <AmazonIVSBroadcast/IVSMixedDevice.h>

@class IVSMixedImageDeviceSource;

NS_ASSUME_NONNULL_BEGIN

/// A mixed image device that can accept multiple image sources to be mixed together to produce a final output.
/// A mixed image device with no input sources will still produce output, but the output will be a black image.
///
/// @note Previews for this device will be delayed slightly from the input sources due to the time it takes to composite
/// and render the various sources into a single output stream.
///
/// @warn This device will stop mixing when the application is in the background as a result of limited access to metal shaders
/// while backgrounded.
///
/// This can be created through `IVSDeviceDiscovery`.
IVS_EXPORT
@protocol IVSMixedImageDevice <IVSImageDevice, IVSMixedDevice>

/// Adds a source to this mixed device. If this `source` has already been added, this will be a no-op.
/// - Parameter source: The source to add.
- (void)addSource:(IVSMixedImageDeviceSource *)source;

/// Removes a source from the mixed device. If this `source` isn't currently attached, this will be a no-op.
- (void)removeSource:(IVSMixedImageDeviceSource *)source;

/// Returns an array of the sources attached to this device.
- (NSArray<IVSMixedImageDeviceSource *> *)sources;

@end

NS_ASSUME_NONNULL_END
