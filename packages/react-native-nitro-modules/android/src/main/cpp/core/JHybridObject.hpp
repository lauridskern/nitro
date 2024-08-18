//
//  JHybridObject.hpp
//  react-native-nitro
//
//  Created by Marc Rousavy on 14.07.24.
//

#pragma once

#include "HybridObject.hpp"
#include <fbjni/fbjni.h>

namespace margelo::nitro {

using namespace facebook;

struct JHybridObject : public jni::HybridClass<JHybridObject>, public virtual HybridObject {
public:
  static auto constexpr kJavaDescriptor = "Lcom/margelo/nitro/HybridObject;";

  explicit JHybridObject(const char* name): HybridObject(name) { }

  virtual ~JHybridObject() = default;

private:
  friend HybridBase;
};

} // namespace margelo::nitro
