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


//�ڽ� ��带 �����ϸ鼭 �޸𸮸� ���� �ϴµ�, ���� �ڽĳ�常 �����Ͽ� �޸� ������ �߻��� �� ����
//�����Ϸ��� ��尡 ���� ���(����Ʈ��)�� ���
//�����Ϸ��� ����� �ڽĵ��� �������� ���ŵǾ����� ������ �������� �ʰ� �޸𸮸� ������
//��ȸ�ϸ鼭 ����Ʈ���� ��� �����ϴ� ���� �ʿ�
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