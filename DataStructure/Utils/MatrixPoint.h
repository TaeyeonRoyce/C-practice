#ifndef DATASTRUCTURE_MATRIXPOINT_H
#define DATASTRUCTURE_MATRIXPOINT_H

typedef struct _point {
    int xpos;
    int ypos;
} Point;

//Point x, y설정
void SetPointPost(Point *ppos, int xpos, int ypos);

//Point x, y 출력
void ShowPointPos(Point *ppos);

//두 Point 비교
int PointComp(Point *pos1, Point *pos2);

#endif