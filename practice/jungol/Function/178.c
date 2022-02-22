//

#include <stdio.h>

int square_9(int a){
    int k = 1;
    for (int i = 1; i <= a; i++) k *= 2;
    return k;
}

int function_9(){
    
    int a;
    scanf("%d", &a);
    printf("%d\n", square_9(a));
    
    return 0;
}
