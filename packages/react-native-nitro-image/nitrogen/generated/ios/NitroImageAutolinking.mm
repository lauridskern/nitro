///
/// NitroImageAutolinking.mm
/// Thu Sep 12 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#import <Foundation/Foundation.h>
#import <NitroModules/HybridObjectRegistry.hpp>
#import "NitroImage-Swift-Cxx-Umbrella.hpp"
#import <type_traits>

#include "HybridImageFactorySpecSwift.hpp"
#include "HybridTestObject.hpp"
#include "HybridSwiftKotlinTestObjectSpecSwift.hpp"

@interface NitroImageAutolinking : NSObject
@end

@implementation NitroImageAutolinking

+ (void) load {
  using namespace margelo::nitro;
  using namespace margelo::nitro::image;

  HybridObjectRegistry::registerHybridObjectConstructor(
    "ImageFactory",
    []() -> std::shared_ptr<HybridObject> {
      auto swiftPart = NitroImage::NitroImageAutolinking::createImageFactory();
      return std::make_shared<HybridImageFactorySpecSwift>(swiftPart);
    }
  );
  HybridObjectRegistry::registerHybridObjectConstructor(
    "TestObject",
    []() -> std::shared_ptr<HybridObject> {
      static_assert(std::is_default_constructible_v<HybridTestObject>,
                    "The HybridObject \"HybridTestObject\" is not default-constructible! "
                    "Create a public constructor that takes zero arguments to be able to autolink this HybridObject.");
      return std::make_shared<HybridTestObject>();
    }
  );
  HybridObjectRegistry::registerHybridObjectConstructor(
    "SwiftKotlinTestObject",
    []() -> std::shared_ptr<HybridObject> {
      auto swiftPart = NitroImage::NitroImageAutolinking::createSwiftKotlinTestObject();
      return std::make_shared<HybridSwiftKotlinTestObjectSpecSwift>(swiftPart);
    }
  );
}

@end
