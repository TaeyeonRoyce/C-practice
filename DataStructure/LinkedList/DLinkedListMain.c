#include <stdio.h>
#include "DLinkedList.h"

int main(void) {
    List list;
    LData data;
    ListInit(&list);

    //데이터 저장
    LInsert(&list, 11);
    LInsert(&list, 11);
    LInsert(&list, 22);
    LInsert(&list, 22);
    LInsert(&list, 33);

    printf("현재 데이더의 수: %d\n", LCount(&list));

    if(LFirst(&list, &data)) {
        printf("%d ", data);

        while(LNext(&list, &data)) {
            printf("%d ", data);
        }
    }
    printf("\n\n");

    //데이터가 22인 노드 삭제
    if(LFirst(&list, &data)) {
        if(data == 22)
            LRemove(&list);

        while(LNext(&list, &data)) {
            if(data == 22)
                LRemove(&list);
        }
    }

    //삭제 후 변경된 LinkedList 출력
    printf("현재 데이더의 수: %d\n", LCount(&list));

    if(LFirst(&list, &data)) {
        printf("%d ", data);

        while(LNext(&list, &data)) {
            printf("%d ", data);
        }
    }
    printf("\n\n");

    return 0;
}