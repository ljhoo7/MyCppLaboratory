cmake_minimum_required(VERSION 3.20.0)

project (LockFreeQueueTest)

set(CMAKE_CXX_STANDARD 17)

file(GLOB LOCK_FREE_QUEUE_TEST_SRC
	*.cpp *.h
	)

add_executable(LockFreeQueueTest ${LOCK_FREE_QUEUE_TEST_SRC})