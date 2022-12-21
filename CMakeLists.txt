cmake_minimum_required(VERSION 3.6)
project(main)

add_library(Vector Vector.h)

add_executable(main Source.cpp)

target_link_libraries(main PRIVATE Vector)