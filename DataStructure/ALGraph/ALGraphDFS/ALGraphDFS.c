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

    //�湮 ���� �迭 �ʱ�ȭ
    pg->visitInfo = (int *)malloc(sizeof(int) * pg->numV);
    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
    //�湮 �� = 0, �湮 �� = 1
    //memset�� ���� �湮 �� ����(0)�� ����
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
        printf("%c�� ����� ����: ", i + 65);

        if(LFirst(&(pg->adjList[i]), &vx)) {
            printf("%c ", vx + 65);

            while(LNext(&(pg->adjList[i]), &vx)) {
                printf("%c ", vx + 65);
            }
            printf("\n");
        }
    }
}

//�湮�ߴ� ������� Ȯ��
//�湮 ������ return 1, �ƴϸ� 0
int VisitVertex(ALGraph *pg, int visitV) {
    if(pg->visitInfo[visitV] == 0) {
        pg->visitInfo[visitV] = 1;
        printf("%c ", visitV + 65);
        return TRUE;
    }
    return FALSE;
}

//DFSŽ��
void DFShowGraphVertex(ALGraph *pg, int startV) {
    Stack stack; //Stack�� Ȱ���Ͽ� DFS���� ����
    int visitV = startV; //���� Ž���ϴ� ���
    int nextV;
    StackInit(&stack); //Stack Init
    VisitVertex(pg, visitV); //���� ��� �湮 ���� ���� ��ȭ
    SPush(&stack, visitV); //Stack�� Push�Ͽ� ���� �켱 Ž�� ����

    while(LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) {
        int visitFlag = FALSE;

        //�湮 �ߴٸ�
        if(VisitVertex(pg, nextV) == TRUE) {
            SPush(&stack, visitV); //���� ���̷� �̵�
            visitV = nextV; //���� ���̷� �̵�
            visitFlag = TRUE; //�湮 ��ȭ
        }
        else { //�湮�� ���ߴٸ� (�̹� �湮�� ���ų� ������ ���� ���)
            while(LNext(&(pg->adjList[visitV]), &nextV) == TRUE) { //�ٸ� ����(���)�� �̵�
                if(VisitVertex(pg, nextV) == TRUE) {
                    SPush(&stack, visitV);
                    visitV = nextV;
                    visitFlag = TRUE;
                    break;
                }
            }
        }

        //��� ����ͼ� visitFlag == FALSE�̸�
        if(visitFlag == FALSE) {
            if(SIsEmpty(&stack) == TRUE) //������ ��������� ��� �湮 �Ϸ�
                break;
            else // Stack�� ����Ǿ��ִ� ������ ���� Ž�� ����
                visitV = SPop(&stack);
        }
    }
    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}