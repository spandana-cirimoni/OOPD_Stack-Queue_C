# Abstract Data Types - Stack, Queue and Fixed Array C++ Templates

This repository contains C++ template implementations for basic array, fixed-size array, queue, and stack classes. These classes are designed to work with arbitrary elements of any data type.

Make use of the Array class to implement three more ADTs:

- Stack — an ADT that contains a list of elements such that the list has last-in, first-out (LIFO)
semantics, i.e., elements are inserted into the front of the list and removed from the front of
the list.

- Queue — an ADT that contains a list of elements such that the list has first-in, first-out (FIFO)
semantics, i.e., elements are inserted into the of the list and removed from the front of the list.

- Fixed Array — an ADT that is an array, but cannot grow or shrink.


## Files Included

- `Array.h` and `Array_Base.h`: Templates for a dynamic array class.
- `Array.inl` and `Array_Base.inl` - inline functions of Array
- `Array.cpp` and `Array_Base.cpp` - implementation of Array header

- `Stack.h`: Template for a basic stack class.
- `Stack.inl` - inline functions of Stack
- `Stack.cpp` - implementation of Stack
  
- `Queue.h` - Template for a basic stack class.
- `Queue.inl` - inline functions of Queue
- `Queue.cpp` - implementation of Queue
  
- `Fixed_Array.h`: Template for a fixed-size array class derived from the dynamic array class.
- `Fixed_Array.inl` - inline functions of Fixed_Array
- `Fixed_Array.cpp` - implementation of Fixed_Array header

### Build Configuration Files:
- `assignment2.mpc`: MPC (Makefile Project Creator) configuration file for the project.
- `Makefile.assignment2`: Makefile for building the project.


## Build Instructions
- To build the project, use the provided build configuration files:
  make all
  
- To clean the project, use:
  make clean

## How to Use

1. Include the necessary header file(s) in your C++ code, depending on the data structure you want to use (`Array`, `Fixed_Array`, `Queue`, or `Stack`).

2. Instantiate the class with the desired data type.

3. Use the provided methods to manipulate and work with the data structure.

Example:

```cpp
#include "Array.h"

int main() {
    // Create an array of integers
    Array<int> myArray;

    // Add elements to the array
    myArray.resize(5);
    myArray[0] = 1;
    myArray[1] = 2;
    myArray[2] = 3;
    myArray[3] = 4;
    myArray[4] = 5;

    // Print the elements of the array
    for (size_t i = 0; i < myArray.size(); ++i) {
        std::cout << myArray[i] << " ";
    }

    return 0;
}
