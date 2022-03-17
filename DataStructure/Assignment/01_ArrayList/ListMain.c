#include <stdio.h>
#include "ArrayList.h"

void printList(List *list, char *data);

void removeDataOfList(char removeData, List *plist, char *data);

/**
 * 과제를 위한 필요 구현 내용
 * 1. char형 데이터 10개를 리스트에 추가
 * 2. 리스트에 저장된 데이터 2개 제거
 */
int main() {
    List list;
    char data;

    ListInit(&list);

    //char형 데이터 생성을 위한 초기 값(ASCII)
    data = 'A';

    //char 데이터 'A'부터 'J'까지(10개) 리스트에 저장
    for (int i = 0; i < 10; ++i) {

        if (i == 9) {//모든 데이터가 추가되는 시점에 breakPoint를 걸기 위함
            LInsert(&list, data + i);
            break;
        }

        LInsert(&list, data + i);
    }

    //리스트에 저장된 데이터를 출력하는 함수 추출
    //삭제 전, 후 반복되는 코드에 대한 재사용을 위함
    //구현 코드는 main(){} 아래에 있습니다.
    printList(&list, &data);

    //삭제할 데이터
    char removed_1, removed_2;
    removed_1 = 'A';
    removed_2 = 'H';

    //removeDataOfList(removeData, plist, data)
    //리스트(plist)의 삭제할 데이터(removeData)를 삭제
    //반복 되는 삭제 로직을 분리 하여 재사용 할 수 있도록 하였습니다.
    //구현 코드는 main(){} 아래에 있습니다.

    //removed_1('A')를 삭제
    removeDataOfList(removed_1, &list, &data);

    //removed_2('H')를 탐색 하여 삭제
    removeDataOfList(removed_2, &list, &data);

    printList(&list, &data);

    return 0;
}

void printList(List *list, char *data) {
    printf("현재 데이터의 수 : %d\n", LCount(list));
    if(LFirst(list, data)) {
        printf("%c ", (*data));

        while(LNext(list, data)) {
            printf("%c ", (*data));
        }
    }
    printf("\n\n");
}

void removeDataOfList(char removeData, List *plist, char *data) {
    if (LFirst(plist, data)) {
        if ((*data) == removeData) {
            LRemove(plist);
        }

        while (LNext(plist, data)) {
            if ((*data) == removeData) {
                LRemove(plist);
            }
        }
    }
}
