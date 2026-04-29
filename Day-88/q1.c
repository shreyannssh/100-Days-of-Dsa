#include <stdio.h>
#include <stdlib.h>

// Compare function for sorting
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Check if we can place k cows with minimum distance d
int canPlace(int stalls[], int n, int k, int d) {
    int count = 1;  // first cow
    int lastPos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= d) {
            count++;
            lastPos = stalls[i];
        }

        if (count >= k)
            return 1;
    }

    return 0;
}

// Main
int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int stalls[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &stalls[i]);

    // Sort stalls
    qsort(stalls, n, sizeof(int), cmp);

    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPlace(stalls, n, k, mid)) {
            ans = mid;        // possible
            low = mid + 1;    // try bigger
        } else {
            high = mid - 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}