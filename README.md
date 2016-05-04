## CSCI 2312: Programming Assignment 5 Mini 
## \<\< UNDER DEVELOPMENT \>\>

_templates, STL, C++11_

* * *

### Goals

1. Get experience with C++ templates and the Standard Template Library (STL).
4. Continue using git and Github.
5. Develop good coding style.

### Synopsis

PA5 is a standalone assignment and does not depend on PA1-PA4.

PA5 is in the test-driven-development (TDD) style, just like the preceding assignments. 

This assignment (PA5-Mini) is a significantly scaled-back version of the original PA5. It contains a set of small standalone exercises with C++ templates.

### Submission

You don't need to submit anything. Once you fork the repository (this is your **remote** repository on Github, aka **origin**), you will clone it to your development machine (this is your local repository), and start work on it. Commit your changes to your local repository often and push them up to the remote repository occasionally. Make sure you push at least once before the due date. At the due date, your remote repository will be cloned and tested automatically by the grading script. _**Note:** Your code should be in the **master** branch of your remote repository._

### Grading

An autograding script will run the test suite against your files. Your grade will be based on the number of tests passed. (E.g. if your code passes 3 out of 6 test cases, your score will be 50% and the grade will be the corresponding letter grade in the course's grading scale). The test suite for PA5 has __(TODO)__ tests. **Note:** The testing and grading will be done with fresh original copies of all the provided files. In the course of development, you can modify them, if you need to, but your changes will not be used. Only your (TODO) files will be used.

### Compiler

Your program should run on **GCC 4.9.0** or later, or **Clang 3.3** or later. No other compilers are supported.

### Due Date

The assignment is due on **Tue, May 10, at 23:59 Mountain time**. No late work. The last commit to your PA5 repository before the deadline will be graded.

### Honor Code

Free Github repositories are public so you can look at each other's code. Please, don't do that. You can discuss any programming topics and the assignments in general but sharing of solutions diminishes the individual learning experience of many people. Assignments might be randomly checked for plagiarism and a plagiarism claim may be raised against you.

### Use of libraries

Unless otherwise specified, you are encouraged to make maximum use of the Standard Library, especially the Standard Template Library (STL).

### Coding style

Familiarize yourself with and start following [coding style guidelines](http://courses.cms.caltech.edu/cs11/material/cpp/donnie/cppstyle.html). There are others on the Web. Pick one and be consistent. _**Note:** If you stumble on the Google C++ Style Guide, be advised that it has been heavily criticized by many leading C++ programmers. I don't advise you to follow it, especially the more advanced features. This Guide is for entry-level coders at Google who need to be able to work with their legacy code. It is not advisable for new projects and novice programmers._

### References

Operator overloading [guidelines](http://courses.cms.caltech.edu/cs11/material/cpp/donnie/cpp-ops.html). For the implementation of `virtual Piece &operator*(Piece &other)`, see this [example](https://github.com/ivogeorg/ucd-csci2312-pa4/blob/master/examples/virtual_operator.cpp).

A very good [C++ tutorial](http://www.learncpp.com/), including many topics we are covering.

Two websites with C++ Reference, [here](http://en.cppreference.com/w/) and [here](http://www.cplusplus.com/).

### Detailed Instructions

#### I. Implementing and specializing a functor 

##### Introduction

A functor is a function object, an object of a class type which overloads the function operator `operator()`. An functor object can be "called" like a function.

```c++
class F {
  public:
    [return type] operator() ([operator argument list]);
}

int main() {
  F f;
  
  T t = f(4, 5, "string");  // T is the same type as the return type of F::operator()
  
  return 0;
}
```

Naturally, a functor class can be a _class template_:

```c++
template <typename T>
class F {
  public:
    [return type] operator() ([operator argument list]);
}

int main() {
  F<W> f;
  
  T t = f(4, 5, "string");
  
  return 0;
}
```

A template _specialization_ is an implementation of a template for a specific type. This is useful if one or more of the types for which the template will be instantiated require special implementation. A common example is comparing numeric primitives and strings. The template specialization syntax is as follows:

```c++
template <typename T>
class F {
  public:
    void operator() (const T &);
}

template <>
class F<std::string> {
  public:
    void operator() (const std::string &);
}
```

Notice (i) the `template <>` line, and (ii) that the rest of the class declaration is non-template since it has been _specialized_ for the type `std::string`.

##### Requirements

1. Implement a template functor `less` for arbitrary types which overload `operator<`.

2. Specialize the template for C-strings (type `const char *`) and standard strings (type `std::string`).

3. To avoid clashes with the `std` namespace, which implements `less`, you need to wrap your implementation in the namespace `CS2312`.

4. You should not use `std::less`.

5. Write your implementation in file `less_functor.h`.

#### II. Implementing a container iterator

<< IN PROGRESS >>

