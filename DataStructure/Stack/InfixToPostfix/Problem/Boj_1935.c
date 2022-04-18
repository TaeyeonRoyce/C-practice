//
// Created by ¿øÅÂ¿¬ on 2022/04/13.
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_UPPER_ALPHA_START 65;

typedef struct _node {
    double data;
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

void addData(Stack *pstack, double data) {
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

float pop(Stack *pstack) {
    Node *popNode = pstack->cursor;
    double popData = popNode->data;
    if (isEmpty(&pstack)) {
        printf("Stack is Empty\n");
        return 0;
    }
    pstack->cursor = popNode->before;
    free(popNode);

    return popData;
}

float peek(Stack *pstack) {
    return pstack->cursor->data;
}

int isOperator(char tok) {
    if (tok == '*' || tok == '+' || tok == '/' || tok == '-') {
        return 1;
    }
    return 0;
}


int main() {
    int N;
    char userInput[50];
    scanf("%d", &N);
    scanf("%s", userInput);
    double numArray[N];
    for (int i = 0; i < N; i++) {
        scanf("%lf", &numArray[i]);
    }
    Stack stack;
    initStack(&stack);
    for (int i = 0; i < strlen(userInput); i++) {
        char tok = userInput[i];
        if (isOperator(tok)) {
            double num2 = pop(&stack);
            double num1 = pop(&stack);
            if (tok == '*') {
                addData(&stack, num1 * num2);
            } else if (tok == '/') {
                addData(&stack, num1 / num2);
            } else if (tok == '+') {
                addData(&stack, num1 + num2);
            } else if (tok == '-') {
                addData(&stack, num1 - num2);
            }
        } else {
            addData(&stack, numArray[tok - 65]);
        }
    }
    printf("%.2lf\n", peek(&stack));

    return 0;
}