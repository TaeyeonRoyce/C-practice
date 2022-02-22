//
#include <stdio.h>

int array_15(){
    int a[4],k;
    for (int j = 0; j < 4; j++){
        printf("%dclass? ", j+1);
        int sum = 0;
        for (int i = 0; i < 3; i++){
            scanf("%d", &k);
            sum += k;
        }
        *(a+j) = sum;
    }
    for (int i = 0; i < 4; i++) printf("%dclass : %d\n", i+1, *(a+i));
    
    return 0;
}
