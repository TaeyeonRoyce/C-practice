//
// Created by ¿øÅÂ¿¬ on 2022/04/19.
//

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node {
    Data data;
    struct _node *next;
} Node;

typedef struct _listStack {
    Node *head;
} LinkedListStack;

typedef LinkedListStack Stack;

void StackInit(Stack *pstack) {
    pstack->head = NULL;
}

int IsEmpty(Stack *pstack) {
    if(pstack->head == NULL)
        return TRUE;
    else
        return FALSE;
}

void SPush(Stack *pstack, Data data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = pstack->head;
    pstack->head = newNode;
}

Data SPop(Stack *pstack) {
    Data rdata;
    Node *rnode;

    if(IsEmpty(pstack)) {
        printf("Stack Memory Error!\n");
        exit(-1);
    }

    rnode = pstack->head;
    rdata = pstack->head->data;

    pstack->head = pstack->head->next;

    free(rnode);
    return rdata;
}


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