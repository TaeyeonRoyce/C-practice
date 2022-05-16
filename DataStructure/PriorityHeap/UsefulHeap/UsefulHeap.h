//
// Created by ���¿� on 2022/05/16.
//

#ifndef DATASTRUCTURE_USEFULHEAP_H
#define DATASTRUCTURE_USEFULHEAP_H

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

//Heap ������ Ÿ��
typedef char HData;

//Heap �켱���� �Լ�
typedef int PriorityComp(HData data1, HData data2);

typedef struct _heap {
    PriorityComp *comp;
    int numOfData;
    HData heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap *ph, PriorityComp pc);
int HIsEmpty(Heap *ph);

void HInsert(Heap *ph, HData data);
HData HDelete(Heap *ph);

#endif //DATASTRUCTURE_USEFULHEAP_H
