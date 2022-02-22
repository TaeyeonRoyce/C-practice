//행과 열의 수를 입력받아 다음과 같이 출력하는 프로그램을 작성하시오.

#include <stdio.h>

int loopCon_13(){
    int a, b;
    scanf("%d %d", &a, &b);
    
    for (int i = 1 ; i <= a; i++){
        for (int j = 1; j <= b; j++){
            printf("%d ", i*j);
        }
        printf("\n");
    }
    return 0;
}
