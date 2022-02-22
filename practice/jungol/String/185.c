//

#include <stdio.h>
#include <string.h>
int str_4(){
    char a[100],b;
    scanf("%s ", a);
    scanf("%c", &b);
    int i = 0;
    for( ; i <= strlen(a);i++) {
        if (*(a+i) == b) {
            printf("%d\n",i);
            break;
        }
        else if ( i == strlen(a)) printf("No\n");
    }
    return 0;
}
