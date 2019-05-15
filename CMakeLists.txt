cmake_minimum_required(VERSION 3.14)
project(klotski)

set(CMAKE_CXX_STANDARD 17)

add_executable(klotski src/main.cpp src/klotski.h src/klotski.cpp)