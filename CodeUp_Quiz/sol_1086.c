#include <stdio.h>

int main() {

    long long w, h, b;
    scanf("%d %d %d", &w, &h, &b);


    double bit_per_MB = 1024 * 1024 * 8;
    double result = (w * h * b) / bit_per_MB;
    printf("%.2lf MB", result);

    return 0;
}
