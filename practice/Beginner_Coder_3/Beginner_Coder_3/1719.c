//
#include <stdio.h>

int beginner_2(){
    int n,m;
    scanf("%d %d",&n,&m);
    if (n < 0 || n > 100 || m < 1 || m > 4 || n % 2 == 0){
        printf("INPUT ERROR!\n");
        return 0;
    }
    else if (m == 1){
        for (int i = 1; i < n + 1; i++){
            if (i > n/2 + 1) for (int j = 0; j < n - i + 1 ; j++) printf("*");
            else for(int j = 0; j < i; j++) printf("*");
            printf("\n");
        }
    }
    
    else if (m == 2){
        for (int i = 1; i < n + 1; i++){
            if (i > n/2 + 1) {
                for (int j = 0; j < i - (n/2 + 1); j++) printf(" ");
                for (int j = 0; j < n - i + 1 ; j++) printf("*");
            }
            else {
                for(int j = 0; j < (n/2 + 1) - i; j++) printf(" ");
                for(int j = 0; j < i; j++) printf("*");
            }
            printf("\n");
        }
    }
    else if (m == 3){
        for (int i = 0; i < n; i++){
            if (i < n/2 + 1) {
                for (int j = 0; j < i ; j++) printf(" ");
                for (int j = 0; j < n - 2*i; j ++) printf("*");
            }
            else{
                for (int j = 1; j < n - i ; j++) printf(" ");
                for (int j = 0; j < 2*(i+1)-n ; j ++) printf("*");
            }
            printf("\n");
        }
    }
    
    else if (m == 4){
        for (int i = 0; i < n; i++){
            if (i < n/2 + 1) {
                for (int j = 0; j < i; j++) printf(" ");
                for (int j = 0; j < n/2 + 1 - i; j++) printf("*");
            
            }
            else {
                for (int j = 0; j < n/2; j++) printf(" ");
                for (int j = 0; j < i - n/2 + 1; j++) printf("*");
            }
            printf("\n");
        }
        
        
    }
    
    return 0;
}

