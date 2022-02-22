//
#include <stdio.h>

typedef struct p{
    char name[100], tel[100], addr[100];
}p2;
int struct_1(){
    p2 p1;
    scanf("%s %s %s",p1.name,p1.tel,p1.addr);
    printf("name : %s\n", p1.name);
    printf("tel : %s\n", p1.tel);
    printf("addr : %s\n", p1.addr);
    return 0;
}
