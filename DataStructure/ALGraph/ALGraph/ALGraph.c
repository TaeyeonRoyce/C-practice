#include <stdio.h>
#include <stdlib.h>
#include "ALGraph.h"

//���� �켱����
int WhoIsPrecede(int data1, int data2);

void GraphInit(ALGraph *pg, int nv) {
    int i;

    //����� ������ŭ LinkedList�迭 ����
    pg->adjList = (List *)malloc(sizeof(List) * nv);
    pg->numV = nv; //����� ��
    pg->numE = 0;  //������ ��

    //LinkedList �迭 �ʱ�ȭ
    for(i = 0; i < nv; i++) {
        ListInit(&(pg->adjList[i]));
        SetSortRule(&(pg->adjList[i]), WhoIsPrecede); //LinkedList�� �켱���� �Լ�
    }
}

//��� ����Ʈ�� �湮�ϸ� ��������
void GraphDestroy(ALGraph *pg) {
    if(pg->adjList != NULL)
        free(pg->adjList);
}

//from -> to
//
void AddEdge(ALGraph *pg, int fromV, int toV) {
    LInsert(&(pg->adjList[fromV]), toV); //from - to ���� �߰�
    LInsert(&(pg->adjList[toV]), fromV); //to - from ���� �߰� (������� ��� �Ѵ� �߰���)
    pg->numE += 1; //���� ���� +1
}

void ShowGraphEdgeInfo(ALGraph *pg) {
    int i;
    int vx;

    for(i = 0; i < pg->numV; i++) {
        printf("%c�� ����� ����: ", i + 65); //ASCII A = 65

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