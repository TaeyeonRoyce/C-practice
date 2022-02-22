//


#include <stdio.h>

int beginner_4(){
    int n ,m,k = 0;
    scanf("%d %d",&n,&m);
    for (int i = 1; i <= n; i++){
        if(n % i == 0){
            k++;
            if(k == m) {
                printf("%d\n", i);
                return 0;
            }
        }
    }
    printf("0\n");
    return 0;
}
