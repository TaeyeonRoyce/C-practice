
#include <stdio.h>
#include <string.h>
int str_3(){

    char a[256];
    scanf("%s", a);
    for (int i =0; i < strlen(a) ; i++){
        int k = *(a+i);
        if (k >= 48 && k <= 57) printf("%c",k);
        else if (k >= 97 && k <= 122) printf("%c",k);
        else if (k >= 65 && k <= 90) printf("%c", k + 32);
    }
    return 0;
}

//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//
//int main(){
//
//    char a[100];
//    int i;
//    scanf("%s", a);
//    for(i=0; i< strlen(a) ;i++){
//        if(isalpha(a[i])||isdigit(a[i])){
//            printf("%c", tolower(a[i]));
//        }
//    }
//    return 0;
//}
