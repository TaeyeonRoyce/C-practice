//VS�� �����ϴ� ��� ���� ����

//
// Created by ���¿� on 2022/04/07.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct _node {
    int data;
    struct _node *next;
} Node;

typedef struct _clinkedList {
    Node *tail;
    Node *cur;
    Node *before;
    int numData;
} List;

void ListInit(List *plist) {
    plist->tail = NULL;
    plist->cur = NULL;
    plist->before = NULL;
    plist->numData = 0;
};

void LInsert(List *plist, int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;

    if (plist->tail == NULL) {
        plist->tail = newNode;
        newNode->next = newNode;

        plist->cur = newNode;
        plist->before = newNode;
    } else {
        newNode->next = plist->tail->next; //���� ����Ʈ ����
        plist->tail->next = newNode;
        plist->tail = newNode;
    }
    plist->numData++;
}

int LRemove(List *plist) {

    Node *removedPosition = plist->cur;
    int removedData = removedPosition->data;

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

    plist->numData--;
    free(removedPosition);
    return removedData;
}

void LMoveCur(List *plist) {
    if (plist->cur != plist->before) {
        plist->before = plist->cur;
    }

    plist->cur = plist->cur->next;
}

int IsLast(List *plist) {
    return plist->numData == 1;
}


//main ����
int main() {
    int N;
    int K;
    int maxSearch;
    scanf("%d %d",&N,&K);
    List circularList;
    ListInit(&circularList);

    //1 ~ N�� ���� ������ ���� ����Ʈ ����
    for (int i = 0; i < N; ++i) {
        LInsert(&circularList, i + 1);
    }

    printf("<"); //��� ������ ���� "<"�� ����
    maxSearch = N * K; //�ݺ����� ���� �ִ� ����� �� ����. for���� ����Ͽ� �̵� Ƚ���� ����, �ʱ�ȭ �ϴ� ���� ����
    for (int i = 1; i < maxSearch + 1; ++i) { //1���� ����
        if (IsLast(&circularList)) { //�������� ���, ��� ������ �ٸ�
            int removedData = LRemove(&circularList);
            printf("%d>", removedData);
            break;
        }
        if (i % K == 0) { //K��ŭ �̵��ϸ� �ش� �� ���� �� ���
            int removedData = LRemove(&circularList);
            printf("%d, ", removedData);
        }
        LMoveCur(&circularList); //Ŀ�� �̵�
    }
}
//��� ����
//<3, 6, 2, 7, 5, 1, 4>

