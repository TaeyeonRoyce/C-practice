//
#include <stdio.h>

int array_1(){
    char arr [10];
    for (int i = 9 ; i >= 0; i--) scanf("%c", arr+i);
    for (int i = 0; i < 10; i++) printf("%c ", arr[i]);
    return 0;
}

