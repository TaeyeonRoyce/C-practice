cmake_minimum_required(VERSION 3.21)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

add_executable(
        DataStructure
        ALGraph/ALGraph/ALGraph.c ALGraph/ALGraph/ALGraph.h ALGraph/ALGraph/ALGraphMain.c ALGraph/ALGraph/DLinkedList.c ALGraph/ALGraph/DLinkedList.h)

