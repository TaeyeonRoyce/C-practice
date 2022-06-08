cmake_minimum_required(VERSION 3.21)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

add_executable(
        DataStructure
        ALGraph/ALGraphBFS/ALGraphBFS.c ALGraph/ALGraphBFS/ALGraphBFS.h ALGraph/ALGraphBFS/BFSMain.c ALGraph/ALGraphBFS/CircularQueue.c ALGraph/ALGraphBFS/CircularQueue.h ALGraph/ALGraphBFS/DLinkedList.c ALGraph/ALGraphBFS/DLinkedList.h)

