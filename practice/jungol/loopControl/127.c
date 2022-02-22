//0 부터 100 까지의 정수를 계속 입력받다가 범위를 벗어나는 수가 입력되면 그 이전까지 입력된 자료의 합계와 평균을 출력하는 프로그램을 작성하시오.
//(평균은 반올림하여 소수 첫째자리까지 출력한다.)

//55 100 48 36 0 101

#include <stdio.h>

int loopCon_3(){
    int sum = 0, cnt = 0;
    
    while(1){
        int a;
        scanf("%d", &a);
        if (a > 100 || a < 0){
            break;
        }
        else{
            sum += a;
            cnt += 1;
        }
    }
    printf("sum : %d\n", sum);
    printf("avg : %.1f\n", ((float)sum/(float)cnt));
    return 0;
}
