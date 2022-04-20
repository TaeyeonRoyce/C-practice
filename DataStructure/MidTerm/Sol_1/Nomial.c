#include <stdio.h>
#include <stdlib.h>

#include "Nomial.h"


Nomial *MakeNomial(int coefficient, int exponent) {
    Nomial *newNomial = (Nomial *) malloc(sizeof(Nomial));
    newNomial->coefficient = coefficient;
    newNomial->exponent = exponent;

    return newNomial;
}

void ShowNomial(Nomial *nomial) {
    int coefficient = nomial->coefficient;
    int exponent = nomial->exponent;

    if (exponent == 0) {
        printf("%d", coefficient);
        return;
    } else if (exponent == 1 && coefficient > 0) {
        if (coefficient > 0) {
            printf("+%dx", coefficient);
        } else {
            printf("%dx", coefficient);
        }
    } else if (coefficient > 0) {
        printf("+%dx^%d", coefficient, exponent);
        return;
    } else {
        printf("%dx^%d", coefficient, exponent);
    }
}