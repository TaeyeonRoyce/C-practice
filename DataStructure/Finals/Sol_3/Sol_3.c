#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "ALGraphBFS.h"


int main() {
    ALGraph graph;

    int N, M, V;
    scanf("%d %d %d", &N, &M, &V);

    GraphInit(&graph, N);

    for (int i = 0; i < M; ++i) {
        int fromV, toV;
        scanf("%d %d", &fromV, &toV);
        AddEdge(&graph, fromV - 1, toV - 1);
    }

    BFShowGraphVertex(&graph, V - 1);; //A노드 부터 BFS탐색

    return 0;
}