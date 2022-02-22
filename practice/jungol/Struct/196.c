//

#include <stdio.h>
#include <string.h>
typedef struct p1{
    char name[15], tel[15], addr[15];
}p2;

int struct_2(){
    
    p2 a[3];
    int j = 0;
    for (int i = 0; i < 3; i++) scanf("%s %s %s", a[i].name,a[i].tel,a[i].addr);
    for(int i = 1 ; i < 3;i++){
        if (strcmp(a[0].name,a[i].name) > 0) j = i;
    }
    printf("name : %s\n", a[j].name);
    printf("tel : %s\n", a[j].tel);
    printf("addr : %s\n", a[j].addr);
    return 0;
}

//int main(){
//    p2 p_1,p_2,p_3;
//    scanf("%s %s %s", p_1.name,p_1.tel,p_1.addr);
//    scanf("%s %s %s", p_2.name,p_2.tel,p_2.addr);
//    scanf("%s %s %s", p_3.name,p_3.tel,p_3.addr);
//    if(strcmp(p_1.name,p_2.name) < 0 && strcmp(p_1.name,p_3.name) < 0){
//        printf("name : %s\n", p_1.name);
//        printf("tel : %s\n", p_1.tel);
//        printf("addr : %s\n", p_1.addr);
//    }
//    else if(strcmp(p_2.name,p_1.name) < 0 && strcmp(p_2.name,p_3.name) < 0){
//        printf("name : %s\n", p_2.name);
//        printf("tel : %s\n", p_2.tel);
//        printf("addr : %s\n", p_2.addr);
//    }
//    else if(strcmp(p_3.name,p_2.name) < 0 && strcmp(p_3.name,p_1.name) < 0){
//        printf("name : %s\n", p_3.name);
//        printf("tel : %s\n", p_3.tel);
//        printf("addr : %s\n", p_3.addr);
//    }
//
//    return 0;
//}
