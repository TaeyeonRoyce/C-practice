//
// Created by ¿øÅÂ¿¬ on 2022/04/19.
//

#include <stdio.h>
#include <stdlib.h>
#include "Balloon.h"

Balloon *MakeBalloon(int index, int moveCnt) {
    Balloon *newBalloon = (Balloon *) malloc(sizeof(Balloon));
    newBalloon->index = index;
    newBalloon->moveCnt = moveCnt;
    return newBalloon;
};
