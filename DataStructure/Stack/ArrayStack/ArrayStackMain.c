#include <stdio.h>
#include "ArrayStack.h"

/**
 * To Run this Source,
 * copy following texts and paste to CMakeLists.txt

   add_executable(
        DataStructure
        Stack/ArrayStack/ArrayStack.c
        Stack/ArrayStack/ArrayStack.h
        Stack/ArrayStack/ArrayStackMain.c
)

 */

int main(void) {
    Stack stack;

    //초기화
    StackInit(&stack);

    SPush(&stack, 1);
    SPush(&stack, 2);
    SPush(&stack, 3);
    SPush(&stack, 4);
    SPush(&stack, 5);

    while (!IsEmpty(&stack)) {
        printf("%d ", SPop(&stack));
    }
    printf("\n");
    return 0;
}