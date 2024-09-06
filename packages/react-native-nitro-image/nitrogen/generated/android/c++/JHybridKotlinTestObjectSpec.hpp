///
/// HybridKotlinTestObjectSpec.hpp
/// Fri Sep 06 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#pragma once

#include <NitroModules/JHybridObject.hpp>
#include <fbjni/fbjni.h>
#include "HybridKotlinTestObjectSpec.hpp"

namespace margelo::nitro::image {

  using namespace facebook;

  class JHybridKotlinTestObjectSpec final: public jni::HybridClass<JHybridKotlinTestObjectSpec, JHybridObject>,
                                           public HybridKotlinTestObjectSpec {
  public:
    static auto constexpr kJavaDescriptor = "Lcom/margelo/nitro/image/HybridKotlinTestObjectSpec;";
    static jni::local_ref<jhybriddata> initHybrid(jni::alias_ref<jhybridobject> jThis);
    static void registerNatives();

  private:
    // C++ constructor (called from Java via `initHybrid()`)
    explicit JHybridKotlinTestObjectSpec(jni::alias_ref<jhybridobject> jThis) :
      HybridObject(HybridKotlinTestObjectSpec::TAG),
      _javaPart(jni::make_global(jThis)) {}

  public:
    size_t getExternalMemorySize() noexcept override;

  public:
    inline const jni::global_ref<JHybridKotlinTestObjectSpec::javaobject>& getJavaPart() const noexcept {
      return _javaPart;
    }

  public:
    // Properties
    double getNumberValue() override;
    void setNumberValue(double numberValue) override;
    std::optional<double> getOptionalNumber() override;
    void setOptionalNumber(std::optional<double> optionalNumber) override;
    std::vector<double> getPrimitiveArray() override;
    void setPrimitiveArray(const std::vector<double>& primitiveArray) override;
    std::vector<Car> getCarCollection() override;
    void setCarCollection(const std::vector<Car>& carCollection) override;
    std::shared_ptr<ArrayBuffer> getSomeBuffer() override;
    void setSomeBuffer(const std::shared_ptr<ArrayBuffer>& someBuffer) override;
    std::unordered_map<std::string, std::string> getSomeRecord() override;
    void setSomeRecord(const std::unordered_map<std::string, std::string>& someRecord) override;

  public:
    // Methods
    std::future<void> asyncTest() override;
    std::shared_ptr<AnyMap> createMap() override;
    void addOnPersonBornListener(const std::function<void(const Person& /* p */)>& callback) override;

  private:
    friend HybridBase;
    using HybridBase::HybridBase;
    jni::global_ref<JHybridKotlinTestObjectSpec::javaobject> _javaPart;
  };

} // namespace margelo::nitro::image
