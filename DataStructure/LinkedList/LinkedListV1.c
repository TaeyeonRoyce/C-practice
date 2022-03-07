#include <stdio.h>
#include "ArrayList.h"

void ListInit(List *plist) {
    //초기화
    //numOfData는 0이고, curPosition는 아무 위치도 가르키지 않는다.
    (plist->numOfData) = 0;
    (plist->curPosition) = -1;
}

void LInsert(List *plist, LData data) {
    //맨 뒤에 추가
    //사이즈보다 큰 경우 저장 불가
    if (plist->numOfData >= LIST_LEN) {
        printf("저장이 불가합니다");
        return;
    }

    //추가 후 numOfData증가
    plist->arr[plist->numOfData] = data;
    plist->numOfData++;
}

int LFirst(List *plist, LData *pdata) {
    //List 유무 체크
    if (plist->numOfData == 0) {
        return FALSE;
    }

    //*pdata에 arr[0](첫 데이터) 저장
    plist->curPosition = 0;
    *pdata = plist->arr[0];
    return TRUE;
}

int LNext(List *plist, LData *pdata) {
    //Next Data가 있는지 체크
    if (plist->curPosition >= plist->numOfData - 1) {
        return FALSE;
    }

    //다음 데이터를 가리킴
    plist->curPosition++;
    *pdata = plist->arr[plist->curPosition];
    return TRUE;
}

LData LRemove(List *plist) {
    //curPosition의 데이터 삭제
    //삭제 후 줄어든 List에 대한 처리 필요
    //삭제 된 데이터 이후의 데이터들을 연속적으로 참조 가능하도록 하여야 함.

    int removePosition = plist->curPosition;
    int num = plist->numOfData;

    LData removeData = plist->arr[removePosition];

    //삭제된 위치를 기준으로 뒤의 데이터 당기기
    // 1, {removed}, 3, 4, 5 -> 1, 3, 4, 5
    for (int i = 0; i < num - 1; ++i) {
        plist->arr[i] = plist->arr[i + 1];
    }

    //크기 감소
    (plist->numOfData)--;

    //커서도 감소해야 함.
    (plist->curPosition)--;

    return removeData;
}



