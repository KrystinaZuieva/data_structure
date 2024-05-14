cmake_minimum_required(VERSION 3.26)
project(data_structure)

set(CMAKE_CXX_STANDARD 17)

add_executable(data_structure main.cpp
        SingleNode.h
        DoubleNode.h
        SinglyLinkedList.h
        DoubleLinkedList.h)
