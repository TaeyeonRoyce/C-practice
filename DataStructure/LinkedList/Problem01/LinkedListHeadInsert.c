#include <stdio.h>
#include <stdlib.h>
#include "LinkedListHeadInsert.h"

void ListInit(List *plist) {
    plist->head = (Node *) malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->numOfData = 0;
}

void HeadInsert(List *plist, LData data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;

    if (plist->head->next == NULL) {
        plist->head->next = newNode;
    }else {
        newNode->next = plist->head->next;
        plist->head->next = newNode;
    }

    plist->numOfData++;
}

int LFirst(List *plist, LData *pdata) {
    //List가 비어 있으면 FALSE
    if (plist->head->next == NULL) {
        return FALSE;
    }
    plist->cur = plist->head->next;
    *pdata = plist->cur->data;

    return TRUE;
}


int LNext(List *plist, LData *pdata) {
    if(plist->cur->next == NULL) {
        return FALSE;
    }

    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;

    return TRUE;
}

int LCount(List *plist) {
    return plist->numOfData;
}