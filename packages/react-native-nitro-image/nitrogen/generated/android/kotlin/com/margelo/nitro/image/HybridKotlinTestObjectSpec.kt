///
/// HybridKotlinTestObjectSpec.kt
/// Tue Aug 27 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

package com.margelo.nitro.image

import android.util.Log
import androidx.annotation.Keep
import com.facebook.jni.HybridData
import com.facebook.proguard.annotations.DoNotStrip
import com.margelo.nitro.core.*

/**
 * A Kotlin class representing the KotlinTestObject HybridObject.
 * Implement this abstract class to create Kotlin-based instances of KotlinTestObject.
 */
@DoNotStrip
@Keep
@Suppress("KotlinJniMissingFunction")
abstract class HybridKotlinTestObjectSpec: HybridObject() {
  protected val TAG = "HybridKotlinTestObjectSpec"

  @DoNotStrip
  val mHybridData: HybridData = initHybrid()

  init {
    // Pass this `HybridData` through to it's base class,
    // to represent inheritance to JHybridObject on C++ side
    super.updateNative(mHybridData)
  }

  // Properties
  @get:DoNotStrip
  @get:Keep
  @set:DoNotStrip
  @set:Keep
  abstract var numberValue: Double
  
  @get:DoNotStrip
  @get:Keep
  @set:DoNotStrip
  @set:Keep
  abstract var optionalNumber: Double?
  
  @get:DoNotStrip
  @get:Keep
  @set:DoNotStrip
  @set:Keep
  abstract var primitiveArray: DoubleArray
  
  @get:DoNotStrip
  @get:Keep
  @set:DoNotStrip
  @set:Keep
  abstract var carCollection: Array<Car>
  
  @get:DoNotStrip
  @get:Keep
  @set:DoNotStrip
  @set:Keep
  abstract var someBuffer: ArrayBuffer

  // Methods
  @DoNotStrip
  @Keep
  abstract fun asyncTest(): Promise<Unit>
  
  @DoNotStrip
  @Keep
  abstract fun createMap(): AnyMap
  
  @DoNotStrip
  @Keep
  abstract fun addOnPersonBornListener(callback: (p: Person) -> Unit): Unit
  
  @DoNotStrip
  @Keep
  private fun addOnPersonBornListener(callback: Func_void_Person): Unit {
    val result = addOnPersonBornListener(callback.toLambda())
    return result
  }

  private external fun initHybrid(): HybridData

  companion object {
    private const val TAG = "HybridKotlinTestObjectSpec"
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
