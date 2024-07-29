///
/// HybridImage.kt
/// Mon Jul 29 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/react-native-nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

package com.margelo.nitro.image

import android.util.Log
import androidx.annotation.Keep
import com.facebook.jni.HybridData
import com.facebook.proguard.annotations.DoNotStrip
import com.margelo.nitro.HybridObject

/**
 * A Kotlin class representing the Image HybridObject.
 * Implement this abstract class to create Kotlin-based instances of Image.
 */
@DoNotStrip
@Keep
@Suppress("KotlinJniMissingFunction")
abstract class HybridImage: HybridObject {
  @DoNotStrip
  @Keep
  private val mHybridData: HybridData

  init {
    mHybridData = initHybrid()
  }

  private external fun initHybrid(): HybridData

  protected val TAG = "HybridImage"

  // Properties
  @get:DoNotStrip
  @get:Keep
  abstract val size: com.margelo.nitro.image.ImageSize
  
  @get:DoNotStrip
  @get:Keep
  abstract val pixelFormat: com.margelo.nitro.image.PixelFormat
  
  @get:DoNotStrip
  @get:Keep
  @set:DoNotStrip
  @set:Keep
  abstract var someSettableProp: Double

  // Methods
  @DoNotStrip
  @Keep
  abstract fun toArrayBuffer(format: com.margelo.nitro.image.ImageFormat): Double
  
  @DoNotStrip
  @Keep
  abstract fun saveToFile(path: String, onFinished: com.margelo.nitro.image.Func_void_std__string): Unit

  companion object {
    private const val TAG = "HybridImage"
    init {
      try {
        Log.i(TAG, "Loading NitroImage C++ library...")
        System.loadLibrary("NitroImage")
        Log.i(TAG, "Successfully loaded NitroImage C++ library!")
      } catch (e: Error) {
        Log.e(TAG, "Failed to load NitroImage C++ library! Is it properly installed and linked? " +
                    "Is the name correct? (see `CMakeLists.txt`, at `add_library(...)`)", e)
        throw e
      }
    }
  }
}