//국어 영어 수학 컴퓨터 과목의 점수를 정수로 입력받아서 총점과 평균을 구하는 프로그램을 작성하시오. (단 평균의 소수점 이하는 버림 한다.)

#include <stdio.h>

int operator_1(){
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    printf("sum %d\n", a+b+c+d);
    printf("avg %d", (a+b+c+d)/4);
    
    return 0;
    
}
