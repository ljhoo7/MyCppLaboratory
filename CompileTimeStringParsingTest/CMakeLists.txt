cmake_minimum_required(VERSION 3.18.0)

project(CompileTimeStaringParser)

file(GLOB SRC *.cpp *.h)

add_executable(CompileTimeStaringParser ${SRC})

set_property(TARGET CompileTimeStaringParser PROPERTY CXX_STANDARD 20)