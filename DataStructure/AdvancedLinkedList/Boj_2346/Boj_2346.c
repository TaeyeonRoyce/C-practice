#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "CircularLinkedList.h"
#include "Balloon.h"

int main() {
    int N;
    CList cList;
    ListInit(&cList);
    scanf("%d", &N);

    int moveCnt;
    Balloon *newBalloon;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &moveCnt);
        newBalloon = MakeBalloon(i + 1, moveCnt);
        LInsert(&cList, newBalloon);
    }

    LFirst(&cList, &newBalloon);
    while(LCount(&cList) > 0) {

        if (newBalloon->index == 1) {
            printf("%d ", newBalloon->index);
            moveCnt = LRemove(&cList);
        }

        if (moveCnt > 0) {
            for (int i = 0; i < moveCnt; ++i) {
                LNext(&cList, &newBalloon);
            }
        } else {
            int logicalSize = LCount(&cList) + 1;
            //(logicalSize + (moveCnt % logicalSize))
            //size�� 5�� �������Ḯ��Ʈ���� �ڷ� 7ĭ�� ���ٰ� �ϸ�,
            //"1" 2 3 4 5 -> 1 2 3 "4" 5
            //������ 3ĭ �����̴� �Ͱ� ����
            //5 + (-7 % 5) = 5 - 2 = 3
            for (int i = 0; i < (logicalSize + (moveCnt % logicalSize)); ++i) {
                LNext(&cList, &newBalloon);
            }
        }
        printf("%d ", newBalloon->index);
        moveCnt = LRemove(&cList);
    }


    return 0;
}