#ifndef DATASTRUCTURE_ALGRAPHDFS_H
#define DATASTRUCTURE_ALGRAPHDFS_H

#include "DLinkedList.h"

enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ual {
    int numV;
    int numE;
    List *adjList;
    int *visitInfo; //DFS를 위해 방문 정보를 저장하는 배열
} ALGraph;

void GraphInit(ALGraph *pg, int nv);
void GraphDestroy(ALGraph *pg);
void AddEdge(ALGraph *pg, int fromV, int toV);
void ShowGraphEdgeInfo(ALGraph *pg);
void DFShowGraphVertex(ALGraph *pg, int startV);

#endif //DATASTRUCTURE_ALGRAPHDFS_H
