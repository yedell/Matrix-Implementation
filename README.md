# C++ Matrix Implementation

# Yona Edell

[![Build Status](https://travis-ci.com/csc340-03-spring-2016/yedell-HW7.svg?token=69t7ThEH9PYiydpeYrPA&branch=master)](https://travis-ci.com/csc340-03-spring-2016/yedell-HW7)

Overloaded operators +,-,* in the class Matrix. Look into the file `Matrix.h` for more details.
      
## Exceptions to be thrown
Throws the default exception wherever necessary (Incorrect sizes, etc)

## Matrix Multiplication Order
```

Given the statement: Mat3 = Mat1 * Mat2;

Mat1 ={{1,  3, -3},
       {-4, 4, 5},
       {-1, 2, 0},
       {6,  7, 8}};

Mat2 ={{-2, 9, 3,  1},
       {10, 4, 5,  11},
       {-1, 2, 12, 0}};

Then Mat3 will be:

Mat3 :{{31, 15,  -18, 34},
       {43, -10, 68,  40},
       {22, -1,  7,   21},
       {50, 98,  149, 83}};

```
## Constraints 
* The class supports the following types via templates:
    * int
    * float
