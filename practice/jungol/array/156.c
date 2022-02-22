//

#include <stdio.h>

int array_7(){
    int a[256], i = 0;
    for (; i < 100 ; i++){
        scanf("%d", a+i);
        if (*(a+i) == 999) break;
    }
    int min = *(a), max = *(a);
    for (int j = 0 ; j < i; j++){
        if ( *(a+j) <= min ) min = *(a+j);
    }
    for (int j = 0 ; j < i; j++){
        if ( *(a+j) >= max ) max = *(a+j);
    }
    printf("max : %d\n", max);
    printf("min : %d\n", min);
    return 0;
}
