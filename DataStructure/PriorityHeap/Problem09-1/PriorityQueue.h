#ifndef DATASTRUCTURE_PRIORITYQUEUE_H
#define DATASTRUCTURE_PRIORITYQUEUE_H

#include "UsefulHeap.h"

typedef Heap PQueue;
typedef HData PQData;

void PQueueInit(PQueue *ppq, PriorityComp pc);
int PQIsEmpty(PQueue *ppq);

void PEnqueue(PQueue *ppq, PQData data);
PQData PDequeue(PQueue *ppq);


#endif //DATASTRUCTURE_PRIORITYQUEUE_H
