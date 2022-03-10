/**
 * LinkedList에 구조체 변수 Sort 저장
 * 1. Matrix의 x, y 비교하여 Sort
 * 1-1. x기준 오름차순
 * 1-2. x가 같은 경우, y기준 오름차순
 */

/**
 * To Run this Source,
 * copy following texts and paste to CMakeLists.txt

   add_executable(
        DataStructure
        ArrayList/MatrixPoint/MatrixPoint.c
        ArrayList/MatrixPoint/MatrixPoint.h
        LinkedList/Problem03/LinkedListMatrixPoint.c
        LinkedList/Problem03/LinkedListMatrixPoint.h
        LinkedList/Problem03/MatrixPointMainSort.c
    )

 */

#include <stdio.h>
#include <stdlib.h>
#include "../../ArrayList/MatrixPoint/MatrixPoint.h"
#include "LinkedListMatrixPoint.h"

int MatrixListSort(MatrixPoint *point1, MatrixPoint *point2) {
    if (point1->xpos == point2->xpos) {
        if (point1->ypos < point2->ypos)
            return 0;
        else
            return 1;
    } else if (point1->xpos < point2->xpos)
        return 0;
    else
        return 1;
}


int main() {
    List list;
    MatrixPoint *ppos;

    ListInit(&list);
    SetSortRule(&list, MatrixListSort);


    //데이터 저장
    ppos = (MatrixPoint *) malloc(sizeof(MatrixPoint));
    SetPointPos(ppos, 3, 1);
    LInsert(&list, ppos);

    ppos = (MatrixPoint *) malloc(sizeof(MatrixPoint));
    SetPointPos(ppos, 1, 2);
    LInsert(&list, ppos);

    ppos = (MatrixPoint *) malloc(sizeof(MatrixPoint));
    SetPointPos(ppos, 9, 6);
    LInsert(&list, ppos);

    ppos = (MatrixPoint *) malloc(sizeof(MatrixPoint));
    SetPointPos(ppos, 9, 2);
    LInsert(&list, ppos);

    //데이터 출력
    printf("현재 데이터 수:%d \n", LCount(&list));

    if (LFirst(&list, &ppos)) {
        ShowPointPos(ppos);

        while (LNext(&list, &ppos)) {
            ShowPointPos(ppos);
        }
        printf("\n");
    }

    return 0;
}
