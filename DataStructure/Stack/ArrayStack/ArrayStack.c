#include <stdlib.h>
#include <stdio.h>
#include "ArrayStack.h"

void StackInit(Stack *pstack) {
    pstack->topIndex = -1;
}

int IsEmpty(Stack *pstack) {
    if(pstack->topIndex == -1)
        return TRUE;
    else
        return FALSE;
}

void SPush(Stack *pstack, Data data) {
    pstack->topIndex += 1;
    pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack *pstack) {
    //Pop => Peek() && topIndex -= 1
    Data peek = SPeek(pstack);
    pstack->topIndex -= 1;
    return peek;
}

Data SPeek(Stack *pstack) {
    if(IsEmpty(pstack)) {
        printf("Stack Memory Error!\n");
        exit(-1);
    }

    return pstack->stackArr[pstack->topIndex];
}