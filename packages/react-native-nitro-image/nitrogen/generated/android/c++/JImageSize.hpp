///
/// JImageSize.hpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#pragma once

#include <fbjni/fbjni.h>
#include "ImageSize.hpp"
#include <NitroModules/JSIConverter.hpp>
#include <NitroModules/JSIConverter+JNI.hpp>



namespace margelo::nitro::image {

  using namespace facebook;

  /**
   * The C++ JNI bridge between the C++ struct "ImageSize" and the the Kotlin data class "ImageSize".
   */
  struct JImageSize final: public jni::JavaClass<JImageSize> {
  public:
    static auto constexpr kJavaDescriptor = "Lcom/margelo/nitro/image/ImageSize;";

  public:
    /**
     * Create a Java/Kotlin-based struct by copying all values from the given C++ struct to Java.
     */
    [[maybe_unused]]
    static jni::local_ref<JImageSize::javaobject> fromCpp(const ImageSize& value) {
      return newInstance(
        value.width,
        value.height
      );
    }

    /**
     * Create a Java/Kotlin-based struct from the given Java values.
     */
    static jni::local_ref<JImageSize::javaobject> create(double width,
                                                         double height) {
      return newInstance(
        width,
        height
      );
    }

  public:
    /**
     * Convert this Java/Kotlin-based struct to the C++ struct ImageSize by copying all values to C++.
     */
    [[maybe_unused]]
    [[nodiscard]] ImageSize toCpp() const {
      static const auto clazz = javaClassStatic();
      static const auto fieldWidth = clazz->getField<double>("width");
      double width = this->getFieldValue(fieldWidth);
      static const auto fieldHeight = clazz->getField<double>("height");
      double height = this->getFieldValue(fieldHeight);
      return ImageSize(
        width,
        height
      );
    }

  public:
    [[nodiscard]] double getWidth() const {
      static const auto field = javaClassStatic()->getField<double>("width");
      return this->getFieldValue(field);
    }
    
    [[nodiscard]] double getHeight() const {
      static const auto field = javaClassStatic()->getField<double>("height");
      return this->getFieldValue(field);
    }
  };

} // namespace margelo::nitro::image

namespace margelo::nitro {

  using namespace margelo::nitro::image;

  // C++/JNI JImageSize <> JS ImageSize (object)
  template <>
  struct JSIConverter<JImageSize> {
    static inline jni::local_ref<JImageSize> fromJSI(jsi::Runtime& runtime, const jsi::Value& arg) {
      jsi::Object obj = arg.asObject(runtime);
      return JImageSize::create(
        JSIConverter<double>::fromJSI(runtime, obj.getProperty(runtime, "width")),
        JSIConverter<double>::fromJSI(runtime, obj.getProperty(runtime, "height"))
      );
    }
    static inline jsi::Value toJSI(jsi::Runtime& runtime, const jni::local_ref<JImageSize>& arg) {
      jsi::Object obj(runtime);
      obj.setProperty(runtime, "width", JSIConverter<double>::toJSI(runtime, arg->getWidth()));
      obj.setProperty(runtime, "height", JSIConverter<double>::toJSI(runtime, arg->getHeight()));
      return obj;
    }
    static inline bool canConvert(jsi::Runtime& runtime, const jsi::Value& value) {
      if (!value.isObject()) {
        return false;
      }
      jsi::Object obj = value.getObject(runtime);
      if (!JSIConverter<double>::canConvert(runtime, obj.getProperty(runtime, "width"))) return false;
      if (!JSIConverter<double>::canConvert(runtime, obj.getProperty(runtime, "height"))) return false;
      return true;
    }
  };

} // namespace margelo::nitro
