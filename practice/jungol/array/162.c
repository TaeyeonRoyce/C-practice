//

#include <stdio.h>

int array_13(){
    int a[10];
    scanf("%d %d", a, a+1);
    for(int i = 2; i < 10 ; i++) *(a+i) = *(a+i-2)+*(a+i-1);
    for(int i = 0; i < 10 ; i++) printf("%d ", *(a+i)%10);
    
    return 0;
}
