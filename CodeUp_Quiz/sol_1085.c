#include <stdio.h>

int main() {

    long long h, b, c, s;
    scanf("%d %d %d %d", &h, &b, &c, &s);


    double bit_per_MB = 1024 * 1024 * 8;
    double result = (h * b * c * s) / bit_per_MB;
    printf("%.1lf MB", result);

    return 0;
}
