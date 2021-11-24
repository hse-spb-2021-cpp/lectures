cmake_minimum_required(VERSION 3.10)

project(shared-library CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)  # Recommended by Boost.DLL's manual

find_package(Boost 1.71 REQUIRED filesystem)  # Required by Boost.DLL
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

add_library(one SHARED plugin_one.cpp)

add_executable(01-bad 01-bad.cpp)
target_link_libraries(01-bad ${Boost_LIBRARIES} ${CMAKE_DL_LIBS})

add_executable(02-good-global 02-good-global.cpp)
target_link_libraries(02-good-global ${Boost_LIBRARIES} ${CMAKE_DL_LIBS})

add_executable(03-good 03-good.cpp)
target_link_libraries(03-good ${Boost_LIBRARIES} ${CMAKE_DL_LIBS})
