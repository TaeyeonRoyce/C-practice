//
// Created by ���¿� on 2022/04/19.
//

#ifndef DATASTRUCTURE_BALLOON_H
#define DATASTRUCTURE_BALLOON_H

typedef struct _balloon {
    int index;
    int moveCnt;
} Balloon;


//NameCard ����ü ������ ���� �Ҵ� �� �ʱ�ȭ �� �ּ� �� ��ȯ
Balloon *MakeBalloon(int index, int moveCnt);

#endif //DATASTRUCTURE_BALLOON_H
