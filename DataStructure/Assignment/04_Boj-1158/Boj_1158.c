//
// Created by 원태연 on 2022/04/07.
//

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
        newNode->next = plist->tail->next; //원형 리스트 유지
        plist->tail->next = newNode;
        plist->tail = newNode;
    }
    plist->numData++;
}

int LRemove(List *plist) {

    Node *removedPosition = plist->cur;
    int removedData = removedPosition->data;

    //맨 마지막인 경우
    if (removedPosition == plist->tail) {
        //인덱스가 1인 경우
        if (plist->tail == plist->tail->next) {
            plist->tail = NULL;
        } else {
            plist->tail = plist->before; //tail을 before로 이동
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

int main() {
    char OPEN_WRAPPER = "<";
    char CLOSE_WRAPPER = ">";
    int N;
    int K;
    int maxSearch;
    scanf("%d %d",&N,&K);
    List circularList;
    ListInit(&circularList);

    for (int i = 0; i < N; ++i) {
        LInsert(&circularList, i + 1);
    }

    printf("<", OPEN_WRAPPER);
    maxSearch = N * K;
    for (int i = 1; i < maxSearch + 1; ++i) {
        if (IsLast(&circularList)) {
            int removedData = LRemove(&circularList);
            printf("%d>", removedData, CLOSE_WRAPPER);
            break;
        }
        if (i % K == 0) {
            int removedData = LRemove(&circularList);
            printf("%d, ", removedData);
        }
        LMoveCur(&circularList);
    }
}