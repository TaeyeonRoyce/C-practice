#ifndef DATASTRUCTURE_ALGRAPH_H
#define DATASTRUCTURE_ALGRAPH_H

#include "DLinkedList.h"

enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ual {
    int numV;
    int numE;
    List *adjList;
} ALGraph;

void GraphInit(ALGraph *pg, int nv);
void GraphDestroy(ALGraph *pg);
void AddEdge(ALGraph *pg, int fromV, int toV);
void ShowGraphEdgeInfo(ALGraph *pg);

#endif //DATASTRUCTURE_ALGRAPH_H
