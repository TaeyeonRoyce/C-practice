//100 이하의 자연수 n을 입력받고 n개의 정수를 입력받아 평균을 출력하는 프로그램을 작성하시오.
//(평균은 반올림하여 소수 둘째자리까지 출력하도록 한다.)

#include <stdio.h>

int loopCon_9(){
    int a, b, sum=0;
    scanf("%d", &a);
    for (int i = 0; i < a ; i ++){
        scanf("%d", &b);
        sum += b;
    }
    printf("%.2f\n", (float)sum/a);
    
    return 0;
}
