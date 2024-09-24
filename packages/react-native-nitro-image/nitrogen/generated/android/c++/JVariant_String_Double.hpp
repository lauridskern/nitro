///
/// JVariant_String_Double.hpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#pragma once

#include <fbjni/fbjni.h>
#include <variant>

namespace margelo::nitro::image {

  using namespace facebook;

  class SomeString;
  class SomeDouble;

  /**
   * The C++ JNI bridge between the C++ std::variant and the Java class "Variant_String_Double".
   */
  class JVariant_String_Double: public jni::JavaClass<JVariant_String_Double> {
  public:
    static auto constexpr kJavaDescriptor = "Lcom/margelo/nitro/image/Variant_String_Double;";

    static jni::local_ref<JVariant_String_Double> create(jni::alias_ref<jni::JString> value) {
      static const auto method = javaClassStatic()->getStaticMethod<JVariant_String_Double(jni::alias_ref<jni::JString>)>("create");
      return method(javaClassStatic(), value);
    }
    static jni::local_ref<JVariant_String_Double> create(double value) {
      static const auto method = javaClassStatic()->getStaticMethod<JVariant_String_Double(double)>("create");
      return method(javaClassStatic(), value);
    }

    static jni::local_ref<JVariant_String_Double> create(const std::variant<std::string, double>& variant) {
      switch (variant.index()) {
        case 0: return create(jni::make_jstring(std::get<0>(variant)));
        case 1: return create(std::get<1>(variant));
        default: throw std::runtime_error("Variant holds unknown index! (" + std::to_string(variant.index()) + ")");
      }
    }

    static std::variant<std::string, double> getVariant(jni::alias_ref<JVariant_String_Double> kotlinVariant);
  };

  class SomeString: public jni::JavaClass<SomeString, JVariant_String_Double> {
  public:
    static auto constexpr kJavaDescriptor = "Lcom/margelo/nitro/image/Variant_String_Double$SomeString;";
  
    jni::local_ref<jni::JString> get() {
      static const auto field = javaClassStatic()->getField<jni::JString>("value");
      return getFieldValue(field);
    }
  };
  
  class SomeDouble: public jni::JavaClass<SomeDouble, JVariant_String_Double> {
  public:
    static auto constexpr kJavaDescriptor = "Lcom/margelo/nitro/image/Variant_String_Double$SomeDouble;";
  
    double get() {
      static const auto field = javaClassStatic()->getField<double>("value");
      return getFieldValue(field);
    }
  };

  std::variant<std::string, double> JVariant_String_Double::getVariant(jni::alias_ref<JVariant_String_Double> kotlinVariant) {
    if (kotlinVariant->isInstanceOf(SomeString::javaClassStatic())) {
      auto jniValue = jni::static_ref_cast<SomeString>(kotlinVariant)->get();
      return jniValue->toStdString();
    } else if (kotlinVariant->isInstanceOf(SomeDouble::javaClassStatic())) {
      auto jniValue = jni::static_ref_cast<SomeDouble>(kotlinVariant)->get();
      return jniValue;
    }
    throw std::runtime_error("Variant is unknown Kotlin instance!");
  }

} // namespace margelo::nitro::image
