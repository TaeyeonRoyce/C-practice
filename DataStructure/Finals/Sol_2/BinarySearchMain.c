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
    printf("����Ʈ�� ���� & Ž�� ����\n");
    if(sNode == NULL)
        printf("Ž�� ����\n");
    else
        printf("Ž���� ������ Ű�� ��: %d\n", BSTGetNodeData(sNode));

    sNode = BSTSearch(bstRoot, 4);
    if(sNode == NULL)
        printf("Ž�� ����\n");
    else
        printf("Ž���� ������ Ű�� ��: %d\n", BSTGetNodeData(sNode));

    sNode = BSTSearch(bstRoot, 6);
    if(sNode == NULL)
        printf("Ž�� ����\n");
    else
        printf("Ž���� ������ Ű�� ��: %d\n", BSTGetNodeData(sNode));

    sNode = BSTSearch(bstRoot, 7);
    if(sNode == NULL) {
        printf("Ž�� ����\n");
    } else {
        printf("Ž���� ������ Ű�� ��: %d\n", BSTGetNodeData(sNode));
    }


    BTreeNode *bstRootDel;
    BTreeNode *sNodeDel;

    BSTMakeAndInit(&bstRootDel);

    BSTInsert(&bstRootDel, 5); BSTInsert(&bstRootDel, 8);
    BSTInsert(&bstRootDel, 1); BSTInsert(&bstRootDel, 6);
    BSTInsert(&bstRootDel, 4); BSTInsert(&bstRootDel, 9);
    BSTInsert(&bstRootDel, 3); BSTInsert(&bstRootDel, 2);
    BSTInsert(&bstRootDel, 7);

    printf("\n����Ʈ�� ���� ����\n");
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