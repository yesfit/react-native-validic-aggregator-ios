- [Getting started](#getting-started)
  - [Linking](#linking)
    - [Automatic](#automatic)
    - [Manual](#manual)
  - [Enable HealthKit](#enable-healthkit)
    - [Permission Usage Descriptions](#permission-usage-descriptions)
- [Usage](#usage)
  - [Subscriptions](#subscriptions)
    - [Set Subscriptions](#set-subscriptions)
    - [Current Subscriptions](#current-subscriptions)


## Getting started

```shell
$ npm install react-native-validic-aggregator-ios --save`
```
or use yarn

```shell
$ yarn add react-native-validic-aggregator-ios`
```

### Linking 

#### Automatic

```shell
react-native link react-native-validic-aggregator-ios
```

_For iOS users using Pods_
You still need to run `pod install` after running the above link command inside your `IOS` folder.

#### Manual

<details>
    <summary>iOS (via CocoaPods) RN >= 60</summary>

Add the following lines to your build targets in your `Podfile`

```ruby
pod 'React', :path => '../node_modules/react-native'

pod 'RNValidicHealthkit', :path => '../node_modules/react-native-validic-aggregator-ios'
pod 'RNValidicSession', :path= => '../node_modules/react-native-validic-session'

```

Then run `pod install`

</details>


<details>
    <summary>iOS (without CocoaPods)</summary>

In XCode, in the project navigator:

- Right click _Libraries_
- Add Files to _[your project's name]_
- Go to `node_modules/react-native-validic-aggregator-ios/ios`
- Add the file `RNValidicHealthkit.xcodeproj`

In XCode, in the project navigator, select your project.

- Add the `libRNValidicHealthkit.a` from the _RNValidicHealthkit_ project to your project's _Build Phases ➜ Link Binary With Libraries_
- Click `.xcodeproj` file you added before in the project navigator and go the _Build Settings_ tab. Make sure _All_ is toggled on (instead of _Basic_).
- Look for _Header Search Paths_ and make sure it contains both `$(SRCROOT)/../react-native/React` and `$(SRCROOT)/../../React`
- Mark both as recursive (should be OK by default).


 In the General tab there will be a panel at the bottom of the screen labeled "Embedded Binaries". You should see the frameworks added here.

![Linked Frameworks](img/Linked_Frameworks.png)

Next copy 'copy-validicmobile.rb' to the `ios` folder of your project.

Go to the build settings of your target. In the "Build Phases" tab add a new build phase by clicking the plus button at the top and selecting "New Run Script Phase".

![Build Phase](img/Build_Phase.png)

In the new phase's text area paste in `ruby copy-validicmobile.rb`.

![Copy Script](img/Copy_Script.png)

</details>


### Enable HealthKit
To enable use of HealthKit in the app, within the build settings of your target, select the 'Capabilities' tab and enable 'HealthKit'.

![HealthKit](img/HealthKit_Entitlements.png)

If HealthKit is not enabled, an error is reported in the console log on app launch but will not report a error during build.

#### Permission Usage Descriptions
Usage descriptions have to be declared in project's `Info.plist` for permissions of the Camera, Bluetooth and to access and update HealthKit data.

- HEALTH_SHARE_USAGE_DESCRIPTION for NSHealthShareUsageDescription
- HEALTH_UPDATE_USAGE_DESCRIPTION for NSHealthUpdateUsageDescription

## Usage
```javascript
import ValidicHealthKit from 'react-native-validic-aggregator-ios';
```
  
### Subscriptions 
To subscribe to HealthKit sample types:

#### Set Subscriptions
Calling `ValidicHealthKit.setSubscriptions(subscriptions)` will overwrite any existing subscriptions so it is important to always pass all of the subscriptions desired each time the method is called.
To get a list of the currently subscribed data types use the method described in [Current subscriptions](#Current_Subscriptions)

```js
ValidicHealthKit.setSubscriptions([ValidicHealthKit.SampleTypes.HKQuantityTypeIdentifierStepCount]);
```
The function accepts an array of strings mapping to HealthKit sample types. 

#### Current Subscriptions 
To retrieve the list of Sample Types currently being observed

```js
ValidicHealthKit.getCurrentSubscriptions((subscriptions)=>{
    if(!subscriptions.includes(ValidicHealthKit.SampleTypes.HKQuantityTypeIdentifierStepCount)){
        subscriptions.push(ValidicHealthKit.SampleTypes.HKQuantityTypeIdentifierStepCount);
        ValidicHealthKit.setSubscriptions(subscriptions);
    }
});
```

#### Events
An event will be passed to the `ValidicHealthKit.eventEmitter` every time Healthkit processes a record type in the background.
The event  will contain the count and type of record processed from healthkit. 

```js
ValidicHealthKit.eventEmitter.addListener('validic:healthkit:onrecords', (summary){
    console.log(summary.type) //type of record that corresponds to ValidicHealthKit.SummaryType
    console.log(summary.count) // count of how many records of the corresponding Summary Type were processed by HealthKit
})
```

Events should be removed as soon as they are no longer needed or the component observing them will be umounted

```js
componentWillUnmount(){
    ValidicHealthKit.eventEmitter.removeAllListeners('validic:healthkit:onrecords');
}
```
