#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int solution(
        int inorderStart,
        int inorderEnd,
        int postorderStart,
        int postorderEnd,
        int inorderArray[],
        int postOrderArray[]
    ) {
    if (inorderStart > inorderEnd || postorderStart > postorderEnd){
        return 0;
    }

    int root = postOrderArray[postorderEnd];
    printf("%d ", root);

    int cnt = 0;
    while(inorderArray[cnt] != root) {
        cnt++;
    }
    int rootIndexInorderArray = cnt;
    int leftSize = cnt - inorderStart;


    //���� Ž�����̱� ������ ���� ����Ʈ������ ��ȸ
    //���� Ʈ�� Ž��
    solution(
        inorderStart,
        rootIndexInorderArray - 1, //�߰��� �������� ���� ����Ʈ���� ������ �ε����� ���� ��
        postorderStart,
        postorderStart + leftSize - 1,
        inorderArray,
        postOrderArray
    );

    //������ Ʈ�� Ž��
    solution(
        rootIndexInorderArray + 1,
        inorderEnd,
        postorderStart + leftSize,
        postorderEnd - 1,
        inorderArray,
        postOrderArray
    );



    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    int inorderArray[n];
    int postorderArray[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &inorderArray[i]);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &postorderArray[i]);
    }

    solution(0, n - 1, 0, n - 1, inorderArray, postorderArray);
    return 0;
}


