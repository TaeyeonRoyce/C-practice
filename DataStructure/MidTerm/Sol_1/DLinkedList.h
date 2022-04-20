#ifndef DATASTRUCTURE_DLINKEDLIST_H
#define DATASTRUCTURE_DLINKEDLIST_H

#define TRUE 1
#define FALSE 0

#include "Nomial.h"
typedef Nomial *LData;

typedef struct _node {
    LData data;
    struct _node *next;
} Node;

/**
 * DLinkedList (Dummy Linked List)
 * ����� ����Ű�� �ƹ� ������ ���� Dummy ��带 �߰��Ͽ�
 * �������� ù��° ��忡�� �޸� �����ؾ� �ϴ� ������ ������ �� ����.
 */
typedef struct _linkedList {
    Node *head;
    Node *cur;
    Node *before; //���� ������ ����
    int numOfData;

    int (*comp)(LData d1, LData d2); //Sort������ �� int�޼���(?)�� ����Ŵ
} LinkedList;

typedef LinkedList List;

//����Ʈ �ʱ�ȭ
void ListInit(List *plist);

//����Ʈ ������ �߰�
void LInsert(List *plist, LData data);

int LFirst(List *plist, LData *pdata);
int LNext(List *plist, LData *pdata);

LData LRemove(List *plist);
int LCount(List *plist);

void SetSortRule(List *plist, int (*comp)(LData data1, LData data2));

#endif //DATASTRUCTURE_DLINKEDLIST_H
