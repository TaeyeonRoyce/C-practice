#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "../LinkedListStack/LinkedListStack.h"

int main() {
    int N;
    scanf("%d", &N);

    int ans;
    for (int i = 0; i < N; ++i) {
        Stack pairStack;
        StackInit(&pairStack);
        char userInput[100001];
        scanf("%s", userInput);


        printf("%s\n", userInput);
    }
}