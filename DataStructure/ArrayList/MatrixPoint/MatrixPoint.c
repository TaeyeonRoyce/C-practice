#include <stdio.h>
#include "MatrixPoint.h"

void SetPointPos(MatrixPoint *ppos, int xpos, int ypos) {
    ppos->xpos = xpos;
    ppos->ypos = ypos;
}

void ShowPointPos(MatrixPoint *ppos) {
    printf("[%d %d] \n", ppos->xpos, ppos->ypos);
}

int PointComp(MatrixPoint *pos1, MatrixPoint *pos2) {
    if (pos1->xpos == pos2->xpos && pos1->ypos == pos2->ypos) {
        return 0;
    } else if (pos1->xpos == pos2->xpos) {
        return 1;
    } else if (pos1->ypos == pos2->ypos) {
        return 2;
    } else {
        return -1;
    }
}