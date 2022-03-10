cmake_minimum_required(VERSION 3.21)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

add_executable(
        DataStructure
        LinkedList/DLinkedList.h
        LinkedList/DLinkedList.c
        LinkedList/LinkedListSort/DLinkedListSortMain.c
)
