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

//ex)
//    1
//  2   3
//4

//���� ��ȸ
// 1 2 4 3
void PreorderTraverses(BTreeNode *bt, VisitFuncPtr action) {
    if(bt == NULL)
        return;

    action(bt->data);
    PreorderTraverses(bt->left, action);
    PreorderTraverses(bt->right, action);
}

//���� ��ȸ
//4 2 1 3
void InorderTraverses(BTreeNode *bt, VisitFuncPtr action) {
    if(bt == NULL)
        return;

    InorderTraverses(bt->left, action);
    action(bt->data);
    InorderTraverses(bt->right, action);
}


//���� ��ȸ
//4 2 3 1
void PostorderTraverses(BTreeNode *bt, VisitFuncPtr action) {
    if(bt == NULL)
        return;

    PostorderTraverses(bt->left, action);
    PostorderTraverses(bt->right, action);
    action(bt->data);
}

//�����ϴ� ����� ���� �ܸ������� ��� �湮�Ͽ� ����
void DeleteTree(BTreeNode *bt) {
    if(bt == NULL)
        return;

    DeleteTree(bt->left);
    DeleteTree(bt->right);

    printf("del tree data: %d\n", bt->data);
    free(bt);
}