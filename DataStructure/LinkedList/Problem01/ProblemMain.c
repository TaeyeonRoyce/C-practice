/**
 * 문제 1.
 * LinkedList에 데이터가 추가 될때,
 * tail이 아닌 head에 추가 되도록 변경
 * ex) insert 3, 4, 5, 6
 * -> [6, 5, 4, 3]
 */

/**
 * To Run this Source,
 * copy following texts and paste to CMakeLists.txt

   add_executable(
        DataStructure
        LinkedList/Problem01/LinkedListHeadInsert.h
        LinkedList/Problem01/LinkedListHeadInsert.c
        LinkedList/Problem01/ProblemMain.c
    )

 */

#include <stdio.h>
#include "LinkedListHeadInsert.h"

int main() {
    List *list;
    LData data;

    ListInit(&list);

    HeadInsert(&list, 3);
    HeadInsert(&list, 4);
    HeadInsert(&list, 5);
    HeadInsert(&list, 6);

    printf("현재 데이터 수 : %d\n", LCount(&list));
    if(LFirst(&list, &data)) {
        printf("%d ", data);

        while(LNext(&list, &data)) {
            printf("%d ", data);
        }
    }

    return 0;
}



