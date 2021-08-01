cmake_minimum_required(VERSION 3.0.0)

project(VariableTest)

file(GLOB VARIABLE_TEST_SRC *.cpp *.h)

add_executable(VariableTest ${VARIABLE_TEST_SRC})