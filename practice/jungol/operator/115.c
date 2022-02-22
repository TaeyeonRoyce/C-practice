// 민수와 기영이의 키와 몸무게를 입력받아 민수가 키도 크고 몸무게도 크면 1 그렇지 않으면 0을 출력하는 프로그램을 작성하시오.
// (JAVA는 1 이면 true, 0 이면 false를 출력한다.)

#include <stdio.h>

int operator_5(){
    int a,b,c,d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    if (a > c && b > d){
        printf("1\n");
    }
    else{
        printf("0\n");
    }
    return 0;
}
