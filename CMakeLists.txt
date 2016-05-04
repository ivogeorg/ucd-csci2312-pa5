cmake_minimum_required(VERSION 3.5)
project(ucd_csci2312_pa5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    ErrorContext.cpp
    ErrorContext.h
    TemplateTests.cpp
    TemplateTests.h
    main.cpp
    less_functor.h custom_iterator.h)

add_executable(ucd_csci2312_pa5 ${SOURCE_FILES})