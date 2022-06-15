#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "Heap.h"
#include "Assignment.h"
#include <stdlib.h>

int DataPriorityComp(Assignment a1, Assignment a2) {
    if (a2.score < a1.score) {
        return 1;
    } else {
        return 0;
    }
}

void HeapSort(Assignment arr[1000], int n, PriorityComp pc) {
    Heap heap;
    int i;

    HeapInit(&heap, pc);

    for(i = 0; i < n; i++) {
        HInsert(&heap, &arr[i]);
    }

    for(i = 0; i < n; i++) {
        arr[i] = HDelete(&heap);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    Assignment arr[1000];


    for (int i = 0; i < N; ++i) {
        int d, w;
        scanf("%d %d", &d, &w);
        Assignment *assignment = (Assignment *) malloc(sizeof(Assignment));
        SetAssign(assignment, d, w);
        arr[i] = *assignment;
    }
    HeapSort(arr, N, DataPriorityComp);

    return 0;
}