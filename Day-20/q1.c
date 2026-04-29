#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // prefix[i] stores count of how many times prefix sum i has occurred
    // offset n handles negative prefix sums (range: -n to +n)
    int size = 2 * n + 1;
    int freq[size];
    for (int i = 0; i < size; i++) freq[i] = 0;

    int count = 0, prefSum = 0;
    freq[prefSum + n] = 1;  // prefix sum of 0 seen once (empty subarray)

    for (int i = 0; i < n; i++) {
        prefSum += arr[i];
        count += freq[prefSum + n];
        freq[prefSum + n]++;
    }

    printf("%d\n", count);
    return 0;
}