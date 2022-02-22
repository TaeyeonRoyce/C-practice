//

#include <stdio.h>

int array_17(){
    int a[2][3], b[2][3];
    printf("first array\n");
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++) scanf("%d", (*(a+i)+j));
    }
    printf("second array\n");
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++) scanf("%d", (*(b+i)+j));
    }
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++) printf("%d ", *(*(b+i)+j)*(*(*(a+i)+j)));
        printf("\n");
    }
    
    return 0;
}
