//
// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
//

#import <Foundation/Foundation.h>
#import <AmazonIVSBroadcast/IVSBase.h>

@protocol IVSAudioDevice;
@class IVSMixedAudioDeviceSourceConfiguration;

NS_ASSUME_NONNULL_BEGIN

/// A source for an `IVSMixedAudioDevice`.
IVS_EXPORT
@interface IVSMixedAudioDeviceSource : NSObject

/// The audio device for this source. This can be changed at runtime and the mixed device will immediately apply
/// the new device to the source, having it adopt the source's configuration. This can also be set to `nil`.
@property (nonatomic, strong, nullable) id<IVSAudioDevice> device;

/// The configuration for this source. To update this, provide a new `IVSMixedAudioDeviceSourceConfiguration` to the `transition` API.
@property (nonatomic, strong, readonly) IVSMixedAudioDeviceSourceConfiguration *configuration;

IVS_INIT_UNAVAILABLE

/// Creates a new `IVSMixedAudioDeviceSource` with a required configuration and optional device.
- (instancetype)initWithConfiguration:(IVSMixedAudioDeviceSourceConfiguration *)configuration device:(nullable id<IVSAudioDevice>)device;

/// Transitions this source to a new configuration.
///
/// Multiple concurrent transitions are not supported on the same source. If you initiate a second transition
/// before the first is finished, the transition will start over from the original state and transition to the
/// new state as if the first transition had never been made.
///
/// If there are no devices attached to this source, the duration parameter will be ignored and the slot will be updated immediately.
///
/// @param nextConfiguration The new configuration for this source
/// @param duration The amount of time to animate the transition for
/// @param onComplete An optional callback that will be called when the animation has completed. The boolean
///                   provided will be `true` if the transition finished, or `false` if it was interrupted.
- (void)transitionToConfiguration:(IVSMixedAudioDeviceSourceConfiguration *)nextConfiguration
                         duration:(NSTimeInterval)duration
                       onComplete:(nullable void (^)(BOOL))onComplete;

@end

NS_ASSUME_NONNULL_END
