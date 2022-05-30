#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

int main() {
    BTreeNode *bstRoot;
    BTreeNode *sNode;

    BSTMakeAndInit(&bstRoot);

    BSTInsert(&bstRoot, 9);
    BSTInsert(&bstRoot, 1);
    BSTInsert(&bstRoot, 6);
    BSTInsert(&bstRoot, 2);
    BSTInsert(&bstRoot, 8);
    BSTInsert(&bstRoot, 3);
    BSTInsert(&bstRoot, 5);

    sNode = BSTSearch(bstRoot, 1);
    printf("이진트리 삽입 & 탐색 예시\n");
    if(sNode == NULL)
        printf("탐색 실패\n");
    else
        printf("탐색에 성공한 키의 값: %d\n", BSTGetNodeData(sNode));

    sNode = BSTSearch(bstRoot, 4);
    if(sNode == NULL)
        printf("탐색 실패\n");
    else
        printf("탐색에 성공한 키의 값: %d\n", BSTGetNodeData(sNode));

    sNode = BSTSearch(bstRoot, 6);
    if(sNode == NULL)
        printf("탐색 실패\n");
    else
        printf("탐색에 성공한 키의 값: %d\n", BSTGetNodeData(sNode));

    sNode = BSTSearch(bstRoot, 7);
    if(sNode == NULL) {
        printf("탐색 실패\n");
    } else {
        printf("탐색에 성공한 키의 값: %d\n", BSTGetNodeData(sNode));
    }


    BTreeNode *bstRootDel;
    BTreeNode *sNodeDel;

    BSTMakeAndInit(&bstRootDel);

    BSTInsert(&bstRootDel, 5); BSTInsert(&bstRootDel, 8);
    BSTInsert(&bstRootDel, 1); BSTInsert(&bstRootDel, 6);
    BSTInsert(&bstRootDel, 4); BSTInsert(&bstRootDel, 9);
    BSTInsert(&bstRootDel, 3); BSTInsert(&bstRootDel, 2);
    BSTInsert(&bstRootDel, 7);

    printf("\n이진트리 삭제 예시\n");
    BSTShowAll(bstRootDel); printf("\n");
    sNodeDel = BSTRemove(&bstRootDel, 3);
    free(sNodeDel);

    BSTShowAll(bstRootDel); printf("\n");
    sNodeDel = BSTRemove(&bstRootDel, 8);
    free(sNodeDel);

    BSTShowAll(bstRootDel); printf("\n");
    sNodeDel = BSTRemove(&bstRootDel, 1);
    free(sNodeDel);

    BSTShowAll(bstRootDel); printf("\n");
    sNodeDel = BSTRemove(&bstRootDel, 6);
    free(sNodeDel);

    BSTShowAll(bstRootDel); printf("\n");


    return 0;
}