#ifndef DATASTRUCTURE_BINARYTREE_H
#define DATASTRUCTURE_BINARYTREE_H

typedef int BTData; //data Type

typedef struct _bTreeNode {
    BTData data;
    struct _bTreeNode *left; //���� ���
    struct _bTreeNode *right; //������ ���
} BTreeNode;

//Tree�� ���� �ڷᱸ���ʹ� �ٸ��� Tree��� ����ü�� ���� �������� ����
//BTreeNode�� ������ �� Tree�̱� ����.

BTreeNode *MakeBTreeNode(void);
BTData GetData(BTreeNode *bt);
void SetData(BTreeNode *bt, BTData data);

BTreeNode *GetLeftSubTree(BTreeNode *bt);
BTreeNode *GetRightSubTree(BTreeNode *bt);

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub);
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub);



#endif //DATASTRUCTURE_BINARYTREE_H
