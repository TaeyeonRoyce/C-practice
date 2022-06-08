#include <stdio.h>
#include "ALGraphBFS.h"

int main(void) {
    ALGraph graph;

    //크기가 7인 그래프 생성
    GraphInit(&graph, 7);

    //간선 추가
    AddEdge(&graph, A, B);
    AddEdge(&graph, A, D);
    AddEdge(&graph, B, C);
    AddEdge(&graph, D, C);
    AddEdge(&graph, D, E);
    AddEdge(&graph, E, F);
    AddEdge(&graph, E, G);

    ShowGraphEdgeInfo(&graph);

    BFShowGraphVertex(&graph, A);printf("\n"); //A노드 부터 BFS탐색
    BFShowGraphVertex(&graph, C);printf("\n"); //C노드 부터 BFS탐색
    BFShowGraphVertex(&graph, E);printf("\n"); //E노드 부터 BFS탐색
    BFShowGraphVertex(&graph, G);printf("\n"); //G노드 부터 BFS탐색

    GraphDestroy(&graph);
    return 0;
}