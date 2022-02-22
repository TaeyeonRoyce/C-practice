//

#include <stdio.h>

int shaping_6(){
    int a, num = 1;
    scanf("%d", &a);
    for (int i = 0 ; i < a ; i++){
        for(int j = 0 ; j < i ; j++) printf("  ");
        for(int k  = a - i ; k > 0 ; k-- ) printf("%d ",num++);
        printf("\n");
    }
    
    return 0;
}
