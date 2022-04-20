#ifndef DATASTRUCTURE_LINKEDLISTSTACK_H
#define DATASTRUCTURE_LINKEDLISTSTACK_H

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

void StackInit(Stack *pstack);
int IsEmpty(Stack *pstack);

void SPush(Stack *pstack, Data data);
Data SPop(Stack *pstack);
Data SPeek(Stack *pstack);

#endif //DATASTRUCTURE_LINKEDLISTSTACK_H
