#ifndef DATASTRUCTURE_ASSIGNMENT_H
#define DATASTRUCTURE_ASSIGNMENT_H

typedef struct _assignment {
    int expireDate;
    int score;
} Assignment;

void SetAssign(Assignment *pAssign, int expireDate, int score);

#endif //DATASTRUCTURE_ASSIGNMENT_H
