cmake_minimum_required(VERSION 3.21)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

add_executable(
        DataStructure
        ALGraph/ALGraphDFS/ALGraphDFS.c ALGraph/ALGraphDFS/ALGraphDFS.h ALGraph/ALGraphDFS/ALGraphDFSMain.c ALGraph/ALGraphDFS/DLinkedList.c ALGraph/ALGraphDFS/DLinkedList.h ALGraph/ALGraphDFS/ArrayBaseStack.c ALGraph/ALGraphDFS/ArrayBaseStack.h)

