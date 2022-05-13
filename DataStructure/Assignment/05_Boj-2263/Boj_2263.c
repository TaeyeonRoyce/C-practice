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
    //단말 노드 방문 시 return
    if (inorderStart > inorderEnd || postorderStart > postorderEnd){
        return 0;
    }

    int root = postOrderArray[postorderEnd];

    //해당 루트 출력
    printf("%d ", root);

    //인오더 배열에서 루트 노드 위치 찾기
    int cnt = 0;
    while(inorderArray[cnt] != root) {
        cnt++;
    }

    int rootIndexInorderArray = cnt;
    int leftSize = cnt - inorderStart; //왼쪽 서브트리 크기


    //전위 탐색법이기 때문에 왼쪽 서브트리부터 순회
    //왼쪽 트리 탐색
    solution(
            inorderStart,
            rootIndexInorderArray - 1,
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


    int *inorderArray = malloc(sizeof(int) * n);
    int *postorderArray = malloc(sizeof(int) * n);

    //인오더 입력 동적으로 저장
    for (int i = 0; i < n; ++i) {
        scanf("%d", &inorderArray[i]);
    }

    //포스트오더 입력 동적으로 저장
    for (int i = 0; i < n; ++i) {
        scanf("%d", &postorderArray[i]);
    }

    //재귀 실행
    solution(0, n - 1, 0, n - 1, inorderArray, postorderArray);
    return 0;
}