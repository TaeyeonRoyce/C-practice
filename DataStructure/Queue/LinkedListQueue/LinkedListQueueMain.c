#include <stdio.h>
#include "LinkedListQueue.h"

/**
 * To Run this Source,
 * copy following texts and paste to CMakeLists.txt

   add_executable(
        DataStructure
        Queue/LinkedListQueue/LinkedListQueue.c
        Queue/LinkedListQueue/LinkedListQueue.h
        Queue/LinkedListQueue/LinkedListQueueMain.c
)

 */

int main(void) {
    Queue q;

    QueueInit(&q);

    Enqueue(&q, 1);Enqueue(&q, 2);
    Enqueue(&q, 3);Enqueue(&q, 4);
    Enqueue(&q, 5);Enqueue(&q, 6);

    while(!QIsEmpty(&q)) {
        printf("%d ", Dequeue(&q));
    }
    printf("\n");

    return 0;
}