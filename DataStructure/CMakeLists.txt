cmake_minimum_required(VERSION 3.21)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

add_executable(
        DataStructure

        Queue/Deque/Deque.c
        Queue/Deque/Deque.h
        Queue/Deque/DequeMain.c)
