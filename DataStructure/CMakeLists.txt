cmake_minimum_required(VERSION 3.21)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

add_executable(
        DataStructure
        Stack/LinkedListStack/LinkedListStack.h
        Stack/LinkedListStack/LinkedListStack.c
        Stack/InfixToPostfix/InfixToPostfix.c
        Stack/InfixToPostfix/InfixToPostfix.h
        Stack/InfixToPostfix/InfixToPostfixMain.c
)
