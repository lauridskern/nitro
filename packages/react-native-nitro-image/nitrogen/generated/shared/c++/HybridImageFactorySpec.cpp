///
/// HybridImageFactorySpec.cpp
/// Wed Aug 28 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#include "HybridImageFactorySpec.hpp"

namespace margelo::nitro::image {

  void HybridImageFactorySpec::loadHybridMethods() {
    // load base methods/properties
    HybridObject::loadHybridMethods();
    // load custom methods/properties
    registerHybrids(this, [](Prototype& prototype) {
      prototype.registerHybridMethod("loadImageFromFile", &HybridImageFactorySpec::loadImageFromFile);
      prototype.registerHybridMethod("loadImageFromURL", &HybridImageFactorySpec::loadImageFromURL);
      prototype.registerHybridMethod("loadImageFromSystemName", &HybridImageFactorySpec::loadImageFromSystemName);
      prototype.registerHybridMethod("bounceBack", &HybridImageFactorySpec::bounceBack);
    });
  }

} // namespace margelo::nitro::image
