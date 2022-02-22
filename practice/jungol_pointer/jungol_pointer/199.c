//10 이하의 정수 n을 입력받은 후 n명의 이름(영문자 20자 이하)과 세 과목의 점수를 입력받아 총점이 높은 순으로 정렬하여 출력하는 프로그램을 작성하시오.

#include <stdio.h>
typedef struct Score{
    char name[20];
    int a,b,c,d;
}ls_1;


int struct_5(){
    
    int n;
    scanf("%d", &n);
    int num[n];
    ls_1 k[n];
    for (int i = 0; i < n ; i++){
        scanf("%s %d %d %d",k[i].name,&k[i].a,&k[i].b,&k[i].c);
        k[i].d = k[i].a + k[i].b + k[i].c;
        *(num+i) = k[i].d;
    }
    
    for (int i = 0; i < n ; i++){
        for (int j = 0; j < n; j++){
            if (*(num+i) > *(num+j)){
                int tmp = 0;
                tmp = *(num+i);
                *(num+i) = *(num+j);
                *(num+j) = tmp;
            }
        }
    }
    for (int i = 0; i < n; i++){
        int pk = *(num+i);
        for (int j = 0; j < n; j++){
            if (pk == k[j].d)
                printf("%s %d %d %d %d\n", k[j].name, k[j].a ,k[j].b ,k[j].c, k[j].d);
        }
    }
    return 0;
}
//int num,i,j;
//scanf("%d",&num);
//Person a[num],tmp;
//for(i = 0; i<num; i++) {
//    scanf("%s %d %d %d",a[i].name,&a[i].korean,&a[i].math,&a[i].english);
//    a[i].sum = a[i].korean+a[i].math+a[i].english; }
//for(i = 0; i<num; i++) {
//    for(j = i; j<num; j++) {
//        if(a[i].sum < a[j].sum) {
//            tmp = a[i]; a[i] = a[j];
//            a[j] = tmp; }
//
//    }
//
//}
//for(i = 0; i<num; i++) { printf("%s %d %d %d %d\n",a[i].name,a[i].korean,a[i].math,a[i].english,a[i].sum); } return 0;
//
