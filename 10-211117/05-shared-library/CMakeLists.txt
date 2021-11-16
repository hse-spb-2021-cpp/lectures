cmake_minimum_required(VERSION 3.10)

project(shared-library CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Boost 1.71 REQUIRED filesystem)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

# Windows: libmultiply.dll
# Linux: libmultiply.so
add_library(multiply SHARED plugin_multiply.cpp)
add_library(sum SHARED plugin_sum.cpp)

add_executable(main main.cpp)
target_link_libraries(main ${Boost_LIBRARIES} ${CMAKE_DL_LIBS})
