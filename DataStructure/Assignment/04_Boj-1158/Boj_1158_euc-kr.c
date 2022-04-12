//VS로 실행하는 경우 오류 방지

//
// Created by 원태연 on 2022/04/07.
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


//main 로직
int main() {
    int N;
    int K;
    int maxSearch;
    scanf("%d %d",&N,&K);
    List circularList;
    ListInit(&circularList);

    //1 ~ N의 값을 가지는 원형 리스트 생성
    for (int i = 0; i < N; ++i) {
        LInsert(&circularList, i + 1);
    }

    printf("<"); //출력 조건을 위해 "<"로 시작
    maxSearch = N * K; //반복문을 위한 최대 경우의 수 설정. for문을 사용하여 이동 횟수를 세고, 초기화 하는 로직 제거
    for (int i = 1; i < maxSearch + 1; ++i) { //1부터 시작
        if (IsLast(&circularList)) { //마지막인 경우, 출력 형식이 다름
            int removedData = LRemove(&circularList);
            printf("%d>", removedData);
            break;
        }
        if (i % K == 0) { //K만큼 이동하면 해당 값 제거 및 출력
            int removedData = LRemove(&circularList);
            printf("%d, ", removedData);
        }
        LMoveCur(&circularList); //커서 이동
    }
}
//출력 형식
//<3, 6, 2, 7, 5, 1, 4>

