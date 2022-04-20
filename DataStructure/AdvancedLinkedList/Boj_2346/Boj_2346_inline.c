//
// Created by 원태연 on 2022/04/19.
//

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0


typedef struct _balloon {
    int index;
    int moveCnt;
} Balloon;

typedef Balloon *Data;

typedef struct _node {
    Data data;
    struct _node *next;
} Node;

typedef struct _CLL {
    //tail을 설정하여 원형List에 적합하게 사용 가능
    Node *tail;
    Node *cur;
    Node *before;
    int numOfData;
} CList;

typedef CList List;

Balloon *MakeBalloon(int index, int moveCnt) {
    Balloon *newBalloon = (Balloon *) malloc(sizeof(Balloon));
    newBalloon->index = index;
    newBalloon->moveCnt = moveCnt;
    return newBalloon;
};

void ListInit(List *plist) {
    plist->tail = NULL;
    plist->cur = NULL;
    plist->before = NULL;
    plist->numOfData = 0;
};

//맨 뒤에 추가
//tail이 가리키는 노드로 설정한다는 뜻
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

    //cur = 0 일 때(LFirst), before는 tail
    //원형이니까..!
    plist->before = plist->tail;
    plist->cur = plist->tail->next;

    *pdata = plist->cur->data;
    return TRUE;
};

int LNext(List *plist, Data *pdata) {
    if (plist->tail == NULL) {
        return FALSE;
    }

    //cur기준으로 이동!
    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;
    return TRUE;
};

int LRemove(List *plist) {

    Node *removedPosition = plist->cur;
    int removedData = removedPosition->data->moveCnt;

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

    (plist->numOfData)--;

    free(removedPosition);
    return removedData;
};

int LCount(List *plist) {
    return plist->numOfData;
};

int main() {
    int N;
    CList cList;
    ListInit(&cList);
    scanf("%d", &N);

    int moveCnt;
    Balloon *newBalloon;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &moveCnt);
        newBalloon = MakeBalloon(i + 1, moveCnt);
        LInsert(&cList, newBalloon);
    }

    LFirst(&cList, &newBalloon);

    while(LCount(&cList) > 0) {
        if (newBalloon->index == 1) {
            printf("%d ", newBalloon->index);
            moveCnt = LRemove(&cList);
            if(LCount(&cList) < 1) {
                return 0;
            }
        }

        if (moveCnt > 0) {
            for (int i = 0; i < moveCnt; ++i) {
                LNext(&cList, &newBalloon);
            }
        } else {
            //(logicalSize + (moveCnt % logicalSize))
            //size가 5인 원형연결리스트에서 뒤로 7칸을 간다고 하면,
            //"1" 2 3 4 5 -> 1 2 3 "4" 5
            //앞으로 3칸 움직이는 것과 동일
            //5 + (-7 % 5) = 5 - 2 = 3
            int logicalSize = LCount(&cList);
            for (int i = 0; i < (logicalSize + (moveCnt % logicalSize) + 1); ++i) {
                LNext(&cList, &newBalloon);
            }
        }
        printf("%d ", newBalloon->index);
        moveCnt = LRemove(&cList);
    }


    return 0;
}