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