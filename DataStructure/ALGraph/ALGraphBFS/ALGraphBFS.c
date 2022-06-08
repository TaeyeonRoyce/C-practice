#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DLinkedList.h"
#include "CircularQueue.h"
#include "ALGraphBFS.h"

int WhoIsPrecede(int data1, int data2) {
    if(data1 > data2)
        return 1;
    else
        return 0;
}

void GraphInit(ALGraph *pg, int nv) {
    int i;

    pg->adjList = (List *)malloc(sizeof(List) * nv); //LinkedList 배열 생성
    pg->numV = nv;
    pg->numE = 0;

    for(i = 0; i < nv; i++) {
        ListInit(&(pg->adjList[i])); //LinkedList 배열 초기화
        SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
    }

    pg->visitInfo = (int *)malloc(sizeof(int) * pg->numV);
    memset(pg->visitInfo, 0, sizeof(int) * pg->numV); //방문하지 않은 노드에 대해선 0으로 저장
}


//Deprecate
void GraphDestroy(ALGraph *pg) {
    if(pg->adjList != NULL)
        free(pg->adjList);

    if(pg->visitInfo != NULL)
        free(pg->visitInfo);
}

void AddEdge(ALGraph *pg, int fromV, int toV) {
    LInsert(&(pg->adjList[fromV]), toV);
    LInsert(&(pg->adjList[toV]), fromV);
    pg->numE += 1;
}


void ShowGraphEdgeInfo(ALGraph *pg) {
    int i;
    int vx;

    for(i = 0; i < pg->numV; i++) {
        printf("%c와 연결된 정점: ", i + 65);

        if(LFirst(&(pg->adjList[i]), &vx)) {
            printf("%c ", vx + 65);

            while(LNext(&(pg->adjList[i]), &vx)) {
                printf("%c ", vx + 65);
            }
            printf("\n");
        }
    }
}

int VisitVertex(ALGraph *pg, int visitV) {
    if(pg->visitInfo[visitV] == 0) {
        pg->visitInfo[visitV] = 1;
        printf("%c ", visitV + 65);
        return TRUE;
    }
    return FALSE;
}

void BFShowGraphVertex(ALGraph *pg, int startV) {
    Queue queue; //DFS랑 다르게 Stack이 아닌 Queue를 활용하여 진행 순서 보장
                 //Queue의 FIFO 특징을 통해 BFS순서 구현
    int visitV = startV;
    int nextV;

    QueueInit(&queue); //진행 순서 담을 Queue init
    VisitVertex(pg, visitV);

    while(LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) {
        if(VisitVertex(pg, nextV) == TRUE)
            Enqueue(&queue, nextV);

        while(LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {
            if(VisitVertex(pg, nextV) == TRUE)
                Enqueue(&queue, nextV);
        }

        if(QIsEmpty(&queue) == TRUE)
            break;
        else
            visitV = Dequeue(&queue);
    }
    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}