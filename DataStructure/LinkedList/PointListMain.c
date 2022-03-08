#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "../Utils/MatrixPoint.h"

int main() {
    List list;
    Point compPos;
    Point *ppos;

    ListInit(&list);

    //데이터 저장
    ppos = (Point *) malloc(sizeof(Point));
    SetPointPos(ppos, 2, 1);
    LInsert(&list, ppos);

    ppos = (Point *) malloc(sizeof(Point));
    SetPointPos(ppos, 2, 2);
    LInsert(&list, ppos);

    ppos = (Point *) malloc(sizeof(Point));
    SetPointPos(ppos, 3, 1);
    LInsert(&list, ppos);

    ppos = (Point *) malloc(sizeof(Point));
    SetPointPos(ppos, 3, 2);
    LInsert(&list, ppos);

    //데이터 출력
    printf("현재 데이터 수:%d", LCount(&list));

    if (LFirst(&list, ppos)) {
        ShowPointPos(ppos);

        while (LNext(&list, ppos)) {
            ShowPointPos(ppos);
        }
        printf("\n");
    }

    //xpos가 2인 데이터 삭제
    compPos.xpos = 2;
    compPos.ypos = 0;

    if (LFirst(&list, ppos)) {

        //x가 같다
        if (PointComp(ppos, &compPos) == 1) {

            //삭제된 ppos를 반환 받고 메모리에서 해제한다
            ppos = LRemove(&list);
            free(ppos);
        }

        while (LNext(&list, ppos)) {
            if (PointComp(ppos, &compPos) == 1) {
                ppos = LRemove(&list);
                free(ppos);
            }
        }
    }
    //데이터 출력
    printf("현재 데이터 수:%d", LCount(&list));

    if (LFirst(&list, ppos)) {
        ShowPointPos(ppos);

        while (LNext(&list, ppos)) {
            ShowPointPos(ppos);
        }
        printf("\n");
    }

    return 0;
}



