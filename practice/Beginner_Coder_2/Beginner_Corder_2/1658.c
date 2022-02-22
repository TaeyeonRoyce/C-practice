//

#include <stdio.h>

int beginner_6(){
    int a,b;
    scanf("%d %d", &a,&b);
    for (int i = a; i > 0; i--){
        if(a % i == 0 && b % i ==0){
            printf("%d\n",i);
            printf("%d\n",a*b/i);
            break;
        }
    }
    
    return 0;
}
