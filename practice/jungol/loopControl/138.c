
#include <stdio.h>

int loopCon_14(){
    int a;
    scanf("%d", &a);
    
    for (int i = 1; i <= a; i++){
        for (int j = 1; j <= a; j++) printf("(%d, %d) ", i,j);
        printf("\n");
    }
    
    
    return 0;
}
