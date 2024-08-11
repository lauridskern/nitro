///
/// HybridSwiftKotlinTestObjectSpec.hpp
/// Sun Aug 11 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/react-native-nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#pragma once

#if __has_include(<NitroModules/HybridObject.hpp>)
#include <NitroModules/HybridObject.hpp>
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif





namespace margelo::nitro::image {

  using namespace margelo::nitro;

  /**
   * An abstract base class for `SwiftKotlinTestObject`
   * Inherit this class to create instances of `HybridSwiftKotlinTestObjectSpec` in C++.
   * @example
   * ```cpp
   * class HybridSwiftKotlinTestObject: public HybridSwiftKotlinTestObjectSpec {
   *   // ...
   * };
   * ```
   */
  class HybridSwiftKotlinTestObjectSpec: public HybridObject {
    public:
      // Constructor
      explicit HybridSwiftKotlinTestObjectSpec(): HybridObject(TAG) { }

      // Destructor
      ~HybridSwiftKotlinTestObjectSpec() { }

    public:
      // Properties
      

    public:
      // Methods
      virtual void hallo(std::optional<double> value) = 0;

    protected:
      // Hybrid Setup
      void loadHybridMethods() override;

    protected:
      // Tag for logging
      static constexpr auto TAG = "SwiftKotlinTestObject";
  };

} // namespace margelo::nitro::image
