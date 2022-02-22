//

#include <stdio.h>
#include <string.h>
int str_13(){
    int n;
    char a[200],b[100];
    scanf("%s %s %d",a,b,&n);
    printf("%s\n",strcat(a, b));
    for (int i = 0 ; i < n ;i++) printf("%c", *(a+i));
    for (int i = n ; i < strlen(b) ;i++) printf("%c", *(b+i));
    return 0;
}
