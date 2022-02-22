//
#include <stdio.h>

int loopCon_10(){
    int even = 0;
    int odd = 0;
    for(int i = 0; i <10 ; i++){
        int a;
        scanf("%d", &a);
        if (a%2 == 1){
            odd +=1;
        }
        else{
            even +=1;
        }
    }
    printf("even : %d\n", even);
    printf("odd : %d\n", odd);
    return 0;
}
