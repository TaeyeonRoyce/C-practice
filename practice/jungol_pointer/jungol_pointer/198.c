//어떤 학생의 키는 아버지와 어머니의 키의 평균보다 5cm 크고 몸무게는 아버지와 어머니의 몸무게의 평균보다 4.5kg 가볍다고 한다.
//키와 몸무게를 멤버변수로 갖는 구조체를 정의하고 아버지와 어머니의 키와 몸무게를 입력받아 학생의 키와 몸무게를 출력하는 프로그램을 작성하시오.
//키는 정수미만 버림하고 몸무게는 반올림하여 소수 첫째자리까지 나타낸다.
#include <stdio.h>

typedef struct xy{
    int x;
    float y;
}parent;


int sturct_4() {
    
    parent a[2];
    scanf("%d %f %d %f", &a[0].x,&a[0].y,&a[1].x,&a[1].y);
    printf("height : %dcm\n",(a[0].x + a[1].x)/2+5);
    printf("weight : %.1fkg\n",(a[0].y + a[1].y)/2-4.5);
    
    return 0;
}
