cmake_minimum_required(VERSION 3.0.0)

project(ModernTemplateTest)

file(GLOB MODERN_TEMPLATE_TEST_SRC *.cpp *.h)

add_executable(ModernTemplateTest ${MODERN_TEMPLATE_TEST_SRC})

set_property(TARGET ModernTemplateTest PROPERTY CXX_STANDARD 17)