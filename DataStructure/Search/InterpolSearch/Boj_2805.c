#include <stdio.h>
#include <stdlib.h>

int ISearch(int ar[], int first, int last, int heights[], int M, int N) {
    int mid = (last + first) / 2;

    if(ar[first] > mid || ar[last] < mid) {
        printf("%d", mid);
        return -1;
    }

    long diff = 0;
    for (int i = 0; i < N; ++i) {
        int cutLeft = heights[i] - mid;
        if (cutLeft > 0) {
            diff += cutLeft;
        }
    }

    if(diff == M) {
        printf("%d", mid);
        return 0;
    } else if(diff < M) {
        return ISearch(ar, first, mid - 1, heights, M, N);
    } else {
        return ISearch(ar, mid + 1, last, heights, M, N);
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int maxHeight = 0, height = 0;
    int *heights = (int *) malloc(sizeof(int) * N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &height);

        if (height > maxHeight) {
            maxHeight = height;
        }
        heights[i] = height;
    }

    int *numArr = (int *) malloc(sizeof(int) * maxHeight + 1);
    for (int i = 1; i < maxHeight + 1; ++i) {
        numArr[i] = i;
    }

    ISearch(numArr, 1, maxHeight, heights, M, N);
    return 0;
}