#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "BinarySearchTree.h"

int main() {
    int N;
    scanf("%d", &N);

    BTreeNode *bstRoot;
    BTreeNode *sNode;

    BSTMakeAndInit(&bstRoot);

    for (int i = 0; i < N; ++i) {
        int num;
        scanf("%d", &num);
        BSTInsert(&bstRoot, num);
    }

    int M;
    scanf("%d", &M);

    for (int i = 0; i < M; ++i) {
        int searchNum;
        scanf("%d", &searchNum);
        sNode = BSTSearch(bstRoot, searchNum);
        if (sNode == NULL) {
            printf("0");
        } else {
            printf("1");
        }

        printf(" ");
    }
    return 0;
}