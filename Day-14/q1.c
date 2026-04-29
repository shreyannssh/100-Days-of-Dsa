#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int mat[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j && mat[i][j] != 1) {
                printf("Not an Identity Matrix\n");
                return 0;
            }
            if (i != j && mat[i][j] != 0) {
                printf("Not an Identity Matrix\n");
                return 0;
            }
        }
    }

    printf("Identity Matrix\n");
    return 0;
}