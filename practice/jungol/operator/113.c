//직사각형의 가로와 세로의 길이를 정수형 값으로 입력받은 후 가로의 길이는 5 증가시키고 세로의 길이는 2배하여 저장한 후 가로의 길이 세로의 길이 넓이를 차례로 출력하는 프로그램을 작성하시오.



#include <stdio.h>

int operator_3(){
    
    int a, b;
    scanf("%d %d", &a,&b);
    
    printf("width = %d\n", a+5);
    printf("length = %d\n", b*2);
    printf("area = %d\n", (a+5)*(b*2));
    
    return 0;
}
