cmake_minimum_required(VERSION 3.21)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

add_executable(
        DataStructure
        PriorityHeap/UsefulHeap/UsefulHeap.c
        PriorityHeap/UsefulHeap/UsefulHeap.h
        PriorityHeap/UsefulHeap/UsefulHeapMain.c)

