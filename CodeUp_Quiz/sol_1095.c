#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int board[19][19] = {0};

    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        board[x - 1][y - 1] = 1;
    }

    for (int i = 0; i < 19; ++i) {
        for (int j = 0; j < 19; ++j) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }


    return 0;
}

