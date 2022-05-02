#include <stdio.h>
#include "BinaryTree.h"

void ShowIntData(BTData data);

int main(void) {
    BTreeNode *bt1 = MakeBTreeNode();
    BTreeNode *bt2 = MakeBTreeNode();
    BTreeNode *bt3 = MakeBTreeNode();
    BTreeNode *bt4 = MakeBTreeNode();
    BTreeNode *bt5 = MakeBTreeNode();
    BTreeNode *bt6 = MakeBTreeNode();

    SetData(bt1, 1);
    SetData(bt2, 2);
    SetData(bt3, 3);
    SetData(bt4, 4);
    SetData(bt5, 5);
    SetData(bt6, 6);

    MakeLeftSubTree(bt1, bt2);
    MakeRightSubTree(bt1, bt3);
    MakeLeftSubTree(bt2, bt4);
    MakeRightSubTree(bt2, bt5);
    MakeRightSubTree(bt3, bt6);
    /* Tree ±¸Á¶
     *           1
     *         /   \
     *        2     3
     *      /   \    \
     *     4     5    6
     */

    PreorderTraverses(bt1, ShowIntData); // 1 2 4 5 3 6
    printf("\n");
    InorderTraverses(bt1, ShowIntData); // 4 2 5 1 3 6
    printf("\n");
    PostorderTraverses(bt1, ShowIntData); // 4 5 2 6 3 1
    printf("\n");

    DeleteTree(bt1);

    return 0;
}

void ShowIntData(BTData data) {
    printf("%d ", data);
}