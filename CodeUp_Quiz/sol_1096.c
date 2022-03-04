#include <stdio.h>

int main() {


    int board[19][19] = {0};

    for (int i = 0; i < 19; ++i) {
        for (int j = 0; j < 19; ++j) {
            scanf("%d", &board[i][j]);
        }
    }

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        for (int j = 0; j < 19; ++j) {
            if (board[x-1][j] == 1) {
                board[x-1][j] = 0;
            } else {
                board[x-1][j] = 1;
            }
        }

        for (int j = 0; j < 19; ++j) {
            if (board[j][y-1] == 1) {
                board[j][y-1] = 0;
            } else {
                board[j][y-1] = 1;
            }
        }
    }

    for (int i = 0; i < 19; ++i) {
        for (int j = 0; j < 19; ++j) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }


    return 0;
}

