///
/// HybridSwiftKotlinTestObjectSpec.cpp
/// Wed Aug 14 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/react-native-nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#include "HybridSwiftKotlinTestObjectSpec.hpp"

namespace margelo::nitro::image {

  void HybridSwiftKotlinTestObjectSpec::loadHybridMethods() {
    // load base methods/properties
    HybridObject::loadHybridMethods();
    // load custom methods/properties
    registerHybrids(this, [](Prototype& prototype) {
      prototype.registerHybridGetter("numberValue", &HybridSwiftKotlinTestObjectSpec::getNumberValue);
      prototype.registerHybridSetter("numberValue", &HybridSwiftKotlinTestObjectSpec::setNumberValue);
      prototype.registerHybridGetter("boolValue", &HybridSwiftKotlinTestObjectSpec::getBoolValue);
      prototype.registerHybridSetter("boolValue", &HybridSwiftKotlinTestObjectSpec::setBoolValue);
      prototype.registerHybridGetter("stringValue", &HybridSwiftKotlinTestObjectSpec::getStringValue);
      prototype.registerHybridSetter("stringValue", &HybridSwiftKotlinTestObjectSpec::setStringValue);
      prototype.registerHybridGetter("bigintValue", &HybridSwiftKotlinTestObjectSpec::getBigintValue);
      prototype.registerHybridSetter("bigintValue", &HybridSwiftKotlinTestObjectSpec::setBigintValue);
      prototype.registerHybridGetter("stringOrUndefined", &HybridSwiftKotlinTestObjectSpec::getStringOrUndefined);
      prototype.registerHybridSetter("stringOrUndefined", &HybridSwiftKotlinTestObjectSpec::setStringOrUndefined);
      prototype.registerHybridGetter("stringOrNull", &HybridSwiftKotlinTestObjectSpec::getStringOrNull);
      prototype.registerHybridSetter("stringOrNull", &HybridSwiftKotlinTestObjectSpec::setStringOrNull);
      prototype.registerHybridGetter("optionalString", &HybridSwiftKotlinTestObjectSpec::getOptionalString);
      prototype.registerHybridSetter("optionalString", &HybridSwiftKotlinTestObjectSpec::setOptionalString);
      prototype.registerHybridGetter("someMap", &HybridSwiftKotlinTestObjectSpec::getSomeMap);
      prototype.registerHybridSetter("someMap", &HybridSwiftKotlinTestObjectSpec::setSomeMap);
      prototype.registerHybridGetter("someArray", &HybridSwiftKotlinTestObjectSpec::getSomeArray);
      prototype.registerHybridSetter("someArray", &HybridSwiftKotlinTestObjectSpec::setSomeArray);
      prototype.registerHybridGetter("someOptional", &HybridSwiftKotlinTestObjectSpec::getSomeOptional);
      prototype.registerHybridSetter("someOptional", &HybridSwiftKotlinTestObjectSpec::setSomeOptional);
      prototype.registerHybridGetter("car", &HybridSwiftKotlinTestObjectSpec::getCar);
      prototype.registerHybridSetter("car", &HybridSwiftKotlinTestObjectSpec::setCar);
      prototype.registerHybridGetter("powertrain", &HybridSwiftKotlinTestObjectSpec::getPowertrain);
      prototype.registerHybridSetter("powertrain", &HybridSwiftKotlinTestObjectSpec::setPowertrain);
      prototype.registerHybridGetter("oldEnum", &HybridSwiftKotlinTestObjectSpec::getOldEnum);
      prototype.registerHybridSetter("oldEnum", &HybridSwiftKotlinTestObjectSpec::setOldEnum);
      prototype.registerHybridGetter("buffer", &HybridSwiftKotlinTestObjectSpec::getBuffer);
      prototype.registerHybridSetter("buffer", &HybridSwiftKotlinTestObjectSpec::setBuffer);
      prototype.registerHybridMethod("simpleFunc", &HybridSwiftKotlinTestObjectSpec::simpleFunc);
      prototype.registerHybridMethod("addNumbers", &HybridSwiftKotlinTestObjectSpec::addNumbers);
      prototype.registerHybridMethod("addStrings", &HybridSwiftKotlinTestObjectSpec::addStrings);
      prototype.registerHybridMethod("multipleArguments", &HybridSwiftKotlinTestObjectSpec::multipleArguments);
      prototype.registerHybridMethod("getNumbers", &HybridSwiftKotlinTestObjectSpec::getNumbers);
      prototype.registerHybridMethod("getStrings", &HybridSwiftKotlinTestObjectSpec::getStrings);
      prototype.registerHybridMethod("callCallback", &HybridSwiftKotlinTestObjectSpec::callCallback);
      prototype.registerHybridMethod("createNewBuffer", &HybridSwiftKotlinTestObjectSpec::createNewBuffer);
      prototype.registerHybridMethod("newTestObject", &HybridSwiftKotlinTestObjectSpec::newTestObject);
      prototype.registerHybridMethod("bounceBack", &HybridSwiftKotlinTestObjectSpec::bounceBack);
    });
  }

} // namespace margelo::nitro::image
