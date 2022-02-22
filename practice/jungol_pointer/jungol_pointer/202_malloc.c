//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int ptr_3(){
    
    int *a = malloc(sizeof(int));
    int *b = (int*)malloc(sizeof(int));
    int *c = (int*)malloc(sizeof(int));
    scanf("%d %d", a, b);

    *c = abs(*a-*b);
    printf("%d", *c);
    return 0;
}
