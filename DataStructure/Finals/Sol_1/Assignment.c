#include <stdio.h>
#include "Assignment.h"

void SetAssign(Assignment *pAssign, int expireDate, int score) {
    pAssign->expireDate = expireDate;
    pAssign->score = score;
}
