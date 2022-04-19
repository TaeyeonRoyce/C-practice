#include <stdio.h>
#include <stdlib.h>
#include "CircularLinkedList.h"

//�ʱ�ȭ
void ListInit(List *plist) {
    plist->tail = NULL;
    plist->cur = NULL;
    plist->before = NULL;
    plist->numOfData = 0;
};


//tail�� ����Ű�� ����� ����(�� ��)���� �߰�
void LInsertFront(List *plist, Data data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;

    //list�� ��� ������
    if (plist->tail == NULL) {
        //���� ���� ����Ʈ�� ���� �ϳ��� �����ϴ� ���
        //tail�� �ڱ� �ڽ��� �����Ѿ���
        plist->tail = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
    }

    (plist->numOfData)++;
};

//�� �ڿ� �߰�
//tail�� ����Ű�� ���� �����Ѵٴ� ��
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

    //cur = 0 �� ��(LFirst), before�� tail
    //�����̴ϱ�..!
    plist->before = plist->tail;
    plist->cur = plist->tail->next;

    *pdata = plist->cur->data;
    return TRUE;
};

int LNext(List *plist, Data *pdata) {
    if (plist->tail == NULL) {
        return FALSE;
    }

    //cur�������� �̵�!
    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;
    return TRUE;
};

int LRemove(List *plist) {

    Node *removedPosition = plist->cur;
    int removedData = removedPosition->data->moveCnt;

    //�� �������� ���
    if (removedPosition == plist->tail) {
        //�ε����� 1�� ���
        if (plist->tail == plist->tail->next) {
            plist->tail = NULL;
        } else {
            plist->tail = plist->before; //tail�� before�� �̵�
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

