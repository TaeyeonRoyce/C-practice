#include <stdio.h>

int main() {

    char user_input;

    while(1) {
        scanf("%c", &user_input);
        printf("%c", user_input);
        if (user_input == 'q') {
            return 0;
        }
    }
    return 0;
}
