#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int mat[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    int sum = 0;
    int limit = m < n ? m : n;

    for (int i = 0; i < limit; i++)
        sum += mat[i][i];

    printf("%d\n", sum);
    return 0;
}