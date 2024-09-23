///
/// ImageSize.swift
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

import NitroModules

/**
 * Represents an instance of `ImageSize`, backed by a C++ struct.
 */
public typealias ImageSize = margelo.nitro.image.ImageSize

public extension ImageSize {
  private typealias bridge = margelo.nitro.image.bridge.swift

  /**
   * Create a new instance of `ImageSize`.
   */
  init(width: Double, height: Double) {
    self.init(width, height)
  }

  var width: Double {
    @inline(__always)
    get {
      return self.__width
    }
    @inline(__always)
    set {
      self.__width = newValue
    }
  }
  
  var height: Double {
    @inline(__always)
    get {
      return self.__height
    }
    @inline(__always)
    set {
      self.__height = newValue
    }
  }
}
