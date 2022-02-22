//
//"flower" "rose" "lily" "daffodil" "azalea"

#include <stdio.h>

int str_9(){
    char a[5][10] = {"flower","rose","lily","daffodil","azalea"}, b;
    int k = 0;
    scanf(" %c", &b);
    for (int i = 0 ; i < 5; i++){
        if (a[i][1] == b || a[i][2] == b){
            printf("%s\n",a[i]);
            k++;
        }
    }
    printf("%d\n", k);
    return 0;
}
