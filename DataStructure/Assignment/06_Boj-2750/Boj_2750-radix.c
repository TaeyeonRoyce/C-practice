#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0
#define BUCKET_LEN 10

typedef int Data;

typedef struct _node {
    Data data;
    struct _node *next;
} Node;

typedef struct _lQueue {
    Node *front;
    Node *rear;
} LQueue;

typedef LQueue Queue;

void QueueInit(Queue *pq) {
    pq->front = NULL;
    pq->rear = NULL;
}

int QIsEmpty(Queue *pq) {
    if(pq->front == NULL)
        return TRUE;
    else
        return FALSE;
}

void Enqueue(Queue *pq, Data data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;

    if(QIsEmpty(pq)) {
        pq->front = newNode;
        pq->rear = newNode;
    }
    else {
        pq->rear->next = newNode;
        pq->rear = newNode;
    }
}

Data Dequeue(Queue *pq) {
    Node *delNode;
    Data retData;

    if(QIsEmpty(pq)) {
        printf("Queue Memory Error!\n");
        exit(-1);
    }

    delNode = pq->front;
    retData = delNode->data;

    pq->front = pq->front->next;

    free(delNode);
    return retData;
}

void RadixSort(int arr[], int num, int maxLen) {
//    Queue buckets[10];
    Queue *buckets = (Queue *)malloc(sizeof(Queue) * 10);
    int bi;
    int pos;
    int di;
    int divfac = 1;
    int radix;

    for(bi = 0 ; bi < 10; bi++) {
        QueueInit(&buckets[bi]);
    }

    for(pos = 0; pos < maxLen; pos++) {

        for(di = 0; di < num; di++) {
            radix = (arr[di] / divfac) % 10;
            Enqueue(&buckets[radix], arr[di]);
        }

        for(bi = 0, di = 0; bi < 10; bi++) {
            while(!QIsEmpty(&buckets[bi]))
                arr[di++] = Dequeue(&buckets[bi]);
        }

        divfac *= 10;
    }
}

int main() {

    int N;
    scanf("%d", &N);

    int *arr = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
    }

    RadixSort(arr, N, 4);
    for(int i = 0; i < N; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}