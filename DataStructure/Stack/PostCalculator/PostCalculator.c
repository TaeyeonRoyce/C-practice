//
// Created by ¿øÅÂ¿¬ on 2022/04/18.
//

#include <string.h>
#include "PostCalculator.h"
#include "../LinkedListStack/LinkedListStack.h"

int isOperator(char tok) {
    switch (tok) {
        case '*':
            return 1;
        case '/':
            return 1;
        case '+':
            return 1;
        case '-':
            return 1;

        default:
            return 0;
    }
}


int EvalRPNExp(char exp[]) {
    Stack stack;
    int i;
    int expLen = strlen(exp);
    char tok;
    char op1, op2;

    StackInit(&stack);
    for (i = 0; i < expLen; i++) {
        tok = exp[i];

        if (!isOperator(tok)) {
            SPush(&stack, tok - '0');
        } else {
            op2 = SPop(&stack);
            op1 = SPop(&stack);

            switch (tok) {
                case '+':
                    SPush(&stack, op1 + op2);
                    break;
                case '-':
                    SPush(&stack, op1 - op2);
                    break;
                case '*':
                    SPush(&stack, op1 * op2);
                    break;
                case '/':
                    SPush(&stack, op1 / op2);
                    break;
            }
        }
    }
    return SPop(&stack);
}