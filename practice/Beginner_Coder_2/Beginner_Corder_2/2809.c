//

#include <stdio.h>
#include <math.h>

int beginner_5(){
    int a, cnt = 0;
    scanf("%d", &a);
    int k[10000];
    for (int i = 1; i <= (int)sqrt(a); i++) {
        if(a % i == 0) {
            k[cnt] = i;
            cnt++;
        }
    }
    for (int i = 0; i < cnt; i++) {
        if(k[i] == sqrt(a)) break;
        printf("%d ", k[i]);
    }
    for (int i = cnt-1; i >= 0; i--) printf("%d ", a/k[i]);
    
    return 0;
}
