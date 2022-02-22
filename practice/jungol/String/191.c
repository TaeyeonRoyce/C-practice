//

#include <stdio.h>

int str_10(){
    char a[50][100] = {0};
    int i = 0;
    for (; i< 50; i++){
        scanf("%s",a[i]);
        if (a[i][0] == '0') break;
    }
    printf("%d\n",  i);
    for (int j = 0; 2*j < i; j++) printf("%s\n", a[2*j]);
    return 0;
}
