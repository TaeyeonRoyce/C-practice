#include <stdio.h>

int BubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < (n - i) - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return 0;
}


int main(void) {
    int arr[] = {3, 2, 4, 1};
    int i;

    BubbleSort(arr, sizeof(arr) / sizeof(arr[0]));

    for(i = 0; i < 4; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}