
#include <stdio.h>

int shaping_7(){

    int a;
    scanf("%d" , &a);
    for (int i  = 0 ; i < a + 1; i++ ){
        for (int j = 0 ; j < i ; j++) printf("# ");
        printf("\n");
    }
    for (int i = 1; i < a ; i++){
        for (int k = 0 ; k < i ; k ++) printf("  ");
        for (int j = a - i ; j > 0 ; j--) printf("# ");
        printf("\n");
        }

    return 0;
}

