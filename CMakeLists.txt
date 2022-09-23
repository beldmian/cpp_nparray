cmake_minimum_required(VERSION 3.10)
project(nparray)

file(GLOB SOURCE "*.cc")
add_executable(nparray ${SOURCE})

