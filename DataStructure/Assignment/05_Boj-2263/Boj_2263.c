#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int solution(
        int inorderStart,
        int inorderEnd,
        int postorderStart,
        int postorderEnd,
        int inorderArray[],
        int postOrderArray[]
) {
    //�ܸ� ��� �湮 �� return
    if (inorderStart > inorderEnd || postorderStart > postorderEnd){
        return 0;
    }

    int root = postOrderArray[postorderEnd];

    //�ش� ��Ʈ ���
    printf("%d ", root);

    //�ο��� �迭���� ��Ʈ ��� ��ġ ã��
    int cnt = 0;
    while(inorderArray[cnt] != root) {
        cnt++;
    }

    int rootIndexInorderArray = cnt;
    int leftSize = cnt - inorderStart; //���� ����Ʈ�� ũ��


    //���� Ž�����̱� ������ ���� ����Ʈ������ ��ȸ
    //���� Ʈ�� Ž��
    solution(
            inorderStart,
            rootIndexInorderArray - 1,
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


    int *inorderArray = malloc(sizeof(int) * n);
    int *postorderArray = malloc(sizeof(int) * n);

    //�ο��� �Է� �������� ����
    for (int i = 0; i < n; ++i) {
        scanf("%d", &inorderArray[i]);
    }

    //����Ʈ���� �Է� �������� ����
    for (int i = 0; i < n; ++i) {
        scanf("%d", &postorderArray[i]);
    }

    //��� ����
    solution(0, n - 1, 0, n - 1, inorderArray, postorderArray);
    return 0;
}