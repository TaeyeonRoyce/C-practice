cmake_minimum_required(VERSION 3.21)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

add_executable(
        DataStructure
        AdvancedLinkedList/CircularLinkedList/CircularLinkedList.h
        AdvancedLinkedList/CircularLinkedList/CircularLinkedList.c
        AdvancedLinkedList/CircularLinkedList/CircularLinkedListMain.c
)
