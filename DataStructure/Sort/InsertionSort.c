//
// Created by ¿øÅÂ¿¬ on 2022/05/23.
//

#include <stdio.h>

int InsertSort(int arr[], int n) {
    int i, j;
    int insData;

    for(i = 1; i < n; i++) {
        insData = arr[i];
        for(j = i - 1; j >= 0; j--) {
            if(arr[j] >	insData)
                arr[j + 1] = arr[j];
            else
                break;
        }

        arr[j + 1] = insData;
    }

    return 0;
}

int main(void) {
    int arr[] = {5, 4, 3, 2 ,1};
    int i;

    InsertSort(arr, sizeof(arr) / sizeof(arr[0]));

    for(i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}