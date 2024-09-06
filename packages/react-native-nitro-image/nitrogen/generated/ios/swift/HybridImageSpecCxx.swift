///
/// HybridImageSpecCxx.swift
/// Fri Sep 06 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

import Foundation
import NitroModules

/**
 * A class implementation that bridges HybridImageSpec over to C++.
 * In C++, we cannot use Swift protocols - so we need to wrap it in a class to make it strongly defined.
 *
 * Also, some Swift types need to be bridged with special handling:
 * - Enums need to be wrapped in Structs, otherwise they cannot be accessed bi-directionally (Swift bug: https://github.com/swiftlang/swift/issues/75330)
 * - Other HybridObjects need to be wrapped/unwrapped from the Swift TCxx wrapper
 * - Throwing methods need to be wrapped with a Result<T, Error> type, as exceptions cannot be propagated to C++
 */
public final class HybridImageSpecCxx {
  /**
   * The Swift <> C++ bridge's namespace (`margelo::nitro::image::bridge::swift`)
   * from `NitroImage-Swift-Cxx-Bridge.hpp`.
   * This contains specialized C++ templates, and C++ helper functions that can be accessed from Swift.
   */
  public typealias bridge = margelo.nitro.image.bridge.swift

  /**
   * Holds an instance of the `HybridImageSpec` Swift protocol.
   */
  private(set) var implementation: HybridImageSpec

  /**
   * Create a new `HybridImageSpecCxx` that wraps the given `HybridImageSpec`.
   * All properties and methods bridge to C++ types.
   */
  public init(_ implementation: HybridImageSpec) {
    self.implementation = implementation
  }

  /**
   * Contains a (weak) reference to the C++ HybridObject to cache it.
   */
  public var hybridContext: margelo.nitro.HybridContext {
    get {
      return self.implementation.hybridContext
    }
    set {
      self.implementation.hybridContext = newValue
    }
  }

  /**
   * Get the memory size of the Swift class (plus size of any other allocations)
   * so the JS VM can properly track it and garbage-collect the JS object if needed.
   */
  public var memorySize: Int {
    return self.implementation.memorySize
  }

  // Properties
  public var size: ImageSize {
    @inline(__always)
    get {
      return self.implementation.size
    }
  }
  
  public var pixelFormat: Int32 {
    @inline(__always)
    get {
      return self.implementation.pixelFormat.rawValue
    }
  }
  
  public var someSettableProp: Double {
    @inline(__always)
    get {
      return self.implementation.someSettableProp
    }
    @inline(__always)
    set {
      self.implementation.someSettableProp = newValue
    }
  }

  // Methods
  @inline(__always)
  public func toArrayBuffer(format: Int32) -> Double {
    do {
      let result = try self.implementation.toArrayBuffer(format: margelo.nitro.image.ImageFormat(rawValue: format)!)
      return result
    } catch {
      let message = "\(error.localizedDescription)"
      fatalError("Swift errors can currently not be propagated to C++! See https://github.com/swiftlang/swift/issues/75290 (Error: \(message))")
    }
  }
  
  @inline(__always)
  public func saveToFile(path: std.string, onFinished: bridge.Func_void_std__string) -> Void {
    do {
      try self.implementation.saveToFile(path: String(path), onFinished: { () -> ((String) -> Void) in
        let shared = bridge.share_Func_void_std__string(onFinished)
        return { (path: String) -> Void in
          shared.pointee(std.string(path))
        }
      }())
      return 
    } catch {
      let message = "\(error.localizedDescription)"
      fatalError("Swift errors can currently not be propagated to C++! See https://github.com/swiftlang/swift/issues/75290 (Error: \(message))")
    }
  }
}
