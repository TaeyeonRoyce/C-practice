#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

BTreeNode *MakeBTreeNode() {
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

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub) {
    if(main->left != NULL)
        free(main->left);

    main->left = sub;
}

void MakeRightSubTree(BTreeNode *main, BTreeNode *sub) {
    if(sub->right != NULL)
        free(main->right);

    main->right = sub;
}

void PreorderTraverses(BTreeNode *bt, VisitFuncPtr action) {
    if(bt == NULL)
        return;

    action(bt->data);
    PreorderTraverses(bt->left, action);
    PreorderTraverses(bt->right, action);
}

void InorderTraverses(BTreeNode *bt, VisitFuncPtr action) {
    if(bt == NULL)
        return;

    InorderTraverses(bt->left, action);
    action(bt->data);
    InorderTraverses(bt->right, action);
}

void PostorderTraverses(BTreeNode *bt, VisitFuncPtr action) {
    if(bt == NULL)
        return;

    PostorderTraverses(bt->left, action);
    PostorderTraverses(bt->right, action);
    action(bt->data);
}

void ChangeLeftSubTree(BTreeNode *main, BTreeNode *sub) {
    main->left = sub;
}

void ChangeRightSubTree(BTreeNode *main, BTreeNode *sub) {
    main->right = sub;
}

BTreeNode *RemoveLeftSubTree(BTreeNode *bt) {
    BTreeNode *delNode = NULL;

    if(bt != NULL) {
        delNode = bt->left;
        bt->left = NULL;
    }

    return delNode;
}

BTreeNode *RemoveRightSubTree(BTreeNode *bt) {
    BTreeNode *delNode = NULL;

    if(bt != NULL) {
        delNode = bt->left;
        bt->left = NULL;
    }

    return delNode;
}
