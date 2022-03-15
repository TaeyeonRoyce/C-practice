#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"


//Node자체에서 양방향으로 참조하고 있기 때문에
//tail, before와 같은 멤버가 필요 없다
void ListInit(List *plist) {
    plist->head = NULL;
    plist->numOfData = 0;
}

void LInsert(List *plist, LData data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = plist->head;

    //두 번째 이상의 노드인 경우 prev를 기존 노드로 지정
    if(plist->head != NULL) {
        plist->head->prev = newNode;
    }

    newNode->prev = NULL;
    plist->head = newNode;

    (plist->numOfData)++;
}

int LFirst(List *plist, LData *pdata) {
    if(plist->head == NULL)
        return FALSE;

    plist->cur = plist->head;
    *pdata = plist->cur->data;

    return TRUE;
}

int LNext(List *plist, LData *pdata) {
    if(plist->cur->next == NULL)
        return FALSE;

    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;

    return TRUE;
}

int LPrevious(List *plist, LData *pdata) {
    if(plist->cur->prev == NULL)
        return FALSE;

    plist->cur = plist->cur->prev;
    *pdata = plist->cur->data;

    return TRUE;
}

int LCount(List *plist) {
    return plist->numOfData;
}