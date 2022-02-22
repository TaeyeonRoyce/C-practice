//
#include <stdio.h>

void dp_3(int a){
    for (int i = 1; i <= a; i++){
        for (int j =1; j<= a; j++) printf("%d ", i*j);
        printf("\n");
    }
}

int function_3(){
    int a;
    scanf("%d", &a);
    dp_3(a);
    
    
    return 0;
}
