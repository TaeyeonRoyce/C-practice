//두 개의 정수를 입력받아 큰 수에서 작은 수를 뺀 차를 출력하는 프로그램을 작성하시오.

#include <stdio.h>
#include <stdlib.h>
int selCon_1(){
    
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", abs(a-b));
    return 0;
}
