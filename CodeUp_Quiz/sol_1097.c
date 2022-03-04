#include <stdio.h>

int main() {

    int w, h;
    scanf("%d %d", &w, &h);

    int board[w][h];

    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            board[i][j] = 0;
        }
    }

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int l, d, x, y;
        scanf("%d %d %d %d", &l, &d, &x, &y);

        for (int j = 0; j < l; ++j) {
            if (d == 1) {
                board[x - 1 + j][y - 1] = 1;
            } else {
                board[x - 1][y - 1 + j] = 1;
            }
        }
    }

    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}

