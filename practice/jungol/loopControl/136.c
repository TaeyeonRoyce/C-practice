//한 개의 자연수를 입력받아 그 수의 배수를 차례로 10개 출력하는 프로그램을 작성하시오.

#include <stdio.h>

int loopCon_12(){
    int a;
    scanf("%d", &a);
    for (int i = 1; i <= 10 ; i++) printf("%d ",a*i);
    
    return 0;
}
