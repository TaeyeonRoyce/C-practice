//
// Created by ¿øÅÂ¿¬ on 2022/04/18.
//

#include <stdio.h>
#include "PostCalculator.h"

int main(void) {
    char exp1[] = "123*+";
    char exp2[] = "12+3*";
    char exp3[] = "12-3+52-*";

    printf("%s = %d\n", exp1, EvalRPNExp(exp1));
    printf("%s = %d\n", exp2, EvalRPNExp(exp2));
    printf("%s = %d\n", exp3, EvalRPNExp(exp3));

    return 0;
}