#ifndef DATASTRUCTURE_LINKEDLISTHEADINSERT_H
#define DATASTRUCTURE_LINKEDLISTHEADINSERT_H

#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node {
    LData data;
    struct _node *next;
} Node;

typedef struct _linkedList {
    Node *head;
    Node *cur;
    int numOfData;
} LinkedList;

typedef LinkedList List;

//리스트 초기화
void ListInit(List *plist);

//리스트 데이터 추가
void HeadInsert(List *plist, LData data);

int LFirst(List *plist, LData *pdata);
int LNext(List *plist, LData *pdata);

int LCount(List *plist);

#endif;
