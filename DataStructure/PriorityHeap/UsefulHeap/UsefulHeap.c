//
// Created by ���¿� on 2022/05/16.
//

#include "UsefulHeap.h"

void HeapInit(Heap *ph, PriorityComp pc) {
    ph->numOfData = 0;
    ph->comp = pc;
}

int HIsEmpty(Heap *ph) {
    if(ph->numOfData == 0)
        return TRUE;
    else
        return FALSE;
}

//�迭 ��� ������ �ش� ����� �θ� ��� �ε���
int GetParentIDX(int idx) {
    return idx / 2;
}

//�迭 ��� ������ �ش� ����� ���� �ڽ� ��� �ε���
int GetLChildIDX(int idx) {
    return idx * 2;
}

//�迭 ��� ������ �ش� ����� ������ �ڽ� ��� �ε���
int GetRChildIDX(int idx) {
    return GetLChildIDX(idx) + 1;
}

//�ڽ� ��� ���� �켱���� ��
int GetHiPriChildIDX(Heap *ph, int idx) {

    //�ڽ� ��尡 ���� ���
    if(GetLChildIDX(idx) > ph->numOfData) {
        return 0;
    }
    //������ �ڽ� ��尡 ���� ���
    else if(GetLChildIDX(idx) == ph->numOfData) {
        return GetLChildIDX(idx);
    }
    else {
        //�����ڰ� ���� �켱����(ph.comp)�� �´� �ڽ� ����� �ε��� ��ȯ
        if(ph->comp(ph->heapArr[GetLChildIDX(idx)], ph->heapArr[GetRChildIDX(idx)]) > 0)
            return GetLChildIDX(idx);
        else
            return GetRChildIDX(idx);
    }
}

void HInsert(Heap *ph, HData data) {
    int idx = ph->numOfData + 1; //�迭 �� �ڿ� ����

    while(idx != 1) {
        //�߰��� ����� �����Ͱ� �θ𺸴� �켱������ ������ ����
        if(ph->comp(data, ph->heapArr[GetParentIDX(idx)]) < 0) {
            break;
        }

        //�߰��� ����� �����Ͱ� ���� �θ��庸�� �켱������ ����
        //���� �̵����� ��ġ(�߰��� ����� ��ġ)�� �θ� ���� �ڸ� �ٲ�
        ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];

        //�� ��� ��带 �� ���� ����(�θ�)�� ���� ����
        idx = GetParentIDX(idx);
    }

    ph->heapArr[idx] = data;
    ph->numOfData += 1;
}

/**
 * ���� ���� ����
 * HDelete�� ��Ʈ ��带 �����ϰ�
 * ���� ������ ��带 ��Ʈ ��忡 ��ġ��Ų��.
 * �� �� �켱������ �°� ���ϸ�
 * �ǹٸ� ��ġ�� ã�� ����.
 */

HData HDelete(Heap *ph) {
    //������ ������(��Ʈ ���) �ӽ� ����
    HData retData = ph->heapArr[1];

    //���� ������ ��� �ӽ� ����
    HData lastElem = ph->heapArr[ph->numOfData];

    int parentIdx = 1;
    int childIdx;

    //��Ʈ ��带 ������ �� ������ ��带 ��Ʈ ��忡 ��ġ��Ŵ
    //�� �� �켱������ ���� ��Ʈ �ڸ��� �ö� ������ ��� �����͸� �̵����Ѿ� �ϴµ�,
    //�� ����� ���� ��ġ�� �˸��

    while(childIdx = GetHiPriChildIDX(ph, parentIdx)) {
        //�ڽ� ��� �߿��� �켱������ �� ���� �ڽ��� �ε���

        //�� �ڽĳ���� �켱�������� ���� �̵��ϰ� �ִ� ����� �켱������ �� ������ �ش� �ڸ��� �ǹٸ� �ڸ���
        if(ph->comp(lastElem, ph->heapArr[childIdx]) >= 0) {
            break;
        }

        //�̵� ���� ����� �켱������ ������, �ش� ������� �ڸ��� �纸�ϰ� �� �Ʒ� ����� ���ؾ���
        ph->heapArr[parentIdx] = ph->heapArr[childIdx]; //�ڸ� �纸 -> ������ ����� ��ġ�� �ø�
        parentIdx = childIdx; //�� ���� ������ ���� ��
    }

    ph->heapArr[parentIdx] = lastElem; //�ݺ����� ���� ã�� ������ ����� ��ġ�� ����
    ph->numOfData -= 1; //������ �� ����
    return retData;
}