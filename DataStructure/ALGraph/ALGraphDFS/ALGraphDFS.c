#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DLinkedList.h"
#include "ArrayBaseStack.h"
#include "ALGraphDFS.h"

int WhoIsPrecede(int data1, int data2) {
    if(data1 > data2)
        return 1;
    else
        return 0;
}

void GraphInit(ALGraph *pg, int nv) {
    int i;

    pg->adjList = (List *)malloc(sizeof(List) * nv);
    pg->numV = nv;
    pg->numE = 0;

    for(i = 0; i < nv; i++) {
        ListInit(&(pg->adjList[i]));
        SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
    }

    //방문 정보 배열 초기화
    pg->visitInfo = (int *)malloc(sizeof(int) * pg->numV);
    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
    //방문 전 = 0, 방문 후 = 1
    //memset을 통해 방문 전 상태(0)로 설정
}

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

//방문했던 노드인지 확인
//방문 했으면 return 1, 아니면 0
int VisitVertex(ALGraph *pg, int visitV) {
    if(pg->visitInfo[visitV] == 0) {
        pg->visitInfo[visitV] = 1;
        printf("%c ", visitV + 65);
        return TRUE;
    }
    return FALSE;
}

//DFS탐색
void DFShowGraphVertex(ALGraph *pg, int startV) {
    Stack stack; //Stack을 활용하여 DFS순서 보장
    int visitV = startV; //현재 탐색하는 노드
    int nextV;
    StackInit(&stack); //Stack Init
    VisitVertex(pg, visitV); //시작 노드 방문 적용 상태 변화
    SPush(&stack, visitV); //Stack에 Push하여 깊이 우선 탐색 진행

    while(LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) {
        int visitFlag = FALSE;

        //방문 했다면
        if(VisitVertex(pg, nextV) == TRUE) {
            SPush(&stack, visitV); //다음 깊이로 이동
            visitV = nextV; //다음 깊이로 이동
            visitFlag = TRUE; //방문 변화
        }
        else { //방문을 못했다면 (이미 방문된 노드거나 다음이 없는 경우)
            while(LNext(&(pg->adjList[visitV]), &nextV) == TRUE) { //다른 간선(노드)로 이동
                if(VisitVertex(pg, nextV) == TRUE) {
                    SPush(&stack, visitV);
                    visitV = nextV;
                    visitFlag = TRUE;
                    break;
                }
            }
        }

        //모두 돌고와서 visitFlag == FALSE이면
        if(visitFlag == FALSE) {
            if(SIsEmpty(&stack) == TRUE) //스택이 비어있으면 모두 방문 완료
                break;
            else // Stack에 저장되어있는 순서로 깊이 탐색 시작
                visitV = SPop(&stack);
        }
    }
    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}