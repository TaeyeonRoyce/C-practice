//년도를 입력받아 윤년(leap year)인지 평년(common year)인지 판단하는 프로그램을 작성하시오.
//400으로 나누어떨어지면 윤년이다. 또는 4로 나누어떨어지고 100으로 나누어떨어지지 않으면 윤년이다. 나머지는 모두 평년이다.

#include <stdio.h>

int selCon_3(){
    int a;
    
    scanf("%d" , &a);
    
    if (a % 400 == 0 || (a % 4 == 0 && a % 100 !=0)){
        printf("leap year\n");
    }
    else{
        printf("common year\n");
    }
    
    
    return 0;
}
