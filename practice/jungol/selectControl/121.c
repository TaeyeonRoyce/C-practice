//정수를 입력받아 0 이면 "zero" 양수이면 "plus" 음수이면 "minus" 라고 출력하는 프로그램을 작성하시오.

#include <stdio.h>

int selCon_2(){
    int a;
    scanf("%d" , &a);
    if (a == 0){
        printf("zero\n");
    }
    else if (a > 0){
        printf("plus\n");
    }
    else{
        printf("minus\n");
    }
    return 0;
}
