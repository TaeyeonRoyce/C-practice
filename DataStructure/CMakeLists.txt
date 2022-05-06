cmake_minimum_required(VERSION 3.21)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

add_executable(
        DataStructure
        Tree/BinaryTree.c
        Tree/BinaryTree.h
        Tree/ExpressionTree/ExpressionTree.c
        Tree/ExpressionTree/ExpressionTree.h
        Tree/ExpressionTree/ExpressionTreeMain.c
        Tree/ExpressionTree/ListStackExpTree.c
        Tree/ExpressionTree/ListStackExpTree.h)

