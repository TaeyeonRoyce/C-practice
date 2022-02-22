//


#include <stdio.h>


void beginner_4Function(int x, int y){
    if (y == 0) return;
    y--;
    beginner_4Function(x+1, y);
    printf("%d ",x);
}

int beginner_4(){
    int n,m;
    scanf("%d %d", &n,&m);
    if (n % 2 ==0 || n < 1 || n > 100 || m < 1 || m > 3){
        printf("INPUT ERROR!");
        return 0;
    }
    if (m == 1){
        int cnt = 1;
        for (int i = 0; i < n; i++){
            if (i % 2 == 0){
                for (int j = 0; j < i + 1 ; j++) {
                    printf("%d ",cnt);
                    cnt++;
                    }
                }
            else {
                beginner_4Function(cnt, i + 1);
                cnt += i+1;
                }
            printf("\n");
            }
        }
    
    else if (m == 2){
        int cnt = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < i ; j++) printf("  ");
            for (int j = 0; j < 2*(n-i) - 1; j ++) printf("%d ",cnt);
            cnt++;
            printf("\n");
        }
    }
    else if (m == 3){
        for (int i = 0; i < n; i++){
            int cnt = 1;
            if (i< n/2 + 1){
                for (int j = 0; j < i + 1 ; j++){
                    printf("%d ",cnt);
                    cnt++;
                }
            }
            else
                for (int j = 0 ; j < n - i; j++){
                    printf("%d ",cnt);
                    cnt++;
                }
            printf("\n");
            }
        }
    return 0;
}
