//
// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
//

#import <Foundation/Foundation.h>
#import <AmazonIVSBroadcast/IVSBase.h>

NS_ASSUME_NONNULL_BEGIN

/// Configuration for an `IVSMixedImageDevice`.
IVS_EXPORT
@interface IVSMixedImageDeviceConfiguration : NSObject

/// The output size of this mixed image device.
///
/// By default this is `720x1280`.
@property (nonatomic) CGSize size;

/// Setting this to `YES` will enable transparency between the images from multiple sources at the cost of some memory usage.
///
/// For example, if you wanted to broadcast the rear facing camera taking up the entire view port, and then overlay the front facing camera
/// with 30% transparency so that you can still partially see the rear facing camera under the front facing camera, this property would need to be `YES`.
///
/// @note Enabling this option does increase the memory usage of the pipeline. If you are not going to use multiple sources with blending, leave this as `NO`.
///
/// By default this is `NO`.
@property (nonatomic, getter=isTransparencyEnabled) BOOL transparencyEnabled;

/// The target framerate of the output video stream.
/// This is how frequently the sources attached to this mixed device will have their
/// latest samples composited together according to their configurations.
///
/// By default this is `30`.
@property (nonatomic, readonly) NSInteger targetFramerate;

/// Sets the target framerate of the output video stream. This must be between 10 and 60
/// If the provided framerate falls outside this range, the framerate will not be set and the provided outError will be set.
/// @param targetFramerate The target framerate for the output video stream
/// @param outError On input, a pointer to an error object. If an error occurs, the pointer is an NSError object that describes the error. If you don’t want error information, pass in nil.
/// @return if the set operation is successful or not.
- (BOOL)setTargetFramerate:(NSInteger)targetFramerate error:(NSError *__autoreleasing *)outError;

@end

NS_ASSUME_NONNULL_END
