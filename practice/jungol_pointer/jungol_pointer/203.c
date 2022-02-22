//

#include <stdio.h>

int prt_4(){
    
    int a[10];
    int *ptr = a ,even = 0, odd = 0;
    
    for (int i = 0; i < 10; i++){
        scanf("%d", &ptr[i]);
        if(ptr[i] % 2 == 0) even++;
        else odd++;
    }
    printf("odd : %d\n", odd);
    printf("even : %d\n", even);
    
    
    return 0;
}
