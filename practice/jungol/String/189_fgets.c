//
#include <stdio.h>
#include <string.h>


int str_8(){
    char a[100], b[100][100] = {0};
    int k = 0, p =0;
    fgets(a,100,stdin);
    for(int i = 0 ; i < strlen(a); i++){
        if (*(a+i) == ' ') {
            k++;
            p = 0;
            continue;
        }
        if (*(a+i) == '\n') break;
        *(*(b+k)+p) = *(a+i);
        p++;
    }
    for (int i = k; i >= 0; i--){
        int p = 0;
        while (1){
            printf("%c", b[i][p]);
            p++;
            if (b[i][p] == 0) break;
        }
        printf("\n");
    }
    
    
    return 0;
}
