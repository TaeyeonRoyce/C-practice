//대문자 A는 65로 저장되고 소문자 a는 97로 저장된다. 즉 소문자는 대문자보다 32가 더 크다.

#include <stdio.h>

int array_20(){
    char a[3][5];
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 5; j++){
            scanf(" %c", (*(a+i)+j));
        }
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 5; j++){
            printf("%c ", *(*(a+i)+j)+32);
        }
        printf("\n");
    }
    
    return 0;
}
