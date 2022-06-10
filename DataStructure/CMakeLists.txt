cmake_minimum_required(VERSION 3.21)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

add_executable(
        DataStructure
        ALGraph/KruskalAlgorithms/ALGraphKruskal.c ALGraph/KruskalAlgorithms/ALGraphKruskal.h ALGraph/KruskalAlgorithms/ALEdge.h ALGraph/KruskalAlgorithms/ArrayBaseStack.c ALGraph/KruskalAlgorithms/ArrayBaseStack.h ALGraph/KruskalAlgorithms/DLinkedList.c ALGraph/KruskalAlgorithms/DLinkedList.h ALGraph/KruskalAlgorithms/KruskalMain.c ALGraph/KruskalAlgorithms/PriorityQueue.c ALGraph/KruskalAlgorithms/PriorityQueue.h ALGraph/KruskalAlgorithms/UsefulHeap.c ALGraph/KruskalAlgorithms/UsefulHeap.h)

