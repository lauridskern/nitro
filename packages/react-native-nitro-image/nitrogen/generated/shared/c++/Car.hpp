///
/// Car.hpp
/// Fri Aug 16 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/react-native-nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#pragma once

#if __has_include(<NitroModules/JSIConverter.hpp>)
#include <NitroModules/JSIConverter.hpp>
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif
#if __has_include(<NitroModules/NitroDefines.hpp>)
#include <NitroModules/NitroDefines.hpp>
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif

// Forward declaration of `Powertrain` to properly resolve imports.
namespace margelo::nitro::image { enum class Powertrain; }
// Forward declaration of `Person` to properly resolve imports.
namespace margelo::nitro::image { struct Person; }

#include <string>
#include "Powertrain.hpp"
#include <optional>
#include "Person.hpp"

namespace margelo::nitro::image {

  /**
   * A struct which can be represented as a JavaScript object (Car).
   */
  struct Car {
  public:
    double year     SWIFT_PRIVATE;
    std::string make     SWIFT_PRIVATE;
    std::string model     SWIFT_PRIVATE;
    double power     SWIFT_PRIVATE;
    Powertrain powertrain     SWIFT_PRIVATE;
    std::optional<Person> driver     SWIFT_PRIVATE;

  public:
    explicit Car(double year, std::string make, std::string model, double power, Powertrain powertrain, std::optional<Person> driver): year(year), make(make), model(model), power(power), powertrain(powertrain), driver(driver) {}
  };

} // namespace margelo::nitro::image

namespace margelo::nitro {

  using namespace margelo::nitro::image;

  // C++ Car <> JS Car (object)
  template <>
  struct JSIConverter<Car> {
    static inline Car fromJSI(jsi::Runtime& runtime, const jsi::Value& arg) {
      jsi::Object obj = arg.asObject(runtime);
      return Car(
        JSIConverter<double>::fromJSI(runtime, obj.getProperty(runtime, "year")),
        JSIConverter<std::string>::fromJSI(runtime, obj.getProperty(runtime, "make")),
        JSIConverter<std::string>::fromJSI(runtime, obj.getProperty(runtime, "model")),
        JSIConverter<double>::fromJSI(runtime, obj.getProperty(runtime, "power")),
        JSIConverter<Powertrain>::fromJSI(runtime, obj.getProperty(runtime, "powertrain")),
        JSIConverter<std::optional<Person>>::fromJSI(runtime, obj.getProperty(runtime, "driver"))
      );
    }
    static inline jsi::Value toJSI(jsi::Runtime& runtime, const Car& arg) {
      jsi::Object obj(runtime);
      obj.setProperty(runtime, "year", JSIConverter<double>::toJSI(runtime, arg.year));
      obj.setProperty(runtime, "make", JSIConverter<std::string>::toJSI(runtime, arg.make));
      obj.setProperty(runtime, "model", JSIConverter<std::string>::toJSI(runtime, arg.model));
      obj.setProperty(runtime, "power", JSIConverter<double>::toJSI(runtime, arg.power));
      obj.setProperty(runtime, "powertrain", JSIConverter<Powertrain>::toJSI(runtime, arg.powertrain));
      obj.setProperty(runtime, "driver", JSIConverter<std::optional<Person>>::toJSI(runtime, arg.driver));
      return obj;
    }
    static inline bool canConvert(jsi::Runtime& runtime, const jsi::Value& value) {
      if (!value.isObject()) {
        return false;
      }
      jsi::Object obj = value.getObject(runtime);
      if (!JSIConverter<double>::canConvert(runtime, obj.getProperty(runtime, "year"))) return false;
      if (!JSIConverter<std::string>::canConvert(runtime, obj.getProperty(runtime, "make"))) return false;
      if (!JSIConverter<std::string>::canConvert(runtime, obj.getProperty(runtime, "model"))) return false;
      if (!JSIConverter<double>::canConvert(runtime, obj.getProperty(runtime, "power"))) return false;
      if (!JSIConverter<Powertrain>::canConvert(runtime, obj.getProperty(runtime, "powertrain"))) return false;
      if (!JSIConverter<std::optional<Person>>::canConvert(runtime, obj.getProperty(runtime, "driver"))) return false;
      return true;
    }
  };

} // namespace margelo::nitro
