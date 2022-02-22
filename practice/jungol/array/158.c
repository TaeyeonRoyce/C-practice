//
#include <stdio.h>

int array_9(){
    int a[256], i = 0;
    for (; i < 100; i++){
        scanf("%d", a+i);
        if (*(a+i) == 0) break;
        else if (*(a+i) % 2 == 0) *(a+i) = *(a+i)/2;
        else if (*(a+i) % 2 == 1) *(a+i) = *(a+i)*2;
    }
    printf("%d\n" , i);
    for (int j = 0 ; j < i; j++) printf("%d ", *(a+j));
    
    
    return 0;
}
