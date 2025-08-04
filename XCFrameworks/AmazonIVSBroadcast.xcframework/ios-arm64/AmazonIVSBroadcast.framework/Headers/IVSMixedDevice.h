//
// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
//

#import <Foundation/Foundation.h>
#import <AmazonIVSBroadcast/IVSBase.h>

NS_ASSUME_NONNULL_BEGIN

/// A mixed device is a device that can accept multiple input sources to be mixed together to produce a final output.
/// A single `IVSMixedDevice` instance will be either all audio or all video sources, and the sources and
/// configurations attached will be of the same type. A mixed device with no inputs sources will still produce output,
/// but the output will be a a black image or silent audio, depending on the mixed device type.
///
/// A mixed device can be attached to an `IVSBroadcastSession` via `attachDevice` or to an `IVSStage` by wrapping it
/// in a `IVSLocalStageStream`.
IVS_EXPORT
@protocol IVSMixedDevice

@end

NS_ASSUME_NONNULL_END
