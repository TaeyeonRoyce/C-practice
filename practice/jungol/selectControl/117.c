//실수로 된 3과목의 점수를 입력받아 총점은 정수부분의 합계를 출력하고 평균은 실수의 평균을 구한 뒤 정수부분만 출력하는 프로그램을 작성하시오.

#include <stdio.h>

int debug_2(){
    float a,b,c;
    scanf("%f %f %f", &a,&b,&c);
    
    printf("sum %d\n", (int)a + (int)b + (int)c);
    printf("avg %d\n", (int)(a+b+c)/3);
    return 0;
}
