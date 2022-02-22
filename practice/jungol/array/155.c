//
#include <stdio.h>

int array_6(){
    char a[] = {'J', 'U', 'N', 'G', 'O', 'L'} , b;
    scanf(" %c", &b);
    int i = 0;
    for (; i < 6; i++){
        if (b == *(a+i)) {
            printf("%d\n", i);
            break;
        }
    }
    if (i == 6) printf("none\n");
    
    return 0;
}
