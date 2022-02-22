//

#include <stdio.h>

typedef struct xy{
    int x,y;
}grid;

int struct_3(){
    
    grid a[4];
    for (int i = 0; i < 4; i++) scanf("%d %d",&a[i].x,&a[i].y);
    for (int i = 0; i < 4; i++){
        for(int k = i; k < 4; k++){
            if (a[i].x > a[k].x){
                int tmp = 0;
                tmp = a[k].x;
                a[k].x = a[i].x;
                a[i].x = tmp;
                }
            if (a[i].y > a[k].y){
                int tmp = 0;
                tmp = a[k].y;
                a[k].y = a[i].y;
                a[i].y = tmp;
                }
            }
        }
    printf("%d %d %d %d\n",a[0].x,a[0].y,a[3].x,a[3].y);
    return 0;
}
