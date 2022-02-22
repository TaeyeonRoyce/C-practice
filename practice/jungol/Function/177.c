//

#include <stdio.h>


int absolute_8(int a){
    if (a <= 0) return a*(-1);
    else return a;
}

int function_8(){
    
    int a[5], sum = 0;
    for(int i = 0 ; i < 5 ;i++) {
        scanf("%d", a+i);
        sum += absolute_8(*(a+i));
    }
    printf("%d\n", sum);
    return 0;
}
