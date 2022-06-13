#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char* HData;
typedef int PriorityComp(HData data1, HData data2);

typedef struct _heap {
    PriorityComp *comp;
    int numOfData;
    HData heapArr[HEAP_LEN];
} Heap;

typedef Heap PQueue;
typedef HData PQData;

void HeapInit(Heap *ph, PriorityComp pc) {
    ph->numOfData = 0;
    ph->comp = pc;
}

int HIsEmpty(Heap *ph) {
    if(ph->numOfData == 0)
        return TRUE;
    else
        return FALSE;
}

int GetParentIDX(int idx) {
    return idx / 2;
}

int GetLChildIDX(int idx) {
    return idx * 2;
}

int GetRChildIDX(int idx) {
    return GetLChildIDX(idx) + 1;
}

int GetHiPriChildIDX(Heap *ph, int idx) {
    if(GetLChildIDX(idx) > ph->numOfData)
        return 0;
    else if(GetLChildIDX(idx) == ph->numOfData)
        return GetLChildIDX(idx);
    else {
        if(ph->comp(ph->heapArr[GetLChildIDX(idx)], ph->heapArr[GetRChildIDX(idx)]) > 0)
            return GetLChildIDX(idx);
        else
            return GetRChildIDX(idx);
    }
}

void HInsert(Heap *ph, HData data) {
    int idx = ph->numOfData + 1;

    while(idx != 1) {
        if(ph->comp(data, ph->heapArr[GetParentIDX(idx)]) < 0)
            break;
        ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
        idx = GetParentIDX(idx);
    }
    ph->heapArr[idx] = data;
    ph->numOfData += 1;
}

HData HDelete(Heap *ph) {
    HData retData = ph->heapArr[1];
    HData lastElem = ph->heapArr[ph->numOfData];

    int parentIdx = 1;
    int childIdx;

    while((childIdx = GetHiPriChildIDX(ph, parentIdx))) {
        if(ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
            break;
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;
    }

    ph->heapArr[parentIdx] = lastElem;
    ph->numOfData -= 1;
    return retData;
}

void PQueueInit(PQueue *ppq, PriorityComp pc) {
    HeapInit(ppq, pc);
}

int PQIsEmpty(PQueue *ppq) {
    return HIsEmpty(ppq);
}

void PEnqueue(PQueue *ppq, PQData data) {
    HInsert(ppq, data);
}

PQData PDequeue(PQueue *ppq) {
    return HDelete(ppq);
}

int DataPriorityComp(char* ch1, char* ch2) {
    if (strlen(ch2) - strlen(ch1) == 0) {
        return strcmp(ch2, ch1);
    }

    return strlen(ch2) - strlen(ch1);

}


int main() {
    PQueue pQueue;
    PQueueInit(&pQueue, DataPriorityComp);

    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        char *str = (char *) malloc(sizeof(char) * 50);
        scanf("%s", str);
        PEnqueue(&pQueue, str);
    }

    char beforeStr[50];
    while(!PQIsEmpty(&pQueue)) {
        PQData dequeueStr = PDequeue(&pQueue);
        if (strcmp(beforeStr, dequeueStr) == 0) {
            continue;
        }
        printf("%s\n", dequeueStr);
        strcpy(beforeStr, dequeueStr);
    }

    return 0;

}

