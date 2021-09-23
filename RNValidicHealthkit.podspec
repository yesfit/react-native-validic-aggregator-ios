require "json"

package = JSON.parse(File.read(File.join(__dir__, "package.json")))

Pod::Spec.new do |s|
  s.name         = "RNValidicHealthkit"
  s.version      = package["version"]
  s.summary      = package["description"]
  s.description  = <<-DESC
                  Healthkit integration for the Validic Mobile Platform
                   DESC
  s.homepage     = "https://validic.com"
  s.license      = { :file => "LICENSE" }
  s.author       = ["Validic Mobile"]
  s.platform     = :ios, "10.0"
  s.source       = { :http => 'file:' + __dir__ + '/'}

  s.source_files =  "ios/Classes/*.{h,m}"
  s.ios.vendored_frameworks = 'ios/ValidicHealthKit.xcframework'
  s.requires_arc = true

  s.dependency "React"
  s.dependency "RNValidicSession"
  #s.dependency "others"
end

