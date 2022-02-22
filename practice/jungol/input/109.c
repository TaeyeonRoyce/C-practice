//세 개의 정수를 입력받아 합과 평균을 출력하는 프로그램을 작성하시오.(단 평균은 소수 이하를 버림하여 정수 부분만 출력한다.)

#include <stdio.h>

int input_3(){
    
    int a ,b, c;
    scanf("%d %d %d", &a,&b,&c);
    
    printf("sum = %d\n",a+b+c);
    printf("avg = %d\n", (a+b+c)/3);
    
    return 0;
}

