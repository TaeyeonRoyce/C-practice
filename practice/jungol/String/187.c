//
#include <stdio.h>
#include <string.h>
int str_6(){
    char a[100];
    int b;
    scanf("%s", a);
    int k = strlen(a);
    for (int i = 0; i < k-1;i++){
        scanf("%d", &b);
        if (b >= strlen(a)) b = (int)strlen(a);
        for (int j = b - 1; j < strlen(a) ; j++) *(a+j)= *(a+j+1);
        printf("%s\n",a);
    }
    return 0;
}
