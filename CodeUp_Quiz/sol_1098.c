#include <stdio.h>

int main() {
    int board[10][10] = {0};

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            int a;
            scanf("%d", &a);
            board[i][j] = a;
        }
    }

    int x = 1;
    int y = 1;

    while (1) {
        if (board[x][y] == 2) {
            board[x][y] = 9;
            break;
        }
        board[x][y] = 9;
       if (board[x][y + 1] != 1) {
            y += 1;
       } else if (board[x + 1][y] != 1) {
            x += 1;
       } else {
           break;
       }
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}

