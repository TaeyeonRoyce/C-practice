#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
 * 문제 정의
 * 입력받은 문자열을 배열에 담아 그대로 출력하기
 * ex)
 *     input :
 *     aaa bbb ccc dd eeee
 *
 *     output :
 *     aaa bbb ccc dd eeee
 */


int main() {

    int n;

    char *words[100];

    printf("입력할 문자열의 수를 정해주세요 (100 이하) : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char user_input[100];
        printf("100자 이하의 문자열을 입력하세요: ");
        scanf("%s", user_input);
        //words[i]의 타입     : char*
        //userInput의 타입 : char[]

        //words[i] = user_input; <- 주소값을 공유 not value

        char *tmp;
        tmp = (char *) malloc(strlen(user_input) + 1);
        strcpy(tmp, user_input);

        words[i] = tmp;

        //words[i] = strdup(user_input);

    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", *(words + i));
    }
    return 0;
}
