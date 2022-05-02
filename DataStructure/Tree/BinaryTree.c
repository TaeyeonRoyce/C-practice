#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

BTreeNode *MakeBTreeNode(void) {
    BTreeNode *nd = (BTreeNode *)malloc(sizeof(BTreeNode));
    nd->left = NULL;
    nd->right = NULL;

    return nd;
}

BTData GetData(BTreeNode *bt) {
    return bt->data;
}

void SetData(BTreeNode *bt, BTData data) {
    bt->data = data;
}

BTreeNode *GetLeftSubTree(BTreeNode *bt) {
    return bt->left;
}

BTreeNode *GetRightSubTree(BTreeNode *bt) {
    return bt->right;
}


//자식 노드를 변경하면서 메모리를 해제 하는데, 단일 자식노드만 해제하여 메모리 누수가 발생할 수 있음
//해제하려는 노드가 내부 노드(서브트리)인 경우
//해제하려는 노드의 자식들은 논리적으론 제거되었지만 실제론 지워지지 않고 메모리를 차지함
//순회하면서 서브트리를 모두 제거하는 로직 필요
void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub) {
    if(main->left != NULL)
        free(main->left);
    main->left = sub;
}

void MakeRightSubTree(BTreeNode *main, BTreeNode *sub) {
    if(main->right != NULL)
        free(main->right);

    main->right = sub;
}

//ex)
//    1
//  2   3
//4

//전위 순회
// 1 2 4 3
void PreorderTraverses(BTreeNode *bt, VisitFuncPtr action) {
    if(bt == NULL)
        return;

    action(bt->data);
    PreorderTraverses(bt->left, action);
    PreorderTraverses(bt->right, action);
}

//중위 순회
//4 2 1 3
void InorderTraverses(BTreeNode *bt, VisitFuncPtr action) {
    if(bt == NULL)
        return;

    InorderTraverses(bt->left, action);
    action(bt->data);
    InorderTraverses(bt->right, action);
}


//후위 순회
//4 2 3 1
void PostorderTraverses(BTreeNode *bt, VisitFuncPtr action) {
    if(bt == NULL)
        return;

    PostorderTraverses(bt->left, action);
    PostorderTraverses(bt->right, action);
    action(bt->data);
}

//삭제하는 노드의 하위 단말노드까지 모두 방문하여 삭제
void DeleteTree(BTreeNode *bt) {
    if(bt == NULL)
        return;

    DeleteTree(bt->left);
    DeleteTree(bt->right);

    printf("del tree data: %d\n", bt->data);
    free(bt);
}