//정수를 입력받아서 1부터 입력받은 정수까지의 5의 배수의 합을 구하여 출력하는 프로그램을 작성하시오.

#include <stdio.h>

int loopCon_8(){
    int a, b = 0;
    scanf("%d", &a);
    for (int i = 1; i <= a; i++){
        if (i % 5 == 0) b += i;
    }
    printf("%d\n", b);
    
    return 0;
}
