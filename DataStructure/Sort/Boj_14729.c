#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(float arr[], int left, int mid, int right) {
    int fIdx = left;
    int rIdx = mid + 1;
    int i;

    int *sortArr = (float *)malloc(sizeof(float) * (right + 1));
    int sIdx = left;

    while(fIdx <= mid && rIdx <= right) {
        if(arr[fIdx] <= arr[rIdx])
            sortArr[sIdx] = arr[fIdx++];
        else
            sortArr[sIdx] = arr[rIdx++];

        sIdx++;
    }

    if(fIdx > mid) {
        for(i = rIdx; i <= right; i++, sIdx++)
            sortArr[sIdx] = arr[i];
    }
    else {
        for(i = fIdx; i <= mid; i++, sIdx++)
            sortArr[sIdx] = arr[i];
    }

    for(i = left; i <= right; i++) {
        arr[i] = sortArr[i];
    }

    free(sortArr);
}

void MergeSort(float arr[], int left, int right) {
    int mid;

    if(left < right) {
        mid = (left + right) / 2;

        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);

        MergeTwoArea(arr, left, mid, right);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    float *arr = malloc(sizeof(float) * N);

    for (int j = 0; j < N; ++j) {
        float score;
        scanf("%f", &score);
        arr[j] = score;
    }

    MergeSort(arr, 0, N - 1);

    for(int i = 0; i < 7; i++) {
        printf("%.3f\n", arr[i]);
    }
    return 0;
}