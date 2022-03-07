#ifndef DATASTRUCTURE_ARRAYLIST_H
#define DATASTRUCTURE_ARRAYLIST_H

#define TRUE	1
#define FALSE	0

#define LIST_LEN	100

typedef int LData;

typedef struct __ArrayList {
    LData arr[LIST_LEN];
    int numOfData;
    int curPosition;
} ArrayList;


typedef ArrayList List;

/**
 * List초기화
 * @param plist : 초기화할 List의 주소
 */
void ListInit(List *plist);


/**
 * List에 Data저장
 * @param plist
 * @param data
 */
void LInsert(List *plist, LData data);


//첫 데이터
int LFirst(List *plist, LData *pdata);

//다음 데이터
int LNext(List *plist, LData *pdata);

//데이터 삭제
int LRemove(List *plist);

//데이터 수
int LCount(List *plist);

#endif
