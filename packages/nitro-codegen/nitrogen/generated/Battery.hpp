

///
/// Battery.hpp
/// Sat Jul 13 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/react-native-nitro
///


#pragma once

#include <stddef.h>
#include <string.h>
#include <optional>
#include <NitroModules/JSIConverter.hpp>

struct Battery {
public:
  double capacity;
};

namespace margelo {

// Battery <> Battery
template <> struct JSIConverter<Battery> {
  static Battery fromJSI(jsi::Runtime& runtime, const jsi::Value& arg) {
    jsi::Object obj = arg.asObject(runtime);
    return Battery {
      .capacity = JSIConverter<double>::fromJSI(runtime, obj.getProperty(runtime, "capacity")),
    };
  }
  static jsi::Value toJSI(jsi::Runtime& runtime, const Battery& arg) {
    jsi::Object obj(runtime);
    obj.setProperty(runtime, "capacity", JSIConverter<double>::toJSI(runtime, arg.capacity));
    return obj;
  }
};

} // namespace margelo
        