//
#include <stdio.h>

int str_2(){
    
    char a[100];
    scanf("%s", a);
    for(int i = 0; i < 5; i++) printf("%c ",*(a+i));
    
    return 0;
}
