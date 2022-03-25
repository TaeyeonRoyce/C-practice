#include <stdio.h>
#include "InfixToPostfix.h"

/**
 * To Run this Source,
 * copy following texts and paste to CMakeLists.txt

   add_executable(
        DataStructure
        Stack/LinkedListStack/LinkedListStack.h
        Stack/LinkedListStack/LinkedListStack.c
        Stack/InfixToPostfix/InfixToPostfix.c
        Stack/InfixToPostfix/InfixToPostfix.h
        Stack/InfixToPostfix/InfixToPostfixMain.c
)

 */

int main(void) {
    char exp1[] = "1+2*3";
    char exp2[] = "(1+2)*3";
    char exp3[] = "((1-2)+3)*(5-2)";

    ConvToRPNExp(exp1);
    ConvToRPNExp(exp2);
    ConvToRPNExp(exp3);

    printf("%s\n", exp1);
    printf("%s\n", exp2);
    printf("%s\n", exp3);

    return 0;
}