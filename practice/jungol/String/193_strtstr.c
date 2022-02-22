//

#include <stdio.h>
#include <string.h>
int str_12(){
    char a[5][100], b[2][100];
    int cnt = 0;
    for (int i = 0 ; i < 5;i++) scanf("%s", a[i]);
    scanf("%s %s", b[0], b[1]);
    
    for (int i = 0 ; i < 5; i++){
        if(strstr(a[i], b[0]) || strstr(a[i], b[1])){
            printf("%s\n", a[i]);
            cnt++;
        }
    }
    if (cnt == 0) printf("none\n");
    return 0;
}


