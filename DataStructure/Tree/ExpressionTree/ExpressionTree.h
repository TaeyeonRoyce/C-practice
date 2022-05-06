#ifndef DATASTRUCTURE_EXPRESSIONTREE_H
#define DATASTRUCTURE_EXPRESSIONTREE_H

#include "../BinaryTree.h"

BTreeNode *MakeExpTree(char exp[]);
int EvaluateExpTree(BTreeNode *bt);

void ShowPrefixTypeExp(BTreeNode *bt);
void ShowInfixTypeExp(BTreeNode *bt);
void ShowPostfixTypeExp(BTreeNode *bt);

#endif //DATASTRUCTURE_EXPRESSIONTREE_H
