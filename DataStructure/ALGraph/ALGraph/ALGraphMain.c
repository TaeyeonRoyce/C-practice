#include <stdio.h>
#include "ALGraph.h"

int main() {
    ALGraph graph;

    //노드가 5개인 그래프 초기화
    GraphInit(&graph, 5);

    AddEdge(&graph, A, B);
    AddEdge(&graph, A, D);
    AddEdge(&graph, B, C);
    AddEdge(&graph, C, D);
    AddEdge(&graph, D, E);
    AddEdge(&graph, E, A);

    ShowGraphEdgeInfo(&graph);
    GraphDestroy(&graph);

    return 0;
}