#include <stdio.h>
#include <stdlib.h>

typedef char BTData; //data Type

typedef struct _bTreeNode {
    BTData data;
    struct _bTreeNode *left; //왼쪽 노드
    struct _bTreeNode *right; //오른쪽 노드
} BTreeNode;

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

void PreorderTraverses(BTreeNode *bt) {
    if(bt == NULL)
        return;

    printf("%c", bt->data);
    PreorderTraverses(bt->left);
    PreorderTraverses(bt->right);
}

//중위 순회
//4 2 1 3
void InorderTraverses(BTreeNode *bt) {
    if(bt == NULL)
        return;

    InorderTraverses(bt->left);
    printf("%c", bt->data);
    InorderTraverses(bt->right);
}


//후위 순회
//4 2 3 1
void PostorderTraverses(BTreeNode *bt) {
    if(bt == NULL)
        return;

    PostorderTraverses(bt->left);
    PostorderTraverses(bt->right);
    printf("%c", bt->data);
}

int main() {
    int N;
    scanf("%d ", &N);

    BTreeNode treeArray[N];

    for (int i = 0; i < N; ++i) {
        BTreeNode *pNode = MakeBTreeNode();
        SetData(pNode, 65 + i);
        treeArray[i] = *pNode;
    }
    
    for (int i = 0; i < N; ++i) {
        char root;
        char leftSub;
        char rightSub;

        if (i == N - 1) {
            scanf("%c %c %c",&root, &leftSub,&rightSub);
        } else {
            scanf("%c %c %c ",&root, &leftSub,&rightSub);
        }
        BTreeNode *rootNode;
        for (int j = 0; j < N; ++j) {
            if (GetData(&treeArray[j]) == root) {
                rootNode = &treeArray[j];
                break;
            }
        }


        if (leftSub != '.') {
            for (int j = 0; j < N; ++j) {
                if (GetData(&treeArray[j]) == leftSub) {
                    MakeLeftSubTree(rootNode, &treeArray[j]);
                    break;
                }
            }
        }

        if (rightSub != '.') {
            for (int j = 0; j < N; ++j) {
                if (GetData(&treeArray[j]) == rightSub) {
                    MakeRightSubTree(rootNode, &treeArray[j]);
                    break;
                }
            }
        }
    }

    PreorderTraverses(&treeArray[0]);
    printf("\n");
    InorderTraverses(&treeArray[0]);
    printf("\n");
    PostorderTraverses(&treeArray[0]);


    return 0;
}

