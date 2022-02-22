//

#include <stdio.h>
#define pi 3.141592

double CircleArea_12(double a){
    
    
    return (a*a*pi);
}

int function_12(){
    double a;
    printf("radius : ");
    scanf("%lf", &a);
    
    printf("area = %.3lf\n", CircleArea_12(a));
    
    
    return 0;
}
