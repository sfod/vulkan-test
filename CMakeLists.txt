cmake_minimum_required(VERSION 3.14)
project(vulkan-test)

set(CMAKE_CXX_STANDARD 17)

ADD_COMPILE_OPTIONS(-Wall -Wextra -pedantic)
ADD_COMPILE_OPTIONS("$<$<CONFIG:RELEASE>:-O3>")
ADD_COMPILE_OPTIONS("$<$<CONFIG:DEBUG>:-O0;-ggdb>")
ADD_COMPILE_OPTIONS("$<$<CONFIG:RELWITHDEBINFO>:-O2;-ggdb;-pg;-fno-omit-frame-pointer>")

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "Build type is not specified, set to Release")
    set(CMAKE_BUILD_TYPE "Release")
else()
    message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
endif()

add_executable(vulkan-test src/main.cpp src/triangle_app.hpp src/triangle_app.cpp)
target_link_libraries(vulkan-test glfw vulkan)
