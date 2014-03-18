cmake_minimum_required(VERSION 2.8)

project(raytrace)

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS} -g")

add_executable(raytrace main.cpp Vector3D.cpp Point3D.cpp)

target_link_libraries(raytrace opencv_highgui opencv_imgproc opencv_core)