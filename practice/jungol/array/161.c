//

#include <stdio.h>

int array_12(){
    int b[11] = {0},c;
    for (int i = 0 ; i < 100; i++){
        scanf("%d", &c);
        if (c == 0) break;
        *(b+(int)c/10) += 1;
    }
    for (int i = 10 ; i >= 0; i--) {
        if (*(b+i) == 0) continue;
        else
            printf("%d : %d person\n", i*10,*(b+i));
    }
    return 0;
}
