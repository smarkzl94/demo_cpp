cmake_minimum_required(VERSION 3.16)

project(cpp_demo VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(cpp_demo
    src/main.cpp
)

add_executable(leetcode
    src/leetcode_3761.cpp
)
