//Implement linear search to find key k in an array. Count and display the number of comparisons performed.

#include <stdio.h>

int main() {
    int n, k;
    
    // Input size
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input key
    scanf("%d", &k);

    int comparisons = 0;
    int index = -1;

    // Linear Search
    for(int i = 0; i < n; i++) {
        comparisons++;
        if(arr[i] == k) {
            index = i;
            break;
        }
    }

    // Output
    if(index != -1)
        printf("Found at index %d\n", index);
    else
        printf("Not Found\n");

    printf("Comparisons = %d", comparisons);

    return 0;
}