//
#include <stdio.h>

int beginner_2(){
    
    int a,b,c;
    scanf("%d %d %d", &a,&b,&c);
    int k = a*b*c;
    int cmp[10] = {0};
    while(1){
        if(k < 1) break;
        int p = k % 10;
        for (int i = 0; i < 10; i++){
            if (p == i) {
                cmp[i]++;
                k /= 10;
                break;
            }
        }
    }
    for(int i = 0 ; i < 10; i++)printf("%d\n",cmp[i]);
    return 0;
}
