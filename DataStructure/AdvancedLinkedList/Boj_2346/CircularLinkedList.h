//
// Created by 원태연 on 2022/04/19.
//

#ifndef DATASTRUCTURE_CIRCULARLINKEDLIST_H
#define DATASTRUCTURE_CIRCULARLINKEDLIST_H

#define TRUE 1
#define FALSE 0

#include "Balloon.h"

typedef Balloon *Data;

typedef struct _node {
    Data data;
    struct _node *next;
} Node;

typedef struct _CLL {
    //tail을 설정하여 원형List에 적합하게 사용 가능
    Node *tail;
    Node *cur;
    Node *before;
    int numOfData;
} CList;

typedef CList List;

void ListInit(List *plist);

void LInsert(List *plist, Data data);

void LInsertFront(List *plist, Data data);

int LFirst(List *plist, Data *pdata);

int LNext(List *plist, Data *pdata);

int LRemove(List *plist);

int LCount(List *plist);

#endif //DATASTRUCTURE_CIRCULARLINKEDLIST_H
