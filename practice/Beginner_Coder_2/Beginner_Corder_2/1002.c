//

#include <stdio.h>
#include <string.h>

int GCD(int x, int y){
    for (int i = x; i > 0; i--){
        if(x % i == 0 && y % i == 0) return i;
    }
    return 1;
}


int beginner_7(){
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d",&a[i]);
    int gcd = a[0];
    int lcm = a[0];
    for (int i = 0; i < n-1; i++){
        gcd = GCD(gcd,a[i+1]);
        lcm = lcm*a[i+1]/GCD(lcm, a[i+1]);
    }
    printf("%d %d\n",gcd,lcm);
    return 0;
}
