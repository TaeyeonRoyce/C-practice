//

#include <stdio.h>

void divi_1(int a) {
    if (a <=0) return;
    
    divi_1(a/2);
    printf("%d ", a);
    return;
}



int reFunction_1(){
    int a;
    scanf("%d", &a);
    divi_1(a);
    return 0;
}

