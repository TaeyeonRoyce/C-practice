//
#include <stdio.h>

int array_8(){
    int a[256], k = 0, cnt = 0, sum = 0;
    for( int i = 0; i < 100; i++){
        scanf("%d", a+i);
        if (*(a+i) == 0) break;
        
        else if(*(a+i) % 5 == 0) {
            cnt++;
            sum += *(a+i);
            k++;
        }
    }
    printf("Multiples of 5 : %d\n", cnt);
    printf("sum : %d\n", sum);
    printf("avg : %.1f\n", (float)sum/k);
    
    return 0;
}
