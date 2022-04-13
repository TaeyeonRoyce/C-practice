//
// Created by ¿øÅÂ¿¬ on 2022/04/13.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define ASCII_UPPER_ALPHA_START 65;

typedef struct _node {
    int data;
    struct _node *before;
} Node;

typedef struct _stack {
    Node *cursor;
    int numOfData;
} Stack;

void initStack(Stack *pstack) {
    pstack->cursor = NULL;
    pstack->numOfData = 0;
}

void addData(Stack *pstack, int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    if (pstack->numOfData == 0) {
        newNode->before = NULL;
        pstack->cursor = newNode;
        pstack->numOfData++;
        return;
    }

    newNode->before = pstack->cursor;
    pstack->cursor = newNode;
    pstack->numOfData++;
    return;
}
int isEmpty(Stack *pstack) {
    if (pstack->numOfData > 0) {
        return 0;
    }
    return 1;
}

int pop(Stack *pstack) {
    Node *popNode = pstack->cursor;
    int popData = popNode->data;
    if (isEmpty(&pstack)) {
        printf("Stack is Empty\n");
        return 0;
    }
    pstack->cursor = popNode->before;
    free(popNode);

    return popData;
}

int peek(Stack *pstack) {
    return pstack->cursor->data;
}



int main() {
    int N;
    int num;
    char userInput[100];
    int numArray[N];
    scanf("%d", &N);
    scanf("%s", userInput);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &numArray[i]);
    }



    printf("%d\n%s\n",N,userInput);
    return 0;
}