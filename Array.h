// -*- C++ -*-
// $Id: Array.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
 * @file       Array.h
 *
 * $Id: Array.h 380 2010-02-08 05:10:33Z hillj $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _ARRAY_H_
#define _ARRAY_H_

#include "Array_Base.h"

// COMMENT This array class should contain methods that change the size of the
// array. The other methods should be moved to the base class.

// FIX: All methods here already only change the size of the array, aside from the constructors. = operator has to be overloaded in order to support resizing. Max_size() returns a variable that is unique to resizable arrays, (max_size_), and resize and rawResizeToLarger both directly resize the array.

/**
 * @class Array
 *
 * Basic implementation of a standard array class for chars.
 */
template <typename T>
class Array : public Array_Base<T>
{
public:
  /// Type definition of the element type.
  typedef T type;

  /// Default constructor.
  Array(void);

  /**
   * Initializing constructor.
   *
   * @param[in]      length        Initial size
   */
  Array(size_t length);

  /**
   * Initializing constructor.
   *
   * @param[in]      length        Initial size
   * @param[in]      fill          Initial value for each element
   */
  Array(size_t length, T fill);

  /**
   * Copy constructor
   *
   * @param[in]     arr         The source array.
   */
  Array(const Array &arr);

  /// Destructor.
  ~Array(void);

  /**
   * Assignment operation
   *
   * @param[in]       rhs      Right-hand side of equal sign
   * @return          Reference to self
   */
  const Array &operator=(const Array &rhs);

  /**
   * Retrieve the maximum size of the array.
   *
   * @return          The maximum size
   */
  size_t max_size(void) const;

  /**
   * Set a new size for the array. If \a new_size is less than the current
   * size, then the array is truncated. If \a new_size if greater then the
   * current size, then the array is made larger and the new elements are
   * not initialized to anything. If \a new_size is the same as the current
   * size, then nothing happens.
   *
   * The array's original contents are preserved regardless of whether the 
   * array's size is either increased or decreased.
   *
   * @param[in]       new_size              New size of the array
   */
  void resize(size_t new_size);

protected:
  /// Maximum size of the array.
  size_t max_size_;

  T *rawResizeToLarger(size_t new_size);
};

#include "Array.inl"
#include "Array.hpp"

#endif // !defined _ARRAY_H_
