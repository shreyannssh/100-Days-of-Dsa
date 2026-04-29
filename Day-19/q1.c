#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), cmp);

    int l = 0, r = n - 1;
    int bestL = l, bestR = r;
    int bestSum = abs(arr[l] + arr[r]);

    while (l < r) {
        int sum = arr[l] + arr[r];
        if (abs(sum) < bestSum) {
            bestSum = abs(sum);
            bestL = l;
            bestR = r;
        }
        if (sum < 0)      l++;
        else if (sum > 0) r--;
        else              break;  // sum == 0, can't get closer
    }

    printf("%d %d\n", arr[bestL], arr[bestR]);
    return 0;
}