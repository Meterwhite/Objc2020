Pod::Spec.new do |s|
  s.name         = "ObjC2020"
  s.version      = "1.0"
  s.summary      = 'A versatile Objective-C macro language.'
  s.homepage     = 'https://github.com/Meterwhite/ObjC2020'
  s.license      = 'MIT'
  s.author       = { "meterwhite" => "meterwhite@outlook.com" }
  s.requires_arc = true
  s.source       = { :git => "https://github.com/Meterwhite/ObjC2020.git", :tag => s.version}
  s.source_files  = 'ObjC2020/*.{h,m}'
end
