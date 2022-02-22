//


#include <stdio.h>


int beginner_3(){
    int n,m;
    scanf("%d", &n);
    int a[n],sum_d = 0, sum_x = 0;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 1; i < n+1; i++) {
        if(m % a[i-1] == 0) sum_d += a[i-1];
        if(a[i-1] % m == 0) sum_x += a[i-1];
    }
    printf("%d\n%d\n",sum_d,sum_x);
    return 0;
}
