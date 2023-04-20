cmake_minimum_required(VERSION 3.24)
project(Single_Linked_List)

set(CMAKE_CXX_STANDARD 23)

add_executable(Single_Linked_List main.cpp SingleLinkedList.cpp SingleLinkedList.h DoubleLinkedList.cpp DoubleLinkedList.h CircularLinkedList.cpp CircularLinkedList.h)
