#ifndef DATASTRUCTURE_ARRAYSTACK_H
#define DATASTRUCTURE_ARRAYSTACK_H

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100

typedef int Data;

typedef struct _arrayStack {
    Data stackArr[STACK_LEN];
    int topIndex;
} ArrayStack;

typedef ArrayStack Stack;

//초기화
void StackInit(Stack *pstack);

//Stack에 데이터가 있는지 확인
int IsEmpty(Stack *pstack);

//Stack 맨 위에 데이터 추가
void SPush(Stack *pstack, Data data);

//맨 위 데이터 제거 후 반환
Data SPop(Stack *pstack);

//맨 위 데이터 반환
Data SPeek(Stack *pstack);

#endif //DATASTRUCTURE_ARRAYSTACK_H
