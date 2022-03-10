#include <stdio.h>
#include "../DLinkedList.h"

//DLinkedList.h의 SInsert기준을 따르면,
//Sort 기준인 경우 0을 반환 해야함.

//현재의 경우 오름차순으로 정렬
int WhoIsPrecede(int d1, int d2) {
    //오름차순
    if(d1 < d2)
        return 0;
    else
        return 1;
}

int main(void) {
    List list;
    int data;
    ListInit(&list);

    //WhoIsPrecede로 Sort기준 설정
    SetSortRule(&list, WhoIsPrecede);

    LInsert(&list, 11);
    LInsert(&list, 11);
    LInsert(&list, 22);
    LInsert(&list, 22);
    LInsert(&list, 33);

    printf("현재 데이터 수 : %d\n", LCount(&list));
    if(LFirst(&list, &data)) {
        printf("%d ", data);

        while(LNext(&list, &data)) {
            printf("%d ", data);
        }
    }
    printf("\n\n");

    if(LFirst(&list, &data)) {
        if(data == 22)
            LRemove(&list);

        while(LNext(&list, &data)) {
            if(data == 22)
                LRemove(&list);
        }
    }

    printf("현재 데이터 수 : %d\n", LCount(&list));
    if(LFirst(&list, &data)) {
        printf("%d ", data);

        while(LNext(&list, &data)) {
            printf("%d ", data);
        }
    }
    printf("\n\n");

    return 0;
}