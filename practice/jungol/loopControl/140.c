//정수 20 개를 입력받아서 그 합과 평균을 출력하되 0 이 입력되면 20개 입력이 끝나지 않았더라도 그 때까지 입력된 합과 평균을 출력하는 프로그램을 작성하시오.
//평균은 소수부분은 버리고 정수만 출력한다.(0이 입력된 경우 0을 제외한 합과 평균을 구한다.)

#include <stdio.h>

int loopCon_16(){
    int cnt = 0, sum = 0;
    while(1){
        if (cnt == 20) break;
        int a;
        scanf("%d", &a);
        if (a == 0) break;
        else{
            sum += a;
            cnt++;
        }
    }
    printf("%d %d\n" , sum, sum/cnt);
    return 0;
}


//#include <stdio.h>
//int main()
//{
//    int a, i;
//    int sum = 0;
//    for(i=0;i<20;i++){
//        scanf("%d", &a);
//        sum += a;
//        if(a==0)break;
//    }
//    printf("%d %d", sum, sum/i);
//}
