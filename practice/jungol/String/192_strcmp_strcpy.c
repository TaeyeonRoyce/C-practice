//
#include <stdio.h>
#include <string.h>

int str_11(){
    int a;
    char b[10][100] = {0};
    scanf("%d\n" , &a);
    for (int i = 0; i < a; i++) scanf("%s", b[i]);
    for (int i = 0; i < a; i++){
        for (int j = i + 1; j < a; j++){
            if(strcmp(b[i], b[j]) > 0){
                char tmp[100] = {0};
                strcpy(tmp,b[i]);
                strcpy(b[i],b[j]);
                strcpy(b[j],tmp);
            }
        }
    }
    for (int i = 0 ; i < a; i ++) printf("%s\n", b[i]);
    return 0;
}

