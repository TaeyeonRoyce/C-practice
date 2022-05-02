#ifndef DATASTRUCTURE_BINARYTREE_H
#define DATASTRUCTURE_BINARYTREE_H

typedef int BTData; //data Type

typedef struct _bTreeNode {
    BTData data;
    struct _bTreeNode *left; //왼쪽 노드
    struct _bTreeNode *right; //오른쪽 노드
} BTreeNode;

//Tree는 이전 자료구조와는 다르게 Tree라는 구조체를 따로 선언하지 않음
//BTreeNode의 선언이 곧 Tree이기 때문.

BTreeNode *MakeBTreeNode(void);
BTData GetData(BTreeNode *bt);
void SetData(BTreeNode *bt, BTData data);

BTreeNode *GetLeftSubTree(BTreeNode *bt);
BTreeNode *GetRightSubTree(BTreeNode *bt);

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub);
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub);


//순회 방식 설정
typedef void VisitFuncPtr(BTData data);

//전위 순회
void PreorderTraverses(BTreeNode *bt, VisitFuncPtr action);

//준위 순회
void InorderTraverses(BTreeNode *bt, VisitFuncPtr action);

//후위 순회
void PostorderTraverses(BTreeNode *bt, VisitFuncPtr action);

//노드 삭제
//서브트리의 모든 노드를 제거하기 위해 순회하며 제거하는 로직 필요
void DeleteTree(BTreeNode *bt);



#endif //DATASTRUCTURE_BINARYTREE_H
