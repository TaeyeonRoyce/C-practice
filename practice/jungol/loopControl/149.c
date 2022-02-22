//

#include <stdio.h>

int shaping_8(){
    int a, cnt = 1;
    scanf("%d", &a);
    for (int i = 0 ; i < a; i++){
        for (int j  = 0; j < a; j ++){
            printf("%d ", cnt);
            cnt += 2;
            if (cnt >= 10) cnt = 1;
        }
        printf("\n");
    }
    
    
    return 0 ;
}
