cmake_minimum_required(VERSION 3.21)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

add_executable(
        DataStructure
        Stack/LinkedListStack/LinkedListStack.c
        Stack/LinkedListStack/LinkedListStack.h
        Stack/LinkedListStack/LinkedListStackMain.c
)
