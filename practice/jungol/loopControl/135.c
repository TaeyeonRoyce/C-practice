//두 개의 정수를 입력받아 두 정수 사이(두 정수를 포함)에 3의 배수이거나 5의 배수인 수들의 합과 평균을 출력하는 프로그램을 작성하시오.
//
//(평균은 반올림하여 소수 첫째자리까지 출력한다.)


#include <stdio.h>

int loopCon_11(){
    int a, b, sum = 0, cnt = 0;
    scanf("%d %d", &a, &b);
    if (a <= b){
        for (; a <= b ; a++){
            if (a % 3 == 0 || a % 5 ==0){
                sum += a;
                cnt += 1;
            }
        }
    }
    else {
        for (; b <= a ; b++){
            if (b % 3 == 0 || b % 5 ==0){
                sum += b;
                cnt += 1;
            }
        }
    }
    printf("sum : %d\n", sum);
    printf("avg : %.1f\n", (float)sum/cnt);
    
    return 0;
}
