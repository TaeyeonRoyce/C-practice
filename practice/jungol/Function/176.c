//
#include <stdio.h>
#include <math.h>

int root_7(float a, float b){
    a = sqrtf(a);
    b = sqrtf(b);
    int cnt = 0;
    if (a < b) {
        if (a == (int)a) a = (int)a;
        else a = (int) a + 1;
        b = (int)b;
        for(; a <= b ; a++) cnt++;}
    
    else {
        if (b == (int)b) b = (int)b;
        else b = (int) b + 1;
        a = (int)a;
        for(; b <= a ; b++) cnt++;
    }
    return cnt;
}

int function_7(){
    float a,b;
    scanf("%f %f", &a,&b);
    
    printf("%d\n", root_7(a, b));
    return 0;
}
