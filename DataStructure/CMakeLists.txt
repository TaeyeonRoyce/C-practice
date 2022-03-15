cmake_minimum_required(VERSION 3.21)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

add_executable(
        DataStructure
        AdvancedLinkedList/CircularLinkedList/Problem01/EmployeeInfo.c
        AdvancedLinkedList/CircularLinkedList/Problem01/EmployeeInfo.h
        AdvancedLinkedList/CircularLinkedList/Problem01/CircularLinkedList.c
        AdvancedLinkedList/CircularLinkedList/Problem01/CircularLinkedList.h
)
