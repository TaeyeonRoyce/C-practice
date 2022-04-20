#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List *plist) {
    plist->head = (Node *) malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->numOfData = 0;
    plist->comp = NULL;
}

//Sort기준이 없는 경우,
void FInsert(List *plist, LData data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;

    //이전 노드가 새로운 노드를 가리키고,
    //새로운 노드가 이전노드가 가리키는 노드를 가리키게 함.
    // ex) 1 -> 2 -> 3
    // index 1에 4를 추가할 때,
    // 1 ----X---> 2 -> 3
    //   --> 4 -->
    newNode->next = plist->head->next;
    plist->head->next = newNode;

    plist->numOfData++;

}

void SInsert(List *plist, LData data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    //Sort 기준에 따라 data가 맨 앞에 위치할 수 있다.
    //pred라는 포인터는 처음(head)부터 Sort기준을 적용하기 위해 초기화 및 할당하였다.
    Node *pred = plist->head;

    newNode->data = data;

    //pred가 마지막 Node를 가리키거나
    //comp(data, pred->next->data) (Sort기준)을 만족할 때 까지
    //다음 노드로 이동
    while(pred->next != NULL
          && plist->comp(data, pred->next->data) != 0) {
        pred = pred->next;
    }

    if (data->exponent == pred->next->data->exponent) {
        data->coefficient += pred->next->data->coefficient;
        (plist->numOfData)++;
        return;
    }

    //데이터 추가
    newNode->next = pred->next;
    pred->next = newNode;

    (plist->numOfData)++;

}

//Sort기준의 유무에 따른 데이터 추가 로직 분리
void LInsert(List *plist, LData data) {
    if (plist->comp == NULL) {
        FInsert(plist, data);
        return;
    }

    SInsert(plist, data);
}

int LFirst(List *plist, LData *pdata) {
    //List가 비어 있으면 FALSE
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

    plist->before->next = plist->cur->next; //삭제될 노드의 참조 제거 후 참조 변경
    plist->cur = plist->before; //삭제될 노드의 참조 제거 및 이전 노드로 이동
    free(removedPosition); //더 이상 참조 되지 않는 노드(메모리) 해제

    (plist->numOfData)--;

    return removedData;
}

int LCount(List *plist) {
    return plist->numOfData;
}

void SetSortRule(List *plist, int (*comp)(LData data1, LData data2)) {
    plist->comp = comp;
}