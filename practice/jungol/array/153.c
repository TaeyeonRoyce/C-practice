//
#include <stdio.h>

int array_4(){
    int a[256], cnt = 0;
    for (int i = 0; i < 100; i++){
        scanf("%d", a+i);
        cnt++;
        if (*(a+i) == -1) break;
    }
    if (cnt <= 3)
        for(int i = 0; i < cnt-1 ; i++) printf("%d ", a[i]);
    else printf("%d %d %d\n", *(a+cnt-4),*(a+cnt-3),*(a+cnt-2));
        
    return 0;
}


//#include <stdio.h>
//int main()
//{
//    int a[100];
//    int i, tmp;
//    for(i=0;i<100;i++){
//        scanf("%d", &a[i]);
//        if(a[i] == -1)break;
//    }
//    if(i < 3) tmp = 0;
//    else tmp = i - 3;
//    for(;tmp<i;tmp++){
//        printf("%d ", a[tmp]);
//    }
//}
