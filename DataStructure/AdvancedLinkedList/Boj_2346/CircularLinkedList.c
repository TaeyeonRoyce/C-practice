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


//tail이 가리키는 노드의 다음(맨 앞)으로 추가
void LInsertFront(List *plist, Data data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;

    //list가 비어 있으면
    if (plist->tail == NULL) {
        //원형 연결 리스트에 값이 하나만 존재하는 경우
        //tail도 자기 자신을 가리켜야함
        plist->tail = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
    }

    (plist->numOfData)++;
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
};

int LRemove(List *plist) {

    Node *removedPosition = plist->cur;
    int removedData = removedPosition->data->moveCnt;

    //맨 마지막인 경우
    if (removedPosition == plist->tail) {
        //인덱스가 1인 경우
        if (plist->tail == plist->tail->next) {
            plist->tail = NULL;
        } else {
            plist->tail = plist->before; //tail을 before로 이동
        }
    }

    plist->before->next = plist->cur->next;
    plist->cur = plist->before;

    (plist->numOfData)--;

    free(removedPosition);
    return removedData;
};

int LCount(List *plist) {
    return plist->numOfData;
};

