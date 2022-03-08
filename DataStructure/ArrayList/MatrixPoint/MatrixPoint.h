#ifndef DATASTRUCTURE_MATRIXPOINT_H
#define DATASTRUCTURE_MATRIXPOINT_H

typedef struct _point {
    int xpos;
    int ypos;
} MatrixPoint;

//MatrixPoint x, y설정
void SetPointPos(MatrixPoint *ppos, int xpos, int ypos);

//MatrixPoint x, y 출력
void ShowPointPos(MatrixPoint *ppos);

//두 MatrixPoint 비교
int PointComp(MatrixPoint *pos1, MatrixPoint *pos2);

#endif