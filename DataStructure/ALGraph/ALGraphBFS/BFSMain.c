#include <stdio.h>
#include "ALGraphBFS.h"

int main(void) {
    ALGraph graph;

    //ũ�Ⱑ 7�� �׷��� ����
    GraphInit(&graph, 7);

    //���� �߰�
    AddEdge(&graph, A, B);
    AddEdge(&graph, A, D);
    AddEdge(&graph, B, C);
    AddEdge(&graph, D, C);
    AddEdge(&graph, D, E);
    AddEdge(&graph, E, F);
    AddEdge(&graph, E, G);

    ShowGraphEdgeInfo(&graph);

    BFShowGraphVertex(&graph, A);printf("\n"); //A��� ���� BFSŽ��
    BFShowGraphVertex(&graph, C);printf("\n"); //C��� ���� BFSŽ��
    BFShowGraphVertex(&graph, E);printf("\n"); //E��� ���� BFSŽ��
    BFShowGraphVertex(&graph, G);printf("\n"); //G��� ���� BFSŽ��

    GraphDestroy(&graph);
    return 0;
}