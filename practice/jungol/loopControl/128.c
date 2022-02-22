//0 이 입력될 때까지 정수를 계속 입력받아 3의 배수와 5의 배수를 제외한 수들의 개수를 출력하는 프로그램을 작성하시오.


#include <stdio.h>

int loopCon_4(){
    int cnt = 0;
    while (1){
        int a;
        scanf("%d" , &a);
        if (a == 0) break;
        
        else if (a % 3 ==0 || a % 5 ==0) continue;
        
        else cnt += 1;
    }
    printf("%d\n", cnt);
    
    return 0;
}
