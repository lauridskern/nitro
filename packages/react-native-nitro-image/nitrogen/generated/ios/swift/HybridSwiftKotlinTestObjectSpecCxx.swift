///
/// HybridSwiftKotlinTestObjectSpecCxx.swift
/// Tue Aug 13 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/react-native-nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

import Foundation
import NitroModules

/**
 * A class implementation that bridges HybridSwiftKotlinTestObjectSpec over to C++.
 * In C++, we cannot use Swift protocols - so we need to wrap it in a class to make it strongly defined.
 *
 * Also, some Swift types need to be bridged with special handling:
 * - Enums need to be wrapped in Structs, otherwise they cannot be accessed bi-directionally (Swift bug: https://github.com/swiftlang/swift/issues/75330)
 * - Other HybridObjects need to be wrapped/unwrapped from the Swift TCxx wrapper
 * - Throwing methods need to be wrapped with a Result<T, Error> type, as exceptions cannot be propagated to C++
 */
public final class HybridSwiftKotlinTestObjectSpecCxx {
  private(set) var implementation: HybridSwiftKotlinTestObjectSpec

  public init(_ implementation: HybridSwiftKotlinTestObjectSpec) {
    self.implementation = implementation
  }

  // HybridObject C++ part
  public var hybridContext: margelo.nitro.HybridContext {
    get {
      return self.implementation.hybridContext
    }
    set {
      self.implementation.hybridContext = newValue
    }
  }

  // Memory size of the Swift class (plus size of any other allocations)
  public var memorySize: Int {
    return self.implementation.memorySize
  }

  // Properties
  public var numberValue: Double {
    @inline(__always)
    get {
      return self.implementation.numberValue
    }
    @inline(__always)
    set {
      self.implementation.numberValue = newValue
    }
  }
  
  public var boolValue: Bool {
    @inline(__always)
    get {
      return self.implementation.boolValue
    }
    @inline(__always)
    set {
      self.implementation.boolValue = newValue
    }
  }
  
  public var stringValue: std.string {
    @inline(__always)
    get {
      return std.string(self.implementation.stringValue)
    }
    @inline(__always)
    set {
      self.implementation.stringValue = String(newValue)
    }
  }
  
  public var bigintValue: Int64 {
    @inline(__always)
    get {
      return self.implementation.bigintValue
    }
    @inline(__always)
    set {
      self.implementation.bigintValue = newValue
    }
  }
  
  public var stringOrUndefined: margelo.nitro.image.std__optional_std__string_ {
    @inline(__always)
    get {
      return {
        if let actualValue = self.implementation.stringOrUndefined {
          return margelo.nitro.image.create_std__optional_std__string_(std.string(actualValue))
        } else {
          return .init()
        }
      }()
    }
    @inline(__always)
    set {
      self.implementation.stringOrUndefined = {
        if let actualValue = newValue.value {
          return String(actualValue)
        } else {
          return nil
        }
      }()
    }
  }
  
  public var stringOrNull: margelo.nitro.image.std__optional_std__string_ {
    @inline(__always)
    get {
      return {
        if let actualValue = self.implementation.stringOrNull {
          return margelo.nitro.image.create_std__optional_std__string_(std.string(actualValue))
        } else {
          return .init()
        }
      }()
    }
    @inline(__always)
    set {
      self.implementation.stringOrNull = {
        if let actualValue = newValue.value {
          return String(actualValue)
        } else {
          return nil
        }
      }()
    }
  }
  
  public var optionalString: margelo.nitro.image.std__optional_std__string_ {
    @inline(__always)
    get {
      return {
        if let actualValue = self.implementation.optionalString {
          return margelo.nitro.image.create_std__optional_std__string_(std.string(actualValue))
        } else {
          return .init()
        }
      }()
    }
    @inline(__always)
    set {
      self.implementation.optionalString = {
        if let actualValue = newValue.value {
          return String(actualValue)
        } else {
          return nil
        }
      }()
    }
  }

  // Methods
  @inline(__always)
  public func simpleFunc() -> Void {
    do {
      try self.implementation.simpleFunc()
      return 
    } catch {
      let message = "\(error.localizedDescription)"
      fatalError("Swift errors can currently not be propagated to C++! See https://github.com/swiftlang/swift/issues/75290 (Error: \(message))")
    }
  }
  
  @inline(__always)
  public func addNumbers(a: Double, b: Double) -> Double {
    do {
      let result = try self.implementation.addNumbers(a: a, b: b)
      return result
    } catch {
      let message = "\(error.localizedDescription)"
      fatalError("Swift errors can currently not be propagated to C++! See https://github.com/swiftlang/swift/issues/75290 (Error: \(message))")
    }
  }
  
  @inline(__always)
  public func addStrings(a: std.string, b: std.string) -> std.string {
    do {
      let result = try self.implementation.addStrings(a: String(a), b: String(b))
      return std.string(result)
    } catch {
      let message = "\(error.localizedDescription)"
      fatalError("Swift errors can currently not be propagated to C++! See https://github.com/swiftlang/swift/issues/75290 (Error: \(message))")
    }
  }
  
  @inline(__always)
  public func multipleArguments(num: Double, str: std.string, boo: Bool) -> Void {
    do {
      try self.implementation.multipleArguments(num: num, str: String(str), boo: boo)
      return 
    } catch {
      let message = "\(error.localizedDescription)"
      fatalError("Swift errors can currently not be propagated to C++! See https://github.com/swiftlang/swift/issues/75290 (Error: \(message))")
    }
  }
  
  @inline(__always)
  public func getNumbers() -> margelo.nitro.image.std__vector_double_ {
    do {
      let result = try self.implementation.getNumbers()
      return {
        var vector = margelo.nitro.image.create_std__vector_double_(result.count)
        for item in result {
          vector.push_back(item)
        }
        return vector
      }()
    } catch {
      let message = "\(error.localizedDescription)"
      fatalError("Swift errors can currently not be propagated to C++! See https://github.com/swiftlang/swift/issues/75290 (Error: \(message))")
    }
  }
  
  @inline(__always)
  public func getStrings() -> margelo.nitro.image.std__vector_std__string_ {
    do {
      let result = try self.implementation.getStrings()
      return {
        var vector = margelo.nitro.image.create_std__vector_std__string_(result.count)
        for item in result {
          vector.push_back(std.string(item))
        }
        return vector
      }()
    } catch {
      let message = "\(error.localizedDescription)"
      fatalError("Swift errors can currently not be propagated to C++! See https://github.com/swiftlang/swift/issues/75290 (Error: \(message))")
    }
  }
  
  @inline(__always)
  public func callCallback(callback: margelo.nitro.image.Func_void) -> Void {
    do {
      try self.implementation.callCallback(callback: { () -> Void in
    callback()
  })
      return 
    } catch {
      let message = "\(error.localizedDescription)"
      fatalError("Swift errors can currently not be propagated to C++! See https://github.com/swiftlang/swift/issues/75290 (Error: \(message))")
    }
  }
}
