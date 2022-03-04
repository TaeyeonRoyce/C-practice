#include <stdio.h>

int main() {
    int n;
    int sum, index = 0;
    scanf("%d", &n);

    while (sum < n) {
        sum += index;
        index++;
    }
    printf("%d", sum);

    return 0;
}
