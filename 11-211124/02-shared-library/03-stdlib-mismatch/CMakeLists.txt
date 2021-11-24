cmake_minimum_required(VERSION 3.10)

project(shared-library CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)  # Recommended by Boost.DLL's manual

find_package(Boost 1.71 REQUIRED filesystem)  # Required by Boost.DLL
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

add_library(one SHARED plugin_one.cpp)

add_executable(01-careful 01-careful.cpp)
target_link_libraries(01-careful ${Boost_LIBRARIES} ${CMAKE_DL_LIBS})
