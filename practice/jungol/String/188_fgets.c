//


#include <stdio.h>
#include <string.h>
int str_7(){
    char a[100];
    int b = 1;
    fgets(a,100,stdin);
    printf("%d. ", b);
    for (int i = 0; i < strlen(a); i++){
        if (*(a+i) == ' ') {
            b++;
            printf("\n");
            printf("%d. ", b);
        }
        else printf("%c", *(a+i));
        
    }
    return 0;
}
