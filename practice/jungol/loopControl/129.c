//삼각형의 밑변의 길이와 높이를 입력받아 넓이를 출력하고, "Continue? "에서 하나의 문자를 입력받아 그 문자가 'Y' 나 'y' 이면 작업을 반복하고 다른 문자이면 종료하는 프로그램을 작성하시오.
//
//(넓이는 반올림하여 소수 첫째자리까지 출력한다.)

#include <stdio.h>

int loopCon_5(){
    int a, b;
    char k;
    while(1){
        printf("Base = ");
        scanf("%d", &a);
        printf("Height = ");
        scanf("%d", &b);
        printf("Triangle width = %.1f\n", ((float)a*(float)b)/2);
        printf("Continue? ");
        scanf(" %c", &k); //문자를 입력받을 때에는 %c 앞에 공백을 넣어 주어야 엔터, 공백과 같은 구분자를 입력받지 않고 한 개의 문자를 입력받을 수 있다.
        
        if (k != 'y' && k != 'Y') break;
        
    }
    return 0;
}
