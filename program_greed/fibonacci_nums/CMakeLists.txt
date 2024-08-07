cmake_minimum_required(VERSION 3.5)

project(fibonacci_nums LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(fibonacci_nums main.cpp)

install(TARGETS fibonacci_nums
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
