//


#include <stdio.h>


int beginner_3(){
    int N;
    scanf("%d", &N);
    if (N % 2 ==0 || N < 0 || N > 100){
        printf("INPUT ERROR!");
        return 0;
    }
    for (int i = 1 ; i < N + 1; i++){
        if (i <= N/2 + 1){
            for (int j = 1 ; j < i; j++) printf(" ");
            for (int j = 0 ; j < 2*i - 1; j++) printf("*");
        }
        else{
            for (int j = 0 ; j < N - i; j++) printf(" ");
            for (int j = 0 ; j < 2*(N-i) + 1; j++) printf("*");
        }
        printf("\n");
    }
    
    
    
    return 0;
}
