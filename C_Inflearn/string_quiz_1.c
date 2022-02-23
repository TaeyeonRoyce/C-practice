#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 20

void read_line_V1(char input[BUFFER_SIZE]);
void read_line_V2(char input[BUFFER_SIZE]);
void read_line_V3(char input[BUFFER_SIZE]);
int read_line_V4(char input[BUFFER_SIZE]);

/**
 * Quiz 1
 * 입력받은 문자열의 길이 출력하기.
 * (공백 모두 포함!)
 * input :
 *  hello  !
 *
 * output:
 *  hello  ! : 8
 */
int main() {
    char user_input[BUFFER_SIZE];

    printf("$ ");
    int length = read_line_V4(user_input);
    printf("%s : %d\n", user_input, length);

    return 0;
}

void read_line_V1(char user_input[]) {
//  scanf는 공백을 기준으로 나누어서 받음
    scanf("%s", user_input);
}

void read_line_V2(char user_input[]) {
//  warning: this program uses gets(), which is unsafe.
//  gets는 한 줄을 모두 입력받기 때문에 deprecated 됨.
    gets(user_input);
}

void read_line_V3(char user_input[]) {
    fgets(user_input, BUFFER_SIZE, stdin);
    user_input[strlen(user_input) - 1] = '\0';
    //fgets는 줄바꿈도 입력받기 때문에 변경이 필요함.

    //fgets는 지정해준 size보다 큰 경우 모두 담지 못함.
}

int read_line_V4(char user_input[]) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n') {
        if (i < BUFFER_SIZE) {
            user_input[i++] = ch;
        }
    }
    user_input[i] = '\0';
    return i;
}

