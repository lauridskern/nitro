//
//  NativeNitroModules.cpp
//  NitroModules
//
//  Created by Marc Rousavy on 21.06.24.
//

#include "NativeNitroModules.hpp"
#include "BoxedHybridObject.hpp"
#include "CallInvokerDispatcher.hpp"
#include "Dispatcher.hpp"
#include "HybridObjectRegistry.hpp"
#include "NitroDefines.hpp"

namespace facebook::react {

using namespace margelo::nitro;

NativeNitroModules::NativeNitroModules(std::shared_ptr<CallInvoker> jsInvoker)
    : TurboModule(kModuleName, jsInvoker), _callInvoker(jsInvoker) {}

jsi::Value NativeNitroModules::get(jsi::Runtime& runtime, const jsi::PropNameID& propName) {
  std::string name = propName.utf8(runtime);

  if (name == "install") {
    return jsi::Function::createFromHostFunction(
        runtime, jsi::PropNameID::forUtf8(runtime, "install"), 0,
        [this](jsi::Runtime& runtime, const jsi::Value& thisArg, const jsi::Value* args, size_t count) -> jsi::Value {
          install(runtime);
          return jsi::Value::undefined();
        });
  }
  if (name == "createHybridObject") {
    return jsi::Function::createFromHostFunction(
        runtime, jsi::PropNameID::forUtf8(runtime, "createHybridObject"), 1,
        [this](jsi::Runtime& runtime, const jsi::Value& thisArg, const jsi::Value* args, size_t count) -> jsi::Value {
#ifdef NITRO_DEBUG
          if (count != 1) [[unlikely]] {
            throw jsi::JSError(runtime,
                               "NitroModules.createHybridObject(..) expects 1 argument, but " + std::to_string(count) + " were supplied!");
          }
#endif
          jsi::String objectName = args[0].asString(runtime);
          return createHybridObject(runtime, objectName);
        });
  }
  if (name == "hasHybridObject") {
    return jsi::Function::createFromHostFunction(
        runtime, jsi::PropNameID::forUtf8(runtime, "hasHybridObject"), 1,
        [this](jsi::Runtime& runtime, const jsi::Value& thisArg, const jsi::Value* args, size_t count) -> jsi::Value {
#ifdef NITRO_DEBUG
          if (count != 1) [[unlikely]] {
            throw jsi::JSError(runtime,
                               "NitroModules.hasHybridObject(..) expects 1 argument (name), but received " + std::to_string(count) + "!");
          }
#endif
          jsi::String objectName = args[0].asString(runtime);
          return hasHybridObject(runtime, objectName);
        });
  }
  if (name == "getAllHybridObjectNames") {
    return jsi::Function::createFromHostFunction(runtime, jsi::PropNameID::forUtf8(runtime, "getAllHybridObjectNames"), 0,
                                                 [this](jsi::Runtime& runtime, const jsi::Value& thisArg, const jsi::Value* args,
                                                        size_t count) -> jsi::Value { return getAllHybridObjectNames(runtime); });
  }
  if (name == "hasNativeState") {
    return jsi::Function::createFromHostFunction(
        runtime, jsi::PropNameID::forUtf8(runtime, "hasNativeState"), 1,
        [](jsi::Runtime& runtime, const jsi::Value& thisArg, const jsi::Value* args, size_t count) -> jsi::Value {
          jsi::Object object = args[0].asObject(runtime);
          bool has = object.hasNativeState(runtime) && object.getNativeState(runtime) != nullptr;
          return jsi::Value(has);
        });
  }
  if (name == "removeNativeState") {
    return jsi::Function::createFromHostFunction(
        runtime, jsi::PropNameID::forUtf8(runtime, "removeNativeState"), 1,
        [](jsi::Runtime& runtime, const jsi::Value& thisArg, const jsi::Value* args, size_t count) -> jsi::Value {
          jsi::Object object = args[0].asObject(runtime);
          object.setNativeState(runtime, nullptr);
          return jsi::Value::undefined();
        });
  }
  if (name == "box") {
    return jsi::Function::createFromHostFunction(
        runtime, jsi::PropNameID::forUtf8(runtime, "box"), 1,
        [](jsi::Runtime& runtime, const jsi::Value& thisArg, const jsi::Value* args, size_t count) -> jsi::Value {
          jsi::Object object = args[0].asObject(runtime);
#ifdef NITRO_DEBUG
          if (!object.hasNativeState(runtime)) {
            std::string stringified = args[0].toString(runtime).utf8(runtime);
            throw std::runtime_error("Cannot box object " + stringified + " - it does not have a NativeState!");
          }
#endif

          std::shared_ptr<jsi::NativeState> nativeState = object.getNativeState(runtime);
          std::shared_ptr<HybridObject> maybeHybridObject = std::dynamic_pointer_cast<HybridObject>(nativeState);
          if (maybeHybridObject == nullptr) {
            std::string stringified = args[0].toString(runtime).utf8(runtime);
            throw std::runtime_error("Cannot box object " + stringified + " - it has a NativeState, but it's not a HybridObject!");
          }

          auto boxed = std::make_shared<BoxedHybridObject>(maybeHybridObject);
          return jsi::Object::createFromHostObject(runtime, boxed);
        });
  }
  if (name == "buildType") {
#ifdef NITRO_DEBUG
    return jsi::String::createFromAscii(runtime, "debug");
#else
    return jsi::String::createFromAscii(runtime, "release");
#endif
  }

  return jsi::Value::undefined();
}

void NativeNitroModules::install(jsi::Runtime& runtime) {
  // Installs the global Dispatcher mechanism into this Runtime.
  // This allows creating Promises and calling back to JS.
  auto dispatcher = std::make_shared<CallInvokerDispatcher>(_callInvoker);
  Dispatcher::installRuntimeGlobalDispatcher(runtime, dispatcher);
}

jsi::Value NativeNitroModules::createHybridObject(jsi::Runtime& runtime, const jsi::String& hybridObjectName) {
  auto name = hybridObjectName.utf8(runtime);
  auto hybridObject = HybridObjectRegistry::createHybridObject(name);
  return hybridObject->toObject(runtime);
}

jsi::Value NativeNitroModules::hasHybridObject(jsi::Runtime& runtime, const jsi::String& hybridObjectName) {
  std::string name = hybridObjectName.utf8(runtime);
  bool exists = HybridObjectRegistry::hasHybridObject(name);
  return exists;
}

jsi::Value NativeNitroModules::getAllHybridObjectNames(jsi::Runtime& runtime) {
  std::vector<std::string> keys = HybridObjectRegistry::getAllHybridObjectNames();
  jsi::Array array(runtime, keys.size());
  for (size_t i = 0; i < keys.size(); i++) {
    array.setValueAtIndex(runtime, i, jsi::String::createFromUtf8(runtime, keys[i]));
  }
  return array;
}

} // namespace facebook::react
