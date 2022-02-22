//

#include <stdio.h>

int shaping_4(){
    int a;
    scanf("%d", &a);
    for (int i = a; i > 0; i--){
        int p = 1;
        for (int j = 1; j < 2*i - 1 ; j++) printf(" ");
        for (int k = i; k <= a ; k++) {
            printf("%d ", p);
            p++;
        }
        printf("\n");
    }
    
    return 0;
}
//#include <stdio.h>
//int main()
//{
//    int a, i, j;
//    scanf("%d", &a);
//    for(i=0;i<a;i++){
//        for(j=0;j<a-i-1;j++){
//            printf("  ");
//        }
//        for(j=0;j<i+1;j++){
//            printf("%d ",1+j);
//        }
//        printf("\n");
//    }
//}
