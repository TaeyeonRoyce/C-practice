//
#include <stdio.h>
int a_5 = 0;
void func_5(int a){
    if (a == 1) return;
    else if (a % 2 == 0) func_5(a/2);
    else if (a % 2 == 1) func_5(a/3);
    a_5++;
}


int reFunction_5(){
    int a;
    scanf("%d", &a);
    func_5(a);
    printf("%d\n", a_5);
    return 0;
}
