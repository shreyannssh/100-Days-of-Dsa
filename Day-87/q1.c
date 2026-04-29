#include <stdio.h>

// Simple sorting (Insertion Sort for safety)
void sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Binary Search
int binarySearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // not found
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int x;
    scanf("%d", &x);   // element to search

    sort(arr, n);

    // Print sorted array
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    int result = binarySearch(arr, n, x);

    if (result != -1)
        printf("Found at index %d\n", result);
    else
        printf("Not Found\n");

    return 0;
}