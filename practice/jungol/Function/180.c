//
#include <stdio.h>
#define Num 7

void change_11(int a[],int num){
    for(int i = 0; i < num-1; i++){
        if (*(a+i) > *(a+i+1)) {
            int tmp = 0;
            tmp = *(a+i);
            *(a+i) = *(a+i+1);
            *(a+i+1) = tmp;
        }
        else continue;
    }
}

int function_11(){
    int a[Num];
    for (int i = 0; i < Num; i++) scanf("%d", a+i);
    for (int i = 0; i < 3; i++) change_11(a,Num);
    for (int i = 0; i < 7; i++) printf("%d ", *(a+i));
    return 0;
}
