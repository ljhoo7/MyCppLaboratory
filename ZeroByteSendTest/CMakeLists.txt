cmake_minimum_required(VERSION 3.10.0)

project(ZeroByteSendTest)

file(GLOB SERVER_SRC_FILE ServerMain.cpp)
file(GLOB CLIENT_SRC_FILE ClientMain.cpp)

add_executable(Server ${SERVER_SRC_FILE})
add_executable(Client ${CLIENT_SRC_FILE})