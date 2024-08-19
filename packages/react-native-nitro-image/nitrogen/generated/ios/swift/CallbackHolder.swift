///
/// CallbackHolder.swift
/// Mon Aug 19 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/react-native-nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

import NitroModules

/**
 * Represents an instance of `CallbackHolder`, backed by a C++ struct.
 */
public typealias CallbackHolder = margelo.nitro.image.CallbackHolder

public extension CallbackHolder {
  private typealias bridge = margelo.nitro.image.bridge.swift

  /**
   * Create a new instance of `CallbackHolder`.
   */
  init(callback: @escaping (() -> Void)) {
    self.init({ () -> bridge.Func_void in
      let (wrappedClosure, context) = ClosureWrapper.wrap(closure: callback)
      return bridge.create_Func_void(wrappedClosure, context)
    }())
  }

  var callback: (() -> Void) {
    @inline(__always)
    get {
      return { () -> Void in
        self.__callback()
      }
    }
    @inline(__always)
    set {
      self.__callback = { () -> bridge.Func_void in
        let (wrappedClosure, context) = ClosureWrapper.wrap(closure: newValue)
        return bridge.create_Func_void(wrappedClosure, context)
      }()
    }
  }
}
