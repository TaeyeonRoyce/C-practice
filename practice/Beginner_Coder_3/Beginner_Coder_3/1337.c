//

#include <stdio.h>

int main(){
    int n,cnt = 0;
    scanf("%d",&n);
    int a[n][n];
    int k = n, i = 0, j = 0;
    while(1){
        for (; i < k; i++, j++){
            a[i][j] = cnt;
            cnt++;
            if (cnt > 9) cnt = 0;
            }
        k--;
        i--;
        j--;
        for (; ; ){
            
            }
        for (int ){
            
            }
        }
    for (int i = 0; i < n; i++){
        for (int j = 0 ; j <= i; j++) printf("%d ",a[i][j]);
        printf("\n");
    }
    
    
    
    return 0;
}
