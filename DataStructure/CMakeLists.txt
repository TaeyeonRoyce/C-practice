cmake_minimum_required(VERSION 3.21)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

add_executable(
        DataStructure
        Assignment/03_NameCardSortList/DLinkedList.c
        Assignment/03_NameCardSortList/DLinkedList.h
        Assignment/03_NameCardSortList/NameCard.c
        Assignment/03_NameCardSortList/NameCard.h
        Assignment/03_NameCardSortList/NameCardLinkedList.c
)
