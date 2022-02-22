// 정수를 입력받아 1부터 입력받은 정수까지를 차례대로 출력하는 프로그램을 작성하시오.

#include <stdio.h>

int loopCon_1(){
    int a;
    scanf("%d", &a);
    
    for (int i = 1; i < a + 1; i++){
        printf("%d ", i);
    }
    return 0;
}
