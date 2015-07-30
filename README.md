# LAS-StarterProject-iOS
LAS-StarterProject-iOS

## How to run

1. Clone the repository and open the Xcode project at `LAS-Demo-Auth-iOS/Auth.xcodeproj`.
2. Add your LAS application id and client key in `AppDelegate.m`.
3. Compile and Run.

## Test the SDK

First make sure to include our SDK libraries from your ViewController.h file:

```
#import <LAS/LAS.h>
```

Then copy and paste this code into your app, for example in the viewDidLoad method of `ViewController.m`.

```
LASObject *testObject = [LASObject objectWithClassName:@"TestObject"];
testObject[@"foo"] = @"bar";
[LASDataManager saveObjectInBackground:testObject block:nil];
```

Run your app. A new object of class `TestObject` will be sent to the LAS and saved.