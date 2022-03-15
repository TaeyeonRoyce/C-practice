#ifndef DATASTRUCTURE_LINKEDLISTMATRIXPOINT_H
#define DATASTRUCTURE_LINKEDLISTMATRIXPOINT_H

#define TRUE 1
#define FALSE 0

#include "../../ArrayList/MatrixPoint/MatrixPoint.h"

typedef MatrixPoint *LData;

typedef struct _node {
    LData data;
    struct _node *next;
} Node;

typedef struct _linkedList {
    Node *head;
    Node *cur;
    Node *before;
    int numOfData;

    int (*comp)(LData d1, LData d2);
} LinkedList;

typedef LinkedList List;

void ListInit(List *plist);

void LInsert(List *plist, LData data);

int LFirst(List *plist, LData *pdata);

int LNext(List *plist, LData *pdata);

LData LRemove(List *plist);

int LCount(List *plist);


#endif //DATASTRUCTURE_LINKEDLISTMATRIXPOINT_H