//

#include <stdio.h>

int sum_5(int a, int b, int c){
    return a+b+c;
}


int function_5(){
    int a[4][4] = {0};
    for(int i = 0; i < 3; i ++){
        for (int j = 0; j < 3; j ++) scanf("%d", (*(a+i)+j));
        *(*(a+i)+3) = sum_5(*(*(a+i)),*(*(a+i)+1),*(*(a+i)+2));
    }
    for (int i = 0; i< 4; i++) *(*(a+3)+i) = sum_5(*(*(a)+i),*(*(a+1)+i),*(*(a+2)+i));

    for(int i = 0; i < 4; i ++){
        for (int j = 0; j < 4; j ++) printf("%d ", *(*(a+i)+j));
        printf("\n");
    }
    return 0;
}
