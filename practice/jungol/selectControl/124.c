//1~12사이의 정수를 입력받아 평년의 경우 입력받은 월을 입력받아 평년의 경우 해당 월의 날수를 출력하는 프로그램을 작성하시오.

#include <stdio.h>

int selCon_5(){
    int a;
    scanf("%d", &a);
    if (a == 1 || a == 3 || a == 5 || a == 7 || a == 8 || a == 10 || a == 12){
        printf("31\n");
    }
    else if (a == 2){
        printf("28\n");
    }
    
    else{
        printf("30\n");
    }
    
    return 0;
}
