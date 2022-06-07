#include <stdio.h>
#include <stdlib.h>
#include "ALGraph.h"

//저장 우선순위
int WhoIsPrecede(int data1, int data2);

void GraphInit(ALGraph *pg, int nv) {
    int i;

    //노드의 갯수만큼 LinkedList배열 생성
    pg->adjList = (List *)malloc(sizeof(List) * nv);
    pg->numV = nv; //노드의 수
    pg->numE = 0;  //간선의 수

    //LinkedList 배열 초기화
    for(i = 0; i < nv; i++) {
        ListInit(&(pg->adjList[i]));
        SetSortRule(&(pg->adjList[i]), WhoIsPrecede); //LinkedList의 우선순위 함수
    }
}

//모든 리스트를 방문하며 지워야함
void GraphDestroy(ALGraph *pg) {
    if(pg->adjList != NULL)
        free(pg->adjList);
}

//from -> to
//
void AddEdge(ALGraph *pg, int fromV, int toV) {
    LInsert(&(pg->adjList[fromV]), toV); //from - to 간선 추가
    LInsert(&(pg->adjList[toV]), fromV); //to - from 간선 추가 (양방향인 경우 둘다 추가함)
    pg->numE += 1; //간선 갯수 +1
}

void ShowGraphEdgeInfo(ALGraph *pg) {
    int i;
    int vx;

    for(i = 0; i < pg->numV; i++) {
        printf("%c와 연결된 정점: ", i + 65); //ASCII A = 65

        if(LFirst(&(pg->adjList[i]), &vx)) {
            printf("%c ", vx + 65);

            while(LNext(&(pg->adjList[i]), &vx)) {
                printf("%c ", vx + 65);
            }
        }
        printf("\n");
    }
}

int WhoIsPrecede(int data1, int data2) {
    if(data1 < data2)
        return 0;
    else
        return 1;
}