cmake_minimum_required(VERSION 3.18.0)

project(ModooString)

file(GLOB SRC *.cpp)
file(GLOB HEADER *.h)

add_executable(MODOO ${SRC} ${HEADER})

set_property(TARGET MODOO PROPERTY CMAKE_CXX_STANDARD 17)