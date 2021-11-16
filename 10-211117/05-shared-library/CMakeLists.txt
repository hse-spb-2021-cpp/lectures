cmake_minimum_required(VERSION 3.10)

project(shared-library CXX)

find_package(Boost 1.71 REQUIRED filesystem)

add_library(multiply SHARED plugin_multiply.cpp)
add_library(sum SHARED plugin_sum.cpp)

add_executable(main main.cpp)
target_include_directories(main PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(main ${Boost_LIBRARIES})
