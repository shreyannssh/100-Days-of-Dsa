#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    int mat[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);
    
    if (m != n) {
        printf("Not a Symmetric Matrix\n");
        return 0;
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != mat[j][i]) {
                printf("Not a Symmetric Matrix\n");
                return 0;
            }
        }
    }
    
    printf("Symmetric Matrix\n");
    return 0;
}