cmake_minimum_required(VERSION 3.21)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

add_executable(
        DataStructure
        Search/BinarySearch/BinaryTree.c
        Search/BinarySearch/BinaryTree.h Search/BinarySearch/BinarySearchTree.c Search/BinarySearch/BinarySearchTree.h Search/BinarySearch/BinarySearchMain.c)

