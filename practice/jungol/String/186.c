//
#include <stdio.h>
#include <string.h>

int str_5(){
    char a[100] , b[100];
    scanf("%s %s",a,b);
    if (strlen(a) > strlen(b)) printf("%d\n", (int)strlen(a));
    else printf("%d\n", (int)strlen(b));
    
    
    return 0;
}
