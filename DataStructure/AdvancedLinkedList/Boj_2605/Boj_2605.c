#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "LinkedListStack.h"

int main() {
    int N;
    scanf("%d", &N);

    Stack mainStack;
    Stack demonStack;
    StackInit(&mainStack);
    StackInit(&demonStack);


    int sequence;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &sequence);
        for (int j = 0; j < sequence; ++j) {
            SPush(&demonStack, SPop(&mainStack));
        }
        SPush(&mainStack, i + 1);
        while (!IsEmpty(&demonStack)) {
            SPush(&mainStack, SPop(&demonStack));
        }
    }

    while(!IsEmpty(&mainStack)) {
        SPush(&demonStack, SPop(&mainStack));
    }

    while(!IsEmpty(&demonStack)) {
        Data num = SPop(&demonStack);
        printf("%d ", num);
    }
}