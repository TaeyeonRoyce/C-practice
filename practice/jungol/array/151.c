//
#include <stdio.h>

int array_2(){
    int a[256];
    for (int i = 0 ; i < 5; i ++) scanf("%d", a + i);
    printf("%d\n", a[0] + a[2] + a[4]);
    
    return 0;
}
