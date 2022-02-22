//10 이하의 자연수 n을 입력받아 "JUNGOL​"을 n번 출력하는 프로그램을 작성하시오.

#include <stdio.h>

int loopCon_6(){
    int a;
    scanf("%d", &a);
    for(int i = 0 ; i < a+1; i++){
        printf("JUNGOL\n");
    }
    return 0;
}
