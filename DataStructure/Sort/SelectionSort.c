
#include <stdio.h>

int SelSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[maxIdx])
                maxIdx = j;
        }
        int temp;
        temp = arr[maxIdx];
        arr[maxIdx] = arr[i];
        arr[i] = temp;
    }
    return 0;
}

int main(void) {
    int arr[] = {3, 4, 2, 1};
    int i;

    SelSort(arr, sizeof(arr) / sizeof(arr[0]));

    for(i = 0; i < 4; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}