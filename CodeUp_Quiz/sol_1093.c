#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int students[23] = {0};

    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        students[num - 1]++;
    }

    for (int i = 0; i < 23; ++i) {
        printf("%d ", students[i]);
    }

    return 0;
}

