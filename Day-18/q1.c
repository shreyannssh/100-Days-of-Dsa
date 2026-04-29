#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int k;
    scanf("%d", &k);
    k = k % n;

    // Reverse entire array
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
    }
    // Reverse first k elements
    for (int i = 0, j = k - 1; i < j; i++, j--) {
        int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
    }
    // Reverse remaining n-k elements
    for (int i = k, j = n - 1; i < j; i++, j--) {
        int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
    }

    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
    return 0;
}