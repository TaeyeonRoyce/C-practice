#ifndef DATASTRUCTURE_DLINKEDLIST_H
#define DATASTRUCTURE_DLINKEDLIST_H

#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node {
    LData data;
    struct _node *next;
} Node;

/**
 * DLinkedList (Dummy Linked List)
 * 헤더가 가리키는 아무 정보가 없는 Dummy 노드를 추가하여
 * 실질적인 첫번째 노드에만 달리 적용해야 하는 로직을 덜어줄 수 있음.
 */
typedef struct _linkedList {
    Node *head;
    Node *cur;
    Node *before; //삭제 로직을 위함
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

#endif; //DATASTRUCTURE_DLINKEDLIST_
