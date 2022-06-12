#include <stdio.h>

int main() {
    int N, x, y;
    scanf("%d", &N);

    int arr[100001];

    for (int j = 0; j < N; ++j) {
        scanf("%d.%d", &x, &y);
        arr[x * 1000 + y]++;
    }

    int cnt = 0;

    for (int i = 0; i < 100001; i++) {
        if (!arr[i]) {
            continue;
        }

        while (arr[i] != 0) {
            cnt++;
            arr[i]--;
            if (i / 1000 == 0) {
                printf("00.%03d\n", i % 1000);
            } else {
                printf("%d.%03d\n", i / 1000, i % 1000);
            }
            if (cnt == 7) {
                return 0;
            }
        }

    }

    return 0;
}