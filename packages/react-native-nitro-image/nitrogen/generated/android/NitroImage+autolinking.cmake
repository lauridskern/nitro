#
# NitroImage+autolinking.cmake
# Wed Aug 28 2024
# This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
# https://github.com/mrousavy/nitro
# Copyright © 2024 Marc Rousavy @ Margelo
#

# This is a CMake file that adds all files generated by Nitrogen
# to the current CMake project.
#
# To use it, add this to your CMakeLists.txt:
# ```cmake
# include(${CMAKE_SOURCE_DIR}/../nitrogen/generated/android/NitroImage+autolinking.cmake)
# ```

# Add all headers that were generated by Nitrogen
include_directories(
  "../nitrogen/generated/shared/c++"
  "../nitrogen/generated/android/c++"
)

# Add all .cpp sources that were generated by Nitrogen
target_sources(
  # CMake project name (Android C++ library name)
  NitroImage PRIVATE
  # Shared Nitrogen C++ sources
  ../nitrogen/generated/shared/c++/HybridImageSpec.cpp
  ../nitrogen/generated/shared/c++/HybridImageFactorySpec.cpp
  ../nitrogen/generated/shared/c++/HybridTestObjectSpec.cpp
  ../nitrogen/generated/shared/c++/HybridSwiftKotlinTestObjectSpec.cpp
  ../nitrogen/generated/shared/c++/HybridKotlinTestObjectSpec.cpp
  # Android-specific Nitrogen C++ sources
  ../nitrogen/generated/android/c++/JHybridImageSpec.cpp
  ../nitrogen/generated/android/c++/JHybridImageFactorySpec.cpp
  ../nitrogen/generated/android/c++/JHybridKotlinTestObjectSpec.cpp
)

# Add all libraries required by the generated specs
find_package(fbjni REQUIRED) # <-- Used for communication between Java <-> C++
find_package(ReactAndroid REQUIRED) # <-- Used to set up React Native bindings (e.g. CallInvoker/TurboModule)
find_package(react-native-nitro-modules REQUIRED) # <-- Used to create all HybridObjects and use the Nitro core library

# Link all libraries together
target_link_libraries(
        NitroImage
        fbjni::fbjni                              # <-- Facebook C++ JNI helpers
        ReactAndroid::jsi                         # <-- RN: JSI
        ReactAndroid::react_nativemodule_core     # <-- RN: TurboModules Core
        react-native-nitro-modules::NitroModules  # <-- NitroModules Core :)
)
