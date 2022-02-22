//
#include <stdio.h>

int shaping_2(){
    int a;
    scanf("%d", &a);
    
    for (int i = 0; i < a ; i++){
        for(int j = 0; j < i ; j++) printf(" ");
        for(int k = 2*(a-i) - 1; k > 0; k--) {
            printf("*");
        }
        printf("\n");
    }
    for (int i = 1; i < a ; i++){
        for(int j = a - 1 ; j > i ; j--) printf(" ");
        for(int k = 0; k <= 2*i ; k++) {
            printf("*");
        }
        printf("\n");
    }
    
    
    return 0;
}
