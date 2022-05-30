#ifndef DATASTRUCTURE_BINARYSEARCHTREE_H
#define DATASTRUCTURE_BINARYSEARCHTREE_H

#include "BinaryTree.h"

typedef BTData BSTData;

void BSTMakeAndInit(BTreeNode **pRoot);

BSTData BSTGetNodeData(BTreeNode *bst);

void BSTInsert(BTreeNode **pRoot, BSTData data);

BTreeNode *BSTSearch(BTreeNode *bst, BSTData target);

BTreeNode *BSTRemove(BTreeNode **pRoot, BSTData target);

void BSTShowAll(BTreeNode *bst);

#endif //DATASTRUCTURE_BINARYSEARCHTREE_H
