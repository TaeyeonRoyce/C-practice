#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "DLinkedList.h"
#include "Nomial.h"

int nomialPrecede(Nomial *n1, Nomial *n2) {
    if (n1->exponent > n2->exponent) {
        return 0;
    }
    return 1;
}

int main() {
    int T;
    scanf("%d", &T);

    Nomial *nomial;
    LinkedList nomialList;
    ListInit(&nomialList);

    SetSortRule(&nomialList, nomialPrecede);

    int coefficient;
    int exponent;
    for (int i = 0; i < T; ++i) {
        scanf("%d %d", &coefficient, &exponent);
        nomial = MakeNomial(coefficient, exponent);
        LInsert(&nomialList, nomial);
    }

    if (LFirst(&nomialList, &nomial)) {
        ShowNomial(nomial);

        while (LNext(&nomialList, &nomial)) {
            ShowNomial(nomial);
        }
        printf("\n");
    }
    return 0;
}