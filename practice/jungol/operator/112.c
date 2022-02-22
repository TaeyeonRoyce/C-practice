//두 정수를 입력받아서 나눈 몫과 나머지를 다음과 같은 형식으로 출력하는 프로그램을 작성하시오.

#include <stdio.h>

int operator_2(){
    
    int a, b;
    scanf("%d %d", &a, &b);
    
    printf("%d / %d = %d...%d\n", a, b, a/b, a%b);
    
    return 0;
    
}
