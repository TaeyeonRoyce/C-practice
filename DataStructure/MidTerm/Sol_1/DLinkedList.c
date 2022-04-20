#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List *plist) {
    plist->head = (Node *) malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->numOfData = 0;
    plist->comp = NULL;
}

//Sort������ ���� ���,
void FInsert(List *plist, LData data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;

    //���� ��尡 ���ο� ��带 ����Ű��,
    //���ο� ��尡 ������尡 ����Ű�� ��带 ����Ű�� ��.
    // ex) 1 -> 2 -> 3
    // index 1�� 4�� �߰��� ��,
    // 1 ----X---> 2 -> 3
    //   --> 4 -->
    newNode->next = plist->head->next;
    plist->head->next = newNode;

    plist->numOfData++;

}

void SInsert(List *plist, LData data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    //Sort ���ؿ� ���� data�� �� �տ� ��ġ�� �� �ִ�.
    //pred��� �����ʹ� ó��(head)���� Sort������ �����ϱ� ���� �ʱ�ȭ �� �Ҵ��Ͽ���.
    Node *pred = plist->head;

    newNode->data = data;

    //pred�� ������ Node�� ����Ű�ų�
    //comp(data, pred->next->data) (Sort����)�� ������ �� ����
    //���� ���� �̵�
    while(pred->next != NULL
          && plist->comp(data, pred->next->data) != 0) {
        pred = pred->next;
    }

    if (data->exponent == pred->next->data->exponent) {
        data->coefficient += pred->next->data->coefficient;
        (plist->numOfData)++;
        return;
    }

    //������ �߰�
    newNode->next = pred->next;
    pred->next = newNode;

    (plist->numOfData)++;

}

//Sort������ ������ ���� ������ �߰� ���� �и�
void LInsert(List *plist, LData data) {
    if (plist->comp == NULL) {
        FInsert(plist, data);
        return;
    }

    SInsert(plist, data);
}

int LFirst(List *plist, LData *pdata) {
    //List�� ��� ������ FALSE
    if (plist->head->next == NULL) {
        return FALSE;
    }

    plist->before = plist->head;
    plist->cur = plist->head->next;
    *pdata = plist->cur->data;

    return TRUE;
}


int LNext(List *plist, LData *pdata) {
    if(plist->cur->next == NULL) {
        return FALSE;
    }

    plist->before = plist->cur;
    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;

    return TRUE;
}

LData LRemove(List *plist) {
    Node *removedPosition = plist->cur;
    LData removedData = plist->cur->data;

    plist->before->next = plist->cur->next; //������ ����� ���� ���� �� ���� ����
    plist->cur = plist->before; //������ ����� ���� ���� �� ���� ���� �̵�
    free(removedPosition); //�� �̻� ���� ���� �ʴ� ���(�޸�) ����

    (plist->numOfData)--;

    return removedData;
}

int LCount(List *plist) {
    return plist->numOfData;
}

void SetSortRule(List *plist, int (*comp)(LData data1, LData data2)) {
    plist->comp = comp;
}