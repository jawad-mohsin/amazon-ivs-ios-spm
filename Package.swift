// swift-tools-version:5.7
import PackageDescription

let package = Package(
    name: "AmazonIVS",
    platforms: [
        .iOS(.v14),
    ],
    products: [
        .library(
            name: "AmazonIVSPlayer",
            targets: ["AmazonIVSPlayerTarget"]
        ),
        .library(
            name: "AmazonIVSBroadcast",
            targets: ["AmazonIVSBroadcastTarget"]
        ),
    ],
    targets: [
        // Wrapper targets
        .target(
            name: "AmazonIVSPlayerTarget",
            dependencies: [
                .target(name: "AmazonIVSPlayer")
            ],
            path: "Sources/IVSPlayer"
        ),
        .target(
            name: "AmazonIVSBroadcastTarget",
            dependencies: [
                .target(name: "AmazonIVSBroadcast")
            ],
            path: "Sources/IVSBroadcast"
        ),
        
        // Binary targets
        .binaryTarget(
            name: "AmazonIVSPlayer",
            url: "https://player.live-video.net/1.37.0/AmazonIVSPlayer.xcframework.zip",
            checksum: "5f2dcd7a18a61cf149cea60dcb7e92cc5b01ede3c29ad7857967cea1ba418697"
        ),
        .binaryTarget(
            name: "AmazonIVSBroadcast",
            path: "XCFrameworks/AmazonIVSBroadcast.xcframework"
        ),
    ]
)
