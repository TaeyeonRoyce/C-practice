
#include <stdio.h>

int sum_2(int a){
    int sum = 0;
    for (int i = 1; i <= a; i++) sum += i;
    
    return sum;
}

int function_2(){
    int a;
    scanf("%d", &a);
    
    printf("%d\n",sum_2(a));
    return 0;
}
