//

#include <stdio.h>

int prt_5(){
    
    int n;
    scanf("%d", &n);
    int a[n];
    int* p = a;
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);
    int min = p[0], max = p[0];
    for (int i = 0 ; i< n; i++){
        if (p[i] > max) max = p[i];
        if (p[i] < min) min = p[i];
    }
    printf("max : %d\n", max);
    printf("min : %d\n", min);
    
    
    return 0;
}
