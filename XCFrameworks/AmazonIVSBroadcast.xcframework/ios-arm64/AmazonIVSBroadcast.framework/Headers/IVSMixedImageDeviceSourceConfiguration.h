//
// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
//

#import <Foundation/Foundation.h>
#import <AmazonIVSBroadcast/IVSBase.h>
#import <AmazonIVSBroadcast/IVSBroadcastConfiguration.h>

NS_ASSUME_NONNULL_BEGIN

/// Configuration for an `IVSMixedImageDeviceSource`.
IVS_EXPORT
@interface IVSMixedImageDeviceSourceConfiguration : NSObject

/// The aspect ratio of the associated source.
///
/// By default this is `IVSAspectMode.Fit`.
@property (nonatomic) IVSAspectMode aspect;

/// The position of the associated source.
/// By default this is `0x0`
@property (nonatomic) CGPoint position;

/// The size for the associated source. If the associated source provides samples that don't match this
/// size, they will be scaled based on the `aspect` value set on this configuration.
///
/// By default this is `720x1280`.
@property (nonatomic) CGSize size;

/// The alpha for the associated source. 1 = fully opaque, 0 = fully transparent.
///
/// By default this is `1`.
@property (nonatomic, readonly) float alpha;

/// Sets the alpha for the associated source. 1 = fully opaque, 0 = fully transparent
/// The value must be between 0 and 1 and `IVSMixedImageDevice` must have been created with `transparencyEnabled`
/// set to `YES`, otherwise alpha will not be set and the provided outError will be set.
///
/// @note For alpha to work, the `IVSMixedImageDevice` that the associated source is attached to must
/// have been created with `transparencyEnabled` set to `YES`.
///
/// @param alpha The alpha of the associated source.
/// @param outError On input, a pointer to an error object. If an error occurs, the pointer is an NSError object that describes the error. If you don’t want error information, pass in nil.
/// @return if the set operation is successful or not.
- (BOOL)setAlpha:(float)alpha error:(NSError *__autoreleasing *)outError;

/// The z-index of the associated source. Higher values are rendered on top of lower values.
/// By default this is `0`.
@property (nonatomic) NSInteger zIndex;

/// The fill color for content that is not used by media samples from the device attached to the associated source.
/// For example, if a 4:3 device is attached to a 16:9 source, this fill color will be used as the background color
/// for the letterboxing based on the `aspect` value.
///
/// By default this is `UIColor.clear`.
@property (nonatomic, strong) UIColor *fillColor;

@end

NS_ASSUME_NONNULL_END
