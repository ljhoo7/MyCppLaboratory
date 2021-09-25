cmake_minimum_required(VERSION 3.18.0)

project(TieAndPairTupleTest)

file(GLOB SRC *.cpp *.h)

add_executable(TieAndPairTupleTest ${SRC})

set_property(TARGET TieAndPairTupleTest PROPERTY CXX_STANDARD 20)