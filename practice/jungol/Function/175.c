//

#include <stdio.h>

int input__6(){
    int a;
    scanf("%d", &a);
    return a;
}
void array__6(int k[],int a){
    for (int i = 0; i < a; i++) scanf("%d", k+i);
}
void sort__6(int k[],int a){
    for (int j = 0; j < a; j ++){
        for (int p = 0; p < a; p++){
            if (*(k+j) >= *(k+p)){
                int tmp = 0;
                tmp = *(k+p);
                *(k+p) = *(k+j);
                *(k+j) = tmp;
            }
        }
    }
}
void print_6(int k[], int a){
    for (int i = 0 ; i < a ; i++) printf("%d ", *(k+i));
}
int function_6(){
    int a = input__6();
    int k[256];
    array__6(k,a);
    sort__6(k,a);
    print_6(k,a);
    return 0;
}
