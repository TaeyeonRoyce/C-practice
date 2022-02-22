//
#include <stdio.h>

int array_18(){
    int a[4][2],sum = 0;
    for (int i = 0; i < 4; i++){
        scanf("%d", (*(a+i)));
        scanf("%d", (*(a+i)+1));
        sum += *(*(a+i))+(*(*(a+i)+1));
        
    }
    for (int i = 0; i < 4; i++) printf("%d ", (*(*(a+i))+(*(*(a+i)+1)))/2);
    printf("\n");
    for (int i = 0; i < 2; i++) printf("%d ",(*(*(a)+i)+(*(*(a+1)+i))+(*(*(a+2)+i))+ (*(*(a+3)+i)))/4);
    printf("\n");
    printf("%d\n", sum/8);
    
    return 0;
}
