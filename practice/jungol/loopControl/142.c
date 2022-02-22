//자연수 n을 입력받아 "출력 예"와 같이 출력되는 프로그램을 작성하시오.

//주의! '*'과 '*'사이에 공백이 없고 줄사이에도 빈줄이 없다.

#include <stdio.h>

int shaping_1(){
    int a;
    scanf("%d" , &a);
    for (int i = 1; i <= a ; i++){
        for (int  j = 1 ; j <= i ; j ++){
            printf("*");
        }
        printf("\n");
    }
    for (int i = 1; a >= i  ; a--){
        for (int  j = a-1 ; j > 0 ; j --){
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}
