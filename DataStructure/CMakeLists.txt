cmake_minimum_required(VERSION 3.21)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

add_executable(
        DataStructure

        Queue/CircularQueue/CircularQueue.c Queue/CircularQueue/CircularQueue.h Queue/CircularQueue/CircularQueueMain.c)
