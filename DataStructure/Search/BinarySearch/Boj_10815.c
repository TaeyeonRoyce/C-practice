#include <stdio.h>
#include <stdlib.h>

typedef int BTData;

typedef struct _bTreeNode {
    BTData data;
    struct _bTreeNode *left;
    struct _bTreeNode *right;
} BTreeNode;

typedef BTData BSTData;

BTreeNode *MakeBTreeNode() {
    BTreeNode *nd = (BTreeNode *)malloc(sizeof(BTreeNode));
    nd->left = NULL;
    nd->right = NULL;

    return nd;
}

typedef void VisitFuncPtr(BTData data);

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

void BSTMakeAndInit(BTreeNode **pRoot) {
    *pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode *bst) {
    return GetData(bst);
}

void BSTInsert(BTreeNode **pRoot, BSTData data) {
    BTreeNode *pNode = NULL;
    BTreeNode *cNode = *pRoot;
    BTreeNode *nNode = NULL;

    while(cNode != NULL) {
        if(GetData(cNode) == data)
            return;

        pNode = cNode;

        if(GetData(cNode) > data)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }

    nNode = MakeBTreeNode();
    SetData(nNode, data);

    if(pNode != NULL) {
        if(GetData(pNode) > data)
            MakeLeftSubTree(pNode, nNode);
        else
            MakeRightSubTree(pNode, nNode);
    }
    else {
        *pRoot = nNode;
    }
}

BTreeNode *BSTSearch(BTreeNode *bst, BSTData target) {
    BTreeNode *cNode = bst;
    BSTData cd;

    while(cNode != NULL) {
        cd = GetData(cNode);

        if(target == cd)
            return cNode;
        else if(target < cd)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }

    return NULL;
}

BTreeNode *BSTRemove(BTreeNode **pRoot, BSTData target) {
    BTreeNode *pVRoot = MakeBTreeNode();
    BTreeNode *pNode = pVRoot;
    BTreeNode *cNode = *pRoot;
    BTreeNode *dNode;

    ChangeRightSubTree(pVRoot, *pRoot);

    while(cNode != NULL && GetData(cNode) != target) {
        pNode = cNode;

        if(target < GetData(cNode))
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }

    if(cNode == NULL)
        return NULL;

    dNode = cNode;

    if(GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL) {
        if(GetLeftSubTree(pNode) == dNode)
            RemoveLeftSubTree(dNode);
        else
            RemoveRightSubTree(dNode);
    }
    else if(GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL) {
        BTreeNode *dcNode;

        if(GetLeftSubTree(dNode) != NULL)
            dcNode = GetLeftSubTree(dNode);
        else
            dcNode = GetRightSubTree(dNode);

        if(GetLeftSubTree(pNode) == dNode)
            ChangeLeftSubTree(pNode, dcNode);
        else
            ChangeRightSubTree(pNode, dcNode);
    }
    else {
        BTreeNode *mNode = GetRightSubTree(dNode);
        BTreeNode *mpNode = dNode;
        int delData;

        while(GetLeftSubTree(mNode) != NULL) {
            mpNode = mNode;
            mNode = GetLeftSubTree(mNode);
        }

        delData = GetData(dNode);
        SetData(dNode, GetData(mNode));

        if(GetLeftSubTree(mpNode) == mNode)
            ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
        else
            ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

        dNode = mNode;
        SetData(dNode, delData);
    }

    if(GetRightSubTree(pVRoot) != *pRoot)
        *pRoot = GetRightSubTree(pVRoot);

    free(pVRoot);
    return dNode;
}

void ShowIntData(int data) {
    printf("%d ", data);
}

void BSTShowAll(BTreeNode *bst) {
    InorderTraverses(bst, ShowIntData);
}

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