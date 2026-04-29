#include <stdio.h>

#define MAX 1000

int main() {
    int arr[MAX], n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int sum = 0, maxLen = 0;

    // Hash map (simple array for demo)
    int hash[10000];
    for (int i = 0; i < 10000; i++)
        hash[i] = -1;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) {
            maxLen = i + 1;
        }

        if (hash[sum + 5000] != -1) {
            int len = i - hash[sum + 5000];
            if (len > maxLen)
                maxLen = len;
        } else {
            hash[sum + 5000] = i;
        }
    }

    printf("%d\n", maxLen);

    return 0;
}