///
/// HybridKotlinTestObjectSpec.cpp
/// Mon Aug 19 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/react-native-nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#include "HybridKotlinTestObjectSpec.hpp"

namespace margelo::nitro::image {

  void HybridKotlinTestObjectSpec::loadHybridMethods() {
    // load base methods/properties
    HybridObject::loadHybridMethods();
    // load custom methods/properties
    registerHybrids(this, [](Prototype& prototype) {
      prototype.registerHybridGetter("numberValue", &HybridKotlinTestObjectSpec::getNumberValue);
      prototype.registerHybridSetter("numberValue", &HybridKotlinTestObjectSpec::setNumberValue);
    });
  }

} // namespace margelo::nitro::image
