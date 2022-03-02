#include <stdio.h>

int main() {

    int user_input;
    int sum = 0;
    int count = 0;

    scanf("%d", &user_input);

    while (sum < user_input) {
        sum += count;
        count++;
    }
    printf("%d", count);
    return 0;
}
