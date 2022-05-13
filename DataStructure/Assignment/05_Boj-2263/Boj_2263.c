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
    //������ ��� �湮 �� return
    if (inorderStart > inorderEnd || postorderStart > postorderEnd){
        return 0;
    }

    //����Ʈ���� �迭�� ���� ���� Ʈ���� ��Ʈ ��� ã��
    int root = postOrderArray[postorderEnd];

    //�ش� ��Ʈ ���
    //��������(���� ǥ����)������ Ʈ��(����Ʈ��)���� ��Ʈ�� �켱 ��ȸ�ϱ� ���� (���� -> ������)
    printf("%d ", root);

    //����Ʈ���� �迭���� ã�� ��Ʈ ��尡
    //�ο��� �迭������ ��ġ ã��
    int cnt = 0;
    while(inorderArray[cnt] != root) {
        cnt++;
    }
    int rootIndexInorderArray = cnt; //�ο��� �迭������ ���� ��Ʈ����� ��ġ(�ε���)
    int leftSize = cnt - inorderStart; //���� Ʈ���� ���ۺκп��� ��Ʈ �������� �Ÿ�(ũ��) = ���� ����Ʈ���� ũ��


    //���� Ž�����̱� ������ ���� ����Ʈ������ ��ȸ
    //���� Ʈ�� Ž��
    solution(
        inorderStart, //��Ʈ ��� ��ġ�� �������� ������ ������ Ž���ϱ� ?���� inorderStart�� ����
        rootIndexInorderArray - 1, //��Ʈ ��� �ٷ� ���ʿ� ��ġ�ϴ� ��尡 ���� ����Ʈ���� ��
        postorderStart,
        postorderStart + leftSize - 1, //���� ����Ʈ���� ũ�⸸ŭ ������ �̵��ؾ� �ش� ����Ʈ���� ��Ʈ ��带 ã�� �� ����
        inorderArray,
        postOrderArray
    );

    //������ Ʈ�� Ž��
    solution(
        rootIndexInorderArray + 1, //��Ʈ ��� �ٷ� �����ʿ� ��ġ�ϴ� ��尡 ������ ����Ʈ���� ����
        inorderEnd,
        postorderStart + leftSize, //������ �湮�ߴ� ���� ����Ʈ���� ����
        postorderEnd - 1, //���� ����Ʈ���� ��Ʈ ���
        inorderArray,
        postOrderArray
    );



    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    //�ο��� �Է� ���� �迭
    int *inorderArray = malloc(sizeof(int) * n);
    //����Ʈ���� �Է� ���� �迭
    int *postorderArray = malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &inorderArray[i]);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &postorderArray[i]);
    }

    //
    solution(0, n - 1, 0, n - 1, inorderArray, postorderArray);
    return 0;
}


