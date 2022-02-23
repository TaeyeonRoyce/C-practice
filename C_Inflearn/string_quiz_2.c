#include <stdio.h>
#include <ctype.h>

#define BUFFER_SIZE 100

int read_line (char[]);
/**
 * Quiz 2
 * 입력받은 문자열의 불필요한 공백은 제거 후 그 길이와 함께 출력하기
 * (공백 미포함!)
 * input : (_) == whitespace, 잘 보이기 위함.
 *  ____hel____lo__!__
 *
 * output:
 *  hel_lo_! : 8
 */
int main() {
    char user_input[BUFFER_SIZE];
    printf("$ ");
    int length = read_line(user_input);
    printf("%s : %d\n", user_input, length);


    return 0;
}

int read_line (char user_input[]) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n') {
        if (i < BUFFER_SIZE && !isspace(ch)) {
            user_input[i++] = ch;
        } else if (i > 0 && isspace(ch) && !isspace(user_input[i-1])) {
            user_input[i++] = ch;
        }
    }
    if (i > 0 && isspace(user_input[i-1])) {
        i--;
    }
    user_input[i] = '\0';
    return i;
    //   __abd___12__
    //   abd_12
};

