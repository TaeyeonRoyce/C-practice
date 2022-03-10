#include <stdio.h>
#include <stdlib.h>
#include "LinkedListMatrixPoint.h"


void ListInit(List *plist) {
    plist->head = (Node *) malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->numOfData = 0;
    plist->comp = NULL;
}

void LInsert(List *plist, LData data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = plist->head->next;
    plist->head->next = newNode;
    (plist->numOfData)++;
}

int LFirst(List *plist, LData *pdata) {
    if (plist->head->next == NULL)
        return FALSE;

    plist->before = plist->head;
    plist->cur = plist->head->next;
    *pdata = plist->cur->data;

    return TRUE;
}

int LNext(List *plist, LData *pdata) {
    if (plist->cur->next == NULL)
        return FALSE;

    plist->before = plist->cur;
    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;

    return TRUE;
}

LData LRemove(List *plist) {
    Node *removedPosition = plist->cur;
    LData removedData = plist->cur->data;

    plist->before->next = plist->cur->next;
    plist->cur = plist->before;
    free(removedPosition);

    (plist->numOfData)--;

    return removedData;
}

int LCount(List *plist) {
    return plist->numOfData;
}
