#include <stdio.h>

int main() {
    int a, m, d, n;
    scanf("%d %d %d %d", &a, &m, &d, &n);

    long long answer = a;
    int index = 0;
    while (index < n - 1) {
        answer = (answer * m) + d;
        index += 1;
    }

    printf("%ld", answer);
    return 0;
}
