//
#include <stdio.h>

int array_16(){
    int a[5][7] = {{0,1,0,1,0,1,0},{0},{0},{0},{0}};
    for (int i = 1; i < 5; i++){
        for (int j = 1; j < 6; j++) *(*(a+i)+j) = *(*(a+i-1)+j-1)+*(*(a+i-1)+j+1);
    }
    for (int i = 0; i < 5; i++){
        for (int j = 1; j < 6; j++) printf("%d ", *(*(a+i)+j));
    printf("\n");
}
    return 0;
}
