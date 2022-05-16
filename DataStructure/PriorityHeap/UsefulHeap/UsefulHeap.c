//
// Created by 원태연 on 2022/05/16.
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

//배열 기반 힙에서 해당 노드의 부모 노드 인덱스
int GetParentIDX(int idx) {
    return idx / 2;
}

//배열 기반 힙에서 해당 노드의 왼쪽 자식 노드 인덱스
int GetLChildIDX(int idx) {
    return idx * 2;
}

//배열 기반 힙에서 해당 노드의 오른쪽 자식 노드 인덱스
int GetRChildIDX(int idx) {
    return GetLChildIDX(idx) + 1;
}

//자식 노드 간의 우선순위 비교
int GetHiPriChildIDX(Heap *ph, int idx) {

    //자식 노드가 없는 경우
    if(GetLChildIDX(idx) > ph->numOfData) {
        return 0;
    }
    //오른쪽 자식 노드가 없는 경우
    else if(GetLChildIDX(idx) == ph->numOfData) {
        return GetLChildIDX(idx);
    }
    else {
        //개발자가 정한 우선순위(ph.comp)에 맞는 자식 노드의 인덱스 반환
        if(ph->comp(ph->heapArr[GetLChildIDX(idx)], ph->heapArr[GetRChildIDX(idx)]) > 0)
            return GetLChildIDX(idx);
        else
            return GetRChildIDX(idx);
    }
}

void HInsert(Heap *ph, HData data) {
    int idx = ph->numOfData + 1; //배열 맨 뒤에 저장

    while(idx != 1) {
        //추가된 노드의 데이터가 부모보다 우선순위가 낮으면 정착
        if(ph->comp(data, ph->heapArr[GetParentIDX(idx)]) < 0) {
            break;
        }

        //추가된 노드의 데이터가 현재 부모노드보다 우선순위가 높음
        //현재 이동중인 위치(추가된 노드의 위치)와 부모 노드랑 자리 바꿈
        ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];

        //비교 대상 노드를 더 높은 레벨(부모)의 노드로 변경
        idx = GetParentIDX(idx);
    }

    ph->heapArr[idx] = data;
    ph->numOfData += 1;
}

/**
 * 힙의 삭제 과정
 * HDelete는 루트 노드를 삭제하고
 * 힙의 마지막 노드를 루트 노드에 위치시킨다.
 * 그 후 우선순위에 맞게 비교하며
 * 옳바른 위치로 찾아 간다.
 */

HData HDelete(Heap *ph) {
    //삭제할 데이터(루트 노드) 임시 저장
    HData retData = ph->heapArr[1];

    //힙의 마지막 노드 임시 저장
    HData lastElem = ph->heapArr[ph->numOfData];

    int parentIdx = 1;
    int childIdx;

    //루트 노드를 삭제한 뒤 마지막 노드를 루트 노드에 위치시킴
    //그 후 우선순위에 따라 루트 자리에 올라간 마지막 노드 데이터를 이동시켜야 하는데,
    //그 노드의 최종 위치만 알면됨

    while(childIdx = GetHiPriChildIDX(ph, parentIdx)) {
        //자식 노드 중에서 우선순위가 더 높은 자식의 인덱스

        //그 자식노드의 우선순위보다 현재 이동하고 있는 노드의 우선순위가 더 높으면 해당 자리가 옳바른 자리임
        if(ph->comp(lastElem, ph->heapArr[childIdx]) >= 0) {
            break;
        }

        //이동 중인 노드의 우선순위가 낮으면, 해당 노드한테 자리를 양보하고 더 아래 노드들과 비교해야함
        ph->heapArr[parentIdx] = ph->heapArr[childIdx]; //자리 양보 -> 비교중인 노드의 위치를 올림
        parentIdx = childIdx; //더 낮은 레벨의 노드와 비교
    }

    ph->heapArr[parentIdx] = lastElem; //반복문을 통해 찾은 마지막 노드의 위치에 저장
    ph->numOfData -= 1; //데이터 수 감소
    return retData;
}