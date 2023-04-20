cmake_minimum_required(VERSION 3.24)
project(Queues)

set(CMAKE_CXX_STANDARD 23)

add_executable(Queues main.cpp Queue.cpp Queue.h SingleLinkedList.cpp SingleLinkedList.h)
