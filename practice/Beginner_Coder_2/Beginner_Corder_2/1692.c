//
#include <stdio.h>

int beginner_1(){
    int a,b;
    scanf("%d %d", &a, &b);
    printf("%d\n", a*(b%10));
    printf("%d\n", a*(((int)b/10)%10));
    printf("%d\n", a*((int)b/100));
    printf("%d\n", a*b);
    
    
    
    
    return 0;
}
