#ifndef _ARRAY_BASE_H_
#define _ARRAY_BASE_H_
#define defaultSize 5

#include <cstring> // for size_t definition
#include <stdexcept> // for std::out_of_bounds exception
#include <exception>

template <typename T>
class Array_Base
{
private:
protected:
    /// Pointer to the actual data.
    T *data_;

    /// Current size of the array.
    size_t cur_size_;

public:
    /// Type definition of the element type.
    typedef T type;

    // Default Constructor
    Array_Base(void);

    // Copy Constructor
    Array_Base(const Array_Base &arr);

    // Destructor
    virtual ~Array_Base(void);

    // Getter for cur size
    virtual size_t size(void) const;

    // Getter given index
    virtual T &operator[](size_t index);

    // Getter given index
    virtual const T &operator[](size_t index) const;

    // Getter given index
    virtual T get(size_t index) const;

    // Set at given index
    virtual void set(size_t index, T value);

    // Traverse the array and find the element.
    virtual int find(T element) const;

    // Traverse the array from start and find the element.
    virtual int find(T element, size_t start) const;
    
    // Check if this == rhs as in size and elements
    virtual bool operator==(const Array_Base &rhs) const;

    // Check if this != rhs as in size and elements
    virtual bool operator!=(const Array_Base &rhs) const;

    // Fill the entire array with given element
    virtual void fill(T element);

    // Reverse the array.
    virtual void reverse(void);
};

#include "Array_Base.inl"
#include "Array_Base.hpp"

#endif // !defined _ARRAY_BASE_H_