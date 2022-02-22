//

#include <stdio.h>

int str_1(){
    char a,b;
    scanf("%c %c", &a,&b);
    if ((int)a < (int)b) printf("%d %d\n", a+b, b-a);
    else printf("%d %d\n", a+b, a-b);
    return 0;
}
