//두 정수를 입력받아 첫 번째 수는 전치증가연산자를 사용하고 두 번째 수는 후치감소연산자를 사용하여 출력하고 바뀐 값을 다시 출력하는 프로그램을 작성하시오.



#include <stdio.h>

int operator_4(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d %d\n", ++a, b--);
    printf("%d %d\n", a, b);
    
    return 0;
}
