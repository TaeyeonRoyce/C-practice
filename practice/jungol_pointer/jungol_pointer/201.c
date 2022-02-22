//

# include <stdio.h>
int ptr_2() {
    int a;
    int *p = &a;
    scanf("%d",p);
    for (int i = 0; i < *p; i++) printf("*");
    
    return 0;
}
