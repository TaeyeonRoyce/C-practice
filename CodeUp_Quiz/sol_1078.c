#include <stdio.h>

int main() {

    int user_input;
    scanf("%d", &user_input);

    int sum = 0;
    for (int i = 0; i <= user_input; i += 2) {
        sum += i;
    }

    printf("%d", sum);
    return 0;
}
