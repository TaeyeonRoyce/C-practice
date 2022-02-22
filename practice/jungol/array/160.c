//

#include <stdio.h>

int array_11(){
    int a[6] = {0},b;
    for (int i = 0 ; i < 10; i ++){
        scanf("%d", &b);
//        for (int k = 0; k < 6; k++) if (b == k+1) *(a+k) += 1;
        *(a+b-1) += 1;
    }
    for (int j = 0; j < 6 ; j++) printf("%d : %d\n", j+1, *(a+j));
    return 0;
}
