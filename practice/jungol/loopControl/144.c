

#include <stdio.h>

int shaping_3(){
    int a;
    scanf("%d", &a);
    for (int i = a; i > 0; i--){
        for (int j = 1; j < 2*i - 1 ; j++) printf(" ");
        for (int k = 2*i; k <= 2*a ; k++) printf("*");
        printf("\n");
    }
    
    return 0;
}
