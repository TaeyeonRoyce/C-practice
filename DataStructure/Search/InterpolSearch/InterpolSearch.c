#include <stdio.h>

int ISearch(int ar[], int first, int last, int target) {
    int mid;

    if(ar[first] > target || ar[last] < target) {
        return -1;
    }

    //º¸°£ Å½»öÀÇ ºñ·Ê°ü°è °è»ê ½Ä
    mid = ((double) (target - ar[first]) / (ar[last] - ar[first]) * (last - first)) + first;

    if(target == ar[mid]) {
        return mid;
    } else if(target < ar[mid]) {
        return ISearch(ar, first, mid - 1, target);
    } else {
        return ISearch(ar, mid + 1, last, target);
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int idx;

    idx = ISearch(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1, 7);
    if(idx == -1)
        printf("Å½»ö ½ÇÆÐ\n");
    else
        printf("Å½»ö ÀúÀå ÀÎµ¦½º : %d\n", idx);

    idx = ISearch(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1, 10);
    if(idx == -1)
        printf("Å½»ö ½ÇÆÐ\n");
    else
        printf("Å½»ö ÀúÀå ÀÎµ¦½º : %d\n", idx);

    return 0;
}