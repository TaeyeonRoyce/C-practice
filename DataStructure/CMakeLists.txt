cmake_minimum_required(VERSION 3.21)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

add_executable(
        DataStructure
        Stack/PostCalculator/PostCalculator.c
        Stack/PostCalculator/PostCalculatorMain.c
        Stack/PostCalculator/PostCalculator.h
        Stack/LinkedListStack/LinkedListStack.h
        Stack/LinkedListStack/LinkedListStack.c
)

