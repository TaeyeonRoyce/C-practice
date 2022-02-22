//

#include <stdio.h>
int round_10(float a){
    if (a - (int)a >= 0.5) a = (int)a + 1;
    else a = (int)a;
    return a;
}

int function_10(){
    float a,b,c;
    
    scanf("%f %f %f", &a, &b, &c);
    float d =((float)round_10(a)+(float)round_10(b)+(float)round_10(c))/3;
    printf("%d\n" ,(round_10((a+b+c)/3)));
    printf("%d\n" ,round_10(d));
    
    return 0;
}
