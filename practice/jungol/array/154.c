//
#include <stdio.h>

int array_5(){
    float a[256] , sum = 0;
    for(int i = 0 ; i< 6 ; i++){
        scanf("%f", a+i);
        sum += *(a+i);
    }
    printf("%.1f\n", (sum/6));
    
    
    return 0;
}
