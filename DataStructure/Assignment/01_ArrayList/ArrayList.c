#include <stdio.h>
#include "ArrayList.h"

void ListInit(List *plist) {
    (plist->numOfData) = 0;
    (plist->curPosition) = -1;
}

void LInsert(List *plist, LData data) {
    if (plist->numOfData >= LIST_LEN) {
        printf("저장이 불가합니다");
        return;
    }

    plist->arr[plist->numOfData] = data;
    (plist->numOfData)++;
    return;
}

int LFirst(List *plist, LData *pdata) {
    if (plist->numOfData == 0) {
        return FALSE;
    }

    plist->curPosition = 0;
    *pdata = plist->arr[0];
    return TRUE;
}

int LNext(List *plist, LData *pdata) {
    if (plist->curPosition >= plist->numOfData - 1) {
        return FALSE;
    }

    plist->curPosition++;
    *pdata = plist->arr[plist->curPosition];
    return TRUE;
}

LData LRemove(List *plist) {
    int removePosition = plist->curPosition;
    int num = plist->numOfData;
    int removeData = plist->arr[removePosition];

    //삭제된 위치를 기준으로 뒤의 데이터 당기기
    // 1, {removed}, 3, 4, 5 -> 1, 3, 4, 5
    for (int i = removePosition; i < num - 1; ++i) {
        plist->arr[i] = plist->arr[i + 1];
    }

    (plist->numOfData)--;
    (plist->curPosition)--;

    return removeData;
}

int LCount(List *plist) {
    return plist->numOfData;
}