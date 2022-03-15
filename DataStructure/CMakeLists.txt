cmake_minimum_required(VERSION 3.21)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

add_executable(
        DataStructure
        AdvancedLinkedList/DoubleLinkedList/DoubleLinkedList.c AdvancedLinkedList/DoubleLinkedList/DoubleLinkedList.h AdvancedLinkedList/DoubleLinkedList/DoubleLinkedListMain.c)
