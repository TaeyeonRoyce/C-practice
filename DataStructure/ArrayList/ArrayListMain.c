#include <stdio.h>
#include "ArrayList.h"

int main() {

    //ArrayList 초기화
    List list;
    int data;
    ListInit(&list);

    //List에 데이터 추가
    LInsert(&list, 11);
    LInsert(&list, 11);
    LInsert(&list, 22);
    LInsert(&list, 22);
    LInsert(&list, 33);

    printf("size of list : %d \n", LCount(&list));


    //List탐색
    //List의 data를 처음부터 마지막까지 탐색하며
    //초기화한 int data에 값을 넣어 출력
    if (LFirst(&list, &data)) {
        printf("%d ", data);

        while (LNext(&list, &data)) {
            printf("%d ", data);
        }
    }

    printf("\n\n");

    //Remove in List
    //삭제하기 위해선 탐색이 선행되어야 함
    //ex) 22 삭제
    if (LFirst(&list, &data)) {

        if (data == 22) {
            LRemove(&list);
        }
        while (LNext(&list, &data)) {
            if (data == 22) {
                LRemove(&list);
            }
        }
    }

    //삭제후 달라진 List size출력
    printf("size of list : %d \n", LCount(&list));
    if (LFirst(&list, &data)) {
        printf("%d ", data);

        while (LNext(&list, &data)) {
            printf("%d ", data);
        }
    }


}