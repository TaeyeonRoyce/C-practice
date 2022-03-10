cmake_minimum_required(VERSION 3.21)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

add_executable(
        DataStructure
        ArrayList/MatrixPoint/MatrixPoint.c
        ArrayList/MatrixPoint/MatrixPoint.h
        LinkedList/Problem03/LinkedListMatrixPoint.c
        LinkedList/Problem03/LinkedListMatrixPoint.h
        LinkedList/Problem03/MatrixPointMainSort.c
)
