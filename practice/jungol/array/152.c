//
#include <stdio.h>

int array_3(){
    int a[256], odd = 0 , even = 0;
    for (int i = 0; i < 10; i++) scanf("%d" , a+i);
    for (int i = 0; i < 10; i += 2) odd += a[i];
    for (int i = 1; i < 10; i += 2) even += a[i];
    printf("odd : %d\n", odd);
    printf("even : %d\n", even);
    return 0;
}
