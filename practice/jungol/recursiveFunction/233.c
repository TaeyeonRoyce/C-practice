//

#include <stdio.h>
int sum_3[10];
int a_3 = 0;
void dice_3(int n, int m){
    for(int i = 1 ; i <= 6; i++){
        *(sum_3 + a_3) = i;
        if (a_3 == n - 1){
            int s = 0;
            for (int j = 0; j <= a_3; j++)
                s += *(sum_3+j);
            if (s == m){
                for (int k = 0; k < n; k++)
                    printf("%d ", *(sum_3+k));
                printf("\n");
                return ;
            }
        }
        else {
            a_3++;
            dice_3(n,m);
            a_3--;
        }
    }
}


int reFunction_3(){
    int n,m;
    scanf("%d %d", &n ,&m);
    dice_3(n,m);
    return 0;
}
