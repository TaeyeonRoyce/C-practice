//
int func_4(int a){
    if(a == 1) return 1;
    if(a == 2) return 2;
    
    return (func_4(a-1)*func_4(a-2))%100;
    
}
#include <stdio.h>

int reFunction_4(){
    int a;
    scanf("%d", &a);
    printf("%d\n", func_4(a));
    return 0;
}
