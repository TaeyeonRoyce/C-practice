//

#include <stdio.h>

int su_2(int a){
    if (a % 2 == 0) {
        if (a <= 2) return 0;
    }
    else {
        if (a <= 1) return 0;
    }
    a = a - 2;
    su_2(a);
    printf("%d ",a);
    return 0;
}


int reFunction_2(){
    int a;
    scanf("%d", &a);
    su_2(a+2);
    return 0;
}
