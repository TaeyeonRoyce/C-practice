//

#include <stdio.h>

int array_10(){
    int a, b[256], i = 0;
    scanf("%d" , &a);
    for ( ; i < a ; i++) scanf("%d", b+i);
    for (int j = 0; j < i; j ++){
        for (int k = 0; k < i; k++){
            if (*(b+j) >= *(b+k)){
                int tmp = 0;
                tmp = *(b+j);
                *(b+j) = *(b+k);
                *(b+k) = tmp;
            }
            }
    }
    for (int j = 0 ; j < i ; j++) printf("%d\n" ,*(b+j));
    
    return 0;
}
