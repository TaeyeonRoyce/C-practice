#include <stdio.h>
#include "PriorityQueue.h"
#include <string.h>

int DataPriorityComp(char* ch1, char* ch2) {
    return strlen(ch2) - strlen(ch1);
}

int main() {
    PQueue pQueue;
    PQueueInit(&pQueue, DataPriorityComp);

    PEnqueue(&pQueue, "Good Morning");
    PEnqueue(&pQueue, "I am a boy");
    PEnqueue(&pQueue, "Priority Queue");
    PEnqueue(&pQueue, "Do you like coffee");
    PEnqueue(&pQueue, "I am so happy");

    while(!PQIsEmpty(&pQueue)) {
        printf("%s\n", PDequeue(&pQueue));
    }

    return 0;
}