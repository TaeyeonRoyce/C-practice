//

#include <stdio.h>
int a_6 = 1;

void func_6(int a){
    if (a / 10 >= 1){
        if (a % 10 == 0) a_6 *= a%10 +1;
        else a_6 *= a%10;
    }
    else {
        a_6 *=a;
        return;
    }
    func_6(a/10);
}
    


int reFunction_6(){
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    func_6(a*b*c);
    printf("%d\n", a_6);
    return 0;
}
