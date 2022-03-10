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

    int (*comp)(LData d1, LData d2); //Sort기준이 될 int메서드(?)를 가리킴
} LinkedList;

typedef LinkedList List;

//리스트 초기화
void ListInit(List *plist);

//리스트 데이터 추가
void LInsert(List *plist, LData data);

int LFirst(List *plist, LData *pdata);
int LNext(List *plist, LData *pdata);

LData LRemove(List *plist);
int LCount(List *plist);

//Sort기준 설정
void SetSortRule(List *plist, int (*comp)(LData d1, LData d2));


#endif //DATASTRUCTURE_LINKEDLISTMATRIXPOINT_H
