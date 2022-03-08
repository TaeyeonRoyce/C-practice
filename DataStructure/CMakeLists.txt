cmake_minimum_required(VERSION 3.21)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

#add_executable(
#        DataStructure
#        ADT.c
#        ArrayList/LinkedListV1Main.c
#        ArrayList/ArrayList.h
#        ArrayList/LinkedListV1.c
#        ArrayList/PointListMain.c
#        MatrixPoint/MatrixPoint.h
#        MatrixPoint/MatrixPoint.c
#    )

add_executable(
        DataStructure
#        ADT.c
        ArrayList/ArrayList.h
        ArrayList/ArrayList.c
#        ArrayList/LinkedListV1Main.c
        ArrayList/MatrixPoint/MatrixPointMain.c
        ArrayList/MatrixPoint/MatrixPoint.h
        ArrayList/MatrixPoint/MatrixPoint.c
    )

#add_executable(DataStructure ArrayList/PointListMain.c)
