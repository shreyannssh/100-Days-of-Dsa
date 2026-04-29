#include <stdio.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    int mat[r][c];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &mat[i][j]);

    int top = 0, bottom = r - 1, left = 0, right = c - 1;
    int first = 1;

    while (top <= bottom && left <= right) {
        // Left to right along top row
        for (int j = left; j <= right; j++) {
            if (!first) printf(" ");
            printf("%d", mat[top][j]);
            first = 0;
        }
        top++;

        // Top to bottom along right column
        for (int i = top; i <= bottom; i++) {
            printf(" %d", mat[i][right]);
        }
        right--;

        // Right to left along bottom row (if row still exists)
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                printf(" %d", mat[bottom][j]);
            }
            bottom--;
        }

        // Bottom to top along left column (if column still exists)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf(" %d", mat[i][left]);
            }
            left++;
        }
    }

    printf("\n");
    return 0;
}