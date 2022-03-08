cmake_minimum_required(VERSION 3.21)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

#add_executable(
#        DataStructure
#        ADT.c
#        LinkedList/LinkedListV1Main.c
#        LinkedList/ArrayList.h
#        LinkedList/LinkedListV1.c
#        LinkedList/PointListMain.c
#        Utils/MatrixPoint.h
#        Utils/MatrixPoint.c
#    )

add_executable(
        DataStructure
#        ADT.c
        LinkedList/ArrayList.h
        LinkedList/LinkedListV1.c
#        LinkedList/LinkedListV1Main.c
        LinkedList/PointListMain.c
        Utils/MatrixPoint.h
        Utils/MatrixPoint.c
    )

#add_executable(DataStructure LinkedList/PointListMain.c)
