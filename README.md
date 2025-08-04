# Amazon IVS iOS SDK - Swift Package Manager

This package provides Swift Package Manager support for Amazon IVS iOS SDKs.

## 📦 Included SDKs

- ✅ **Amazon IVS Player SDK** v1.37.0 - For video playback
- ✅ **Amazon IVS Broadcast SDK** v1.32.1 - For live streaming

## 📋 Requirements

- iOS 14.0+
- Xcode 13.0+
- Swift 5.5+

## 🚀 Installation

### Swift Package Manager

1. In Xcode, go to **File** → **Add Package Dependencies...**
2. Enter this repository URL: `https://github.com/YOUR_USERNAME/amazon-ivs-ios-spm`
3. Choose version (e.g., "Up to Next Major Version" from 1.0.0)
4. Select the products you need:
   - `AmazonIVSPlayer` - For playback functionality
   - `AmazonIVSBroadcast` - For broadcasting functionality

## 💻 Usage

### Player SDK

```swift
import AmazonIVSPlayer

class PlayerViewController: UIViewController {
    @IBOutlet weak var playerView: IVSPlayerView!
    private let player = IVSPlayer()
    
    override func viewDidLoad() {
cat > README.md << 'EOF'
# Amazon IVS iOS SDK - Swift Package Manager

This package provides Swift Package Manager support for Amazon IVS iOS SDKs.

## 📦 Included SDKs

- ✅ **Amazon IVS Player SDK** v1.37.0 - For video playback
- ✅ **Amazon IVS Broadcast SDK** v1.32.1 - For live streaming

## 📋 Requirements

- iOS 14.0+
- Xcode 13.0+
- Swift 5.5+

## 🚀 Installation

### Swift Package Manager

1. In Xcode, go to **File** → **Add Package Dependencies...**
2. Enter this repository URL: `https://github.com/YOUR_USERNAME/amazon-ivs-ios-spm`
3. Choose version (e.g., "Up to Next Major Version" from 1.0.0)
4. Select the products you need:
   - `AmazonIVSPlayer` - For playback functionality
   - `AmazonIVSBroadcast` - For broadcasting functionality

### Alternative Installation

If you prefer to use specific versions in your `Package.swift`:

```swift
dependencies: [
    .package(url: "https://github.com/YOUR_USERNAME/amazon-ivs-ios-spm", from: "1.0.0")
],
targets: [
    .target(
        name: "YourApp",
        dependencies: [
            .product(name: "AmazonIVSPlayer", package: "amazon-ivs-ios-spm"),
            .product(name: "AmazonIVSBroadcast", package: "amazon-ivs-ios-spm")
        ]
    )
]
