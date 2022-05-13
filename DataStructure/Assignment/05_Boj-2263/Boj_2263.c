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
    //마지막 노드 방문 시 return
    if (inorderStart > inorderEnd || postorderStart > postorderEnd){
        return 0;
    }

    //포스트오더 배열을 통해 현재 트리의 루트 노드 찾기
    int root = postOrderArray[postorderEnd];

    //해당 루트 출력
    //프리오더(전위 표현식)에서는 트리(서브트리)들의 루트를 우선 순회하기 때문 (왼쪽 -> 오른쪽)
    printf("%d ", root);

    //포스트오더 배열에서 찾은 루트 노드가
    //인오더 배열에서의 위치 찾기
    int cnt = 0;
    while(inorderArray[cnt] != root) {
        cnt++;
    }
    int rootIndexInorderArray = cnt; //인오더 배열에서의 현재 루트노드의 위치(인덱스)
    int leftSize = cnt - inorderStart; //현대 트리의 시작부분에서 루트 노드까지의 거리(크기) = 왼쪽 서브트리의 크기


    //전위 탐색법이기 때문에 왼쪽 서브트리부터 순회
    //왼쪽 트리 탐색
    solution(
        inorderStart, //루트 노드 위치를 기준으로 오른쪽 구간을 탐색하기 ?문에 inorderStart는 유지
        rootIndexInorderArray - 1, //루트 노드 바로 왼쪽에 위치하는 노드가 왼쪽 서브트리의 끝
        postorderStart,
        postorderStart + leftSize - 1, //왼쪽 서브트리의 크기만큼 끝단을 이동해야 해당 서브트리의 루트 노드를 찾을 수 있음
        inorderArray,
        postOrderArray
    );

    //오른쪽 트리 탐색
    solution(
        rootIndexInorderArray + 1, //루트 노드 바로 오른쪽에 위치하는 노드가 오른쪽 서브트리의 시작
        inorderEnd,
        postorderStart + leftSize, //그전에 방문했던 왼쪽 서브트리는 제외
        postorderEnd - 1, //다음 서브트리의 루트 노드
        inorderArray,
        postOrderArray
    );



    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    //인오더 입력 저장 배열
    int *inorderArray = malloc(sizeof(int) * n);
    //포스트오더 입력 저장 배열
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


