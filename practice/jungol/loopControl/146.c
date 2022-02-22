//
#include <stdio.h>

int shaping_5(){
    int a, alp = 0, num = 0;
    scanf("%d" , &a);
    for (int i = 0 ; i < a; i++){
        for (int k = 0; k < a - i; k ++){
            printf("%c ", 65 + alp);
            alp++;
        }
        for (int k = 0; k < i; k++){
            printf("%d ", num);
            num++;
        }
        printf("\n");
    }
    return 0;
}
