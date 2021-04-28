cmake_minimum_required(VERSION 3.18.0)

project(CompileTimeStringParser)

file(GLOB SRC *.cpp *.h)

add_executable(CompileTimeStringParser ${SRC})

set_property(TARGET CompileTimeStringParser PROPERTY CXX_STANDARD 20)