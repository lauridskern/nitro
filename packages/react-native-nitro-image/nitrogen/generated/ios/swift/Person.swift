///
/// Person.swift
/// Fri Sep 06 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

import NitroModules

/**
 * Represents an instance of `Person`, backed by a C++ struct.
 */
public typealias Person = margelo.nitro.image.Person

public extension Person {
  private typealias bridge = margelo.nitro.image.bridge.swift

  /**
   * Create a new instance of `Person`.
   */
  init(name: String, age: Double) {
    self.init(std.string(name), age)
  }

  var name: String {
    @inline(__always)
    get {
      return String(self.__name)
    }
    @inline(__always)
    set {
      self.__name = std.string(newValue)
    }
  }
  
  var age: Double {
    @inline(__always)
    get {
      return self.__age
    }
    @inline(__always)
    set {
      self.__age = newValue
    }
  }
}
