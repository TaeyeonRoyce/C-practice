#ifndef DATASTRUCTURE_CIRCULARQUEUE_H
#define DATASTRUCTURE_CIRCULARQUEUE_H

#define TRUE 1
#define FALSE 0

#define QUE_LEN 100
typedef int Data;

typedef struct _cQueue {
    int front;
    int rear;
    Data queArr[QUE_LEN]; //배열 기반
} CQueue;

typedef CQueue Queue;

void QueueInit(Queue *pq);

int QIsEmpty(Queue *pq);

void Enqueue(Queue *pq, Data data);

Data Dequeue(Queue *pq);

Data QPeek(Queue *pq);

#endif //DATASTRUCTURE_CIRCULARQUEUE_H
