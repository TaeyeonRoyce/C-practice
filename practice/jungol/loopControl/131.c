//100 이하의 두 개의 정수를 입력받아 작은 수부터 큰 수까지 차례대로 출력하는 프로그램을 작성하시오.

#include <stdio.h>

int loopCon_7(){
    int a, b;
    scanf("%d %d", &a, &b);
    if (a < b){
        for (; a < b + 1; a++) printf("%d\n", a);
    }
    else{
        for (; b < a + 1; b++) printf("%d\n", b);
    }
    return 0;
}
