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


    //전위 탐색법이기 때문에 왼쪽 서브트리부터 순회
    //왼쪽 트리 탐색
    solution(
        inorderStart,
        rootIndexInorderArray - 1, //중간을 기준으로 왼쪽 서브트리의 마지막 인덱스가 들어가야 함
        postorderStart,
        postorderStart + leftSize - 1,
        inorderArray,
        postOrderArray
    );

    //오른쪽 트리 탐색
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


