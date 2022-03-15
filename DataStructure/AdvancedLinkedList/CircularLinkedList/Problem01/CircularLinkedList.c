#include <stdio.h>
#include <stdlib.h>
#include "CircularLinkedList.h"

//초기화
void ListInit(List *plist) {
    plist->tail = NULL;
    plist->cur = NULL;
    plist->before = NULL;
    plist->numOfData = 0;
};

//맨 뒤에 추가
//tail이 가리키는 노드로 설정한다는 뜻
void LInsert(List *plist, Data data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;

    if (plist->tail == NULL) {
        plist->tail = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
        plist->tail = newNode;
    }

    (plist->numOfData)++;
};


int LFirst(List *plist, Data *pdata) {
    if (plist->tail == NULL) {
        return FALSE;
    }

    //cur = 0 일 때(LFirst), before는 tail
    //원형이니까..!
    plist->before = plist->tail;
    plist->cur = plist->tail->next;

    *pdata = plist->cur->data;
    return TRUE;
};

int LNext(List *plist, Data *pdata) {
    if (plist->tail == NULL) {
        return FALSE;
    }

    //cur기준으로 이동!
    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;
    return TRUE;
}

int LCount(List *plist) {
    return plist->numOfData;
};

