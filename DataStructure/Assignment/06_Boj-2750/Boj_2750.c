#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void Swap(int arr[], int idx1, int idx2) {
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int Partition(int arr[], int left, int right) {
    int pivot = arr[left];
    int low = left + 1;
    int high = right;

    while(low <= high) {
        if(arr[low] <= pivot && low <= right)
            low++;

        if(arr[high] > pivot && high >= left + 1)
            high--;

        if(low <= high)
            Swap(arr, low, high);
    }

    Swap(arr, left, high);

    return high;
}

void QuickSort(int arr[], int left, int right) {
    if(left <= right) {

        int pivot = Partition(arr, left, right);
        QuickSort(arr, left, pivot - 1);
        QuickSort(arr, pivot + 1, right);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int *arr = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
    }

    QuickSort(arr, 0, N - 1);

    for(int i = 0; i < N; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}