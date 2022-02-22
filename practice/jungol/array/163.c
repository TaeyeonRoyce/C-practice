//
#include <stdio.h>

int array_14(){
    int a[4][3] = {{3,5,9},{2,11,5},{8,30,10},{22,5,1}},sum = 0;
    for (int i = 0 ; i < 4; i ++){
        for (int j = 0 ; j < 3; j++) {
            sum += *(*(a+i)+j);
            printf("%d " , *(*(a+i)+j));
        }
        printf("\n");
    }
    printf("%d\n" , sum);
    return 0;
}
