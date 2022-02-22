//
#include <stdio.h>

int diff_4(int a, int b){
    if (a >= b) return (a*a-b*b);
    else return (b*b-a*a);
}

int function_4(){
    int a,b;
    scanf("%d %d", &a, &b);
    printf("%d\n", diff_4(a,b));
    return 0;
}
