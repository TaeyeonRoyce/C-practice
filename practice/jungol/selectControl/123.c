//1번은 개, 2번은 고양이, 3번은 병아리로 정하고 번호를 입력하면 번호에 해당하는 동물을 영어로 출력하는 프로그램을 작성하시오.
//해당 번호가 없으면 "I don't know."라고 출력한다.
//개-dog
//고양이-cat
//병아리-chick


#include <stdio.h>

int selCon_4(){
    
    int a;
    printf("Number? ");
    scanf("%d", &a);
    if (a == 1){
        printf("dog\n");
    }
    else if (a == 2){
        printf("cat\n");
    }
    else if (a == 3){
        printf("chick\n");
    }
    else{
        printf("I don't know.\n");
    }
    
    
    return 0;
}
