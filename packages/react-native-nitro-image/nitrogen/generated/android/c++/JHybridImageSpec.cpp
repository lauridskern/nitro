///
/// JHybridImageSpec.cpp
/// Mon Aug 19 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/react-native-nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#include "JHybridImageSpec.hpp"

// Forward declaration of `ImageSize` to properly resolve imports.
namespace margelo::nitro::image { struct ImageSize; }
// Forward declaration of `PixelFormat` to properly resolve imports.
namespace margelo::nitro::image { enum class PixelFormat; }
// Forward declaration of `ImageFormat` to properly resolve imports.
namespace margelo::nitro::image { enum class ImageFormat; }

#include "ImageSize.hpp"
#include "JImageSize.hpp"
#include "PixelFormat.hpp"
#include "JPixelFormat.hpp"
#include "ImageFormat.hpp"
#include "JImageFormat.hpp"
#include <string>
#include <functional>
#include "JFunc_void_std__string.hpp"

namespace margelo::nitro::image {

  jni::local_ref<JHybridImageSpec::jhybriddata> JHybridImageSpec::initHybrid(jni::alias_ref<jhybridobject> jThis) {
    return makeCxxInstance(jThis);
  }

  void JHybridImageSpec::registerNatives() {
    registerHybrid({
      makeNativeMethod("initHybrid", JHybridImageSpec::initHybrid),
    });
  }

  size_t JHybridImageSpec::getExternalMemorySize() noexcept {
    static const auto method = _javaPart->getClass()->getMethod<jlong()>("getMemorySize");
    return method(_javaPart);
  }

  // Properties
  ImageSize JHybridImageSpec::getSize() {
    static const auto method = _javaPart->getClass()->getMethod<jni::alias_ref<JImageSize>()>("getSize");
    auto result = method(_javaPart);
    return result->toCpp();
  }
  PixelFormat JHybridImageSpec::getPixelFormat() {
    static const auto method = _javaPart->getClass()->getMethod<jni::alias_ref<JPixelFormat>()>("getPixelFormat");
    auto result = method(_javaPart);
    return result->toCpp();
  }
  double JHybridImageSpec::getSomeSettableProp() {
    static const auto method = _javaPart->getClass()->getMethod<double()>("getSomeSettableProp");
    auto result = method(_javaPart);
    return result;
  }
  void JHybridImageSpec::setSomeSettableProp(double someSettableProp) {
    static const auto method = _javaPart->getClass()->getMethod<void(double /* someSettableProp */)>("setSomeSettableProp");
    method(_javaPart, someSettableProp);
  }

  // Methods
  double JHybridImageSpec::toArrayBuffer(ImageFormat format) {
    static const auto method = _javaPart->getClass()->getMethod<double(jni::alias_ref<JImageFormat> /* format */)>("toArrayBuffer");
    auto result = method(_javaPart, JImageFormat::fromCpp(format));
    return result;
  }
  void JHybridImageSpec::saveToFile(const std::string& path, const std::function<void(const std::string& /* path */)>& onFinished) {
    static const auto method = _javaPart->getClass()->getMethod<void(std::string /* path */, jni::alias_ref<JFunc_void_std__string::javaobject> /* onFinished */)>("saveToFile");
    method(_javaPart, path, JFunc_void_std__string::fromCpp(onFinished));
  }

} // namespace margelo::nitro::image
