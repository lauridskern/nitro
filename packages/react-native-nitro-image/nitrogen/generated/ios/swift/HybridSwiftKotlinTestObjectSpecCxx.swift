///
/// HybridSwiftKotlinTestObjectSpecCxx.swift
/// Mon Aug 12 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/react-native-nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

import Foundation
import NitroModules

/**
 * A class implementation that bridges HybridSwiftKotlinTestObjectSpec over to C++.
 * In C++, we cannot use Swift protocols - so we need to wrap it in a class to make it strongly defined.
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
  
  public var stringValue: String {
    @inline(__always)
    get {
      return self.implementation.stringValue
    }
    @inline(__always)
    set {
      self.implementation.stringValue = newValue
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
  
  public var stringOrUndefined: String? {
    @inline(__always)
    get {
      return self.implementation.stringOrUndefined
    }
    @inline(__always)
    set {
      self.implementation.stringOrUndefined = newValue
    }
  }
  
  public var stringOrNull: String? {
    @inline(__always)
    get {
      return self.implementation.stringOrNull
    }
    @inline(__always)
    set {
      self.implementation.stringOrNull = newValue
    }
  }
  
  public var optionalString: String? {
    @inline(__always)
    get {
      return self.implementation.optionalString
    }
    @inline(__always)
    set {
      self.implementation.optionalString = newValue
    }
  }

  // Methods
  @inline(__always)
  public func simpleFunc() -> Void {
    do {
      try self.implementation.simpleFunc()
    } catch {
      // TODO: Wait for https://github.com/swiftlang/swift/issues/75290
      fatalError("Swift errors cannot be propagated to C++ yet! If you want to throw errors, consider using a Promise (async) or a variant type (sync) instead.")
    }
  }
  
  @inline(__always)
  public func addNumbers(a: Double, b: Double) -> Double {
    do {
      return try self.implementation.addNumbers(a: a, b: b)
    } catch {
      // TODO: Wait for https://github.com/swiftlang/swift/issues/75290
      fatalError("Swift errors cannot be propagated to C++ yet! If you want to throw errors, consider using a Promise (async) or a variant type (sync) instead.")
    }
  }
  
  @inline(__always)
  public func addStrings(a: String, b: String) -> String {
    do {
      return try self.implementation.addStrings(a: a, b: b)
    } catch {
      // TODO: Wait for https://github.com/swiftlang/swift/issues/75290
      fatalError("Swift errors cannot be propagated to C++ yet! If you want to throw errors, consider using a Promise (async) or a variant type (sync) instead.")
    }
  }
  
  @inline(__always)
  public func multipleArguments(num: Double, str: String, boo: Bool) -> Void {
    do {
      try self.implementation.multipleArguments(num: num, str: str, boo: boo)
    } catch {
      // TODO: Wait for https://github.com/swiftlang/swift/issues/75290
      fatalError("Swift errors cannot be propagated to C++ yet! If you want to throw errors, consider using a Promise (async) or a variant type (sync) instead.")
    }
  }
  
  @inline(__always)
  public func createNumbers() -> [Double] {
    do {
      return try self.implementation.createNumbers()
    } catch {
      // TODO: Wait for https://github.com/swiftlang/swift/issues/75290
      fatalError("Swift errors cannot be propagated to C++ yet! If you want to throw errors, consider using a Promise (async) or a variant type (sync) instead.")
    }
  }
  
  @inline(__always)
  public func createStrings() -> [String] {
    do {
      return try self.implementation.createStrings()
    } catch {
      // TODO: Wait for https://github.com/swiftlang/swift/issues/75290
      fatalError("Swift errors cannot be propagated to C++ yet! If you want to throw errors, consider using a Promise (async) or a variant type (sync) instead.")
    }
  }
  
  @inline(__always)
  public func tryOptionalParams(num: Double, boo: Bool, str: String?) -> String {
    do {
      return try self.implementation.tryOptionalParams(num: num, boo: boo, str: str)
    } catch {
      // TODO: Wait for https://github.com/swiftlang/swift/issues/75290
      fatalError("Swift errors cannot be propagated to C++ yet! If you want to throw errors, consider using a Promise (async) or a variant type (sync) instead.")
    }
  }
  
  @inline(__always)
  public func tryMiddleParam(num: Double, boo: Bool?, str: String) -> String {
    do {
      return try self.implementation.tryMiddleParam(num: num, boo: boo, str: str)
    } catch {
      // TODO: Wait for https://github.com/swiftlang/swift/issues/75290
      fatalError("Swift errors cannot be propagated to C++ yet! If you want to throw errors, consider using a Promise (async) or a variant type (sync) instead.")
    }
  }
  
  @inline(__always)
  public func getCar() -> Car {
    do {
      return try self.implementation.getCar()
    } catch {
      // TODO: Wait for https://github.com/swiftlang/swift/issues/75290
      fatalError("Swift errors cannot be propagated to C++ yet! If you want to throw errors, consider using a Promise (async) or a variant type (sync) instead.")
    }
  }
  
  @inline(__always)
  public func isCarElectric(car: Car) -> Bool {
    do {
      return try self.implementation.isCarElectric(car: car)
    } catch {
      // TODO: Wait for https://github.com/swiftlang/swift/issues/75290
      fatalError("Swift errors cannot be propagated to C++ yet! If you want to throw errors, consider using a Promise (async) or a variant type (sync) instead.")
    }
  }
  
  @inline(__always)
  public func getDriver(car: Car) -> Person? {
    do {
      return try self.implementation.getDriver(car: car)
    } catch {
      // TODO: Wait for https://github.com/swiftlang/swift/issues/75290
      fatalError("Swift errors cannot be propagated to C++ yet! If you want to throw errors, consider using a Promise (async) or a variant type (sync) instead.")
    }
  }
}