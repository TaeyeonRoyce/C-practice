#include <stdio.h>

int main() {
    long long a, d, n;

    scanf("%d %d %d", &a, &d, &n);

    int index = 0;
    while (index < n - 1) {
        a *= d;
        index += 1;
    }

    printf("%ld", a);
    return 0;
}
