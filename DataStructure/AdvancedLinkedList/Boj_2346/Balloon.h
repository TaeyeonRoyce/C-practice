//
// Created by 원태연 on 2022/04/19.
//

#ifndef DATASTRUCTURE_BALLOON_H
#define DATASTRUCTURE_BALLOON_H

typedef struct _balloon {
    int index;
    int moveCnt;
} Balloon;


//NameCard 구조체 변수의 동적 할당 및 초기화 후 주소 값 반환
Balloon *MakeBalloon(int index, int moveCnt);

#endif //DATASTRUCTURE_BALLOON_H
