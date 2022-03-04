#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int answer = 23;

    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);

        if (num < answer) {
            answer = num;
        }
    }
    printf("%d", answer);

    return 0;
}

