//
#include <stdio.h>

int beginner_1(){
    int n,m;
    scanf("%d %d",&n,&m);
    if (n < 0 || n > 100 || m < 1 || m > 3){
        printf("INPUT ERROR!\n");
        return 0;
    }
    else if (m == 1){
        for (int i = 1; i < n + 1; i++){
            for(int j = 0; j < i; j++) printf("*");
            printf("\n");
        }
    }
    
    else if (m == 2){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n - i; j++) printf("*");
            printf("\n");
        }
    }
    else if (m == 3){
        for (int i = 1; i < n + 1; i++){
            for (int j = 0; j < n - i; j++) printf(" ");
            for (int k = 0; k < 2*i - 1; k++) printf("*");
            printf("\n");
        }
    }
    
    return 0;
}
