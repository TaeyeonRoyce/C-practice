//
// Created by ¿øÅÂ¿¬ on 2022/04/20.
//

#ifndef DATASTRUCTURE_NOMIAL_H
#define DATASTRUCTURE_NOMIAL_H

typedef struct _nomial {
    int coefficient;
    int exponent;
} Nomial;

Nomial *MakeNomial(int coefficient, int exponent);
void ShowNomial(Nomial *nomial);
#endif //DATASTRUCTURE_NOMIAL_H
