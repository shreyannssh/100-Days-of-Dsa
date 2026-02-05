//Given an array of n integers, reverse the array in-place using two-pointer approach.

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);      // Read size of array

    int arr[n];
    
    // Read array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Two-pointer approach
    int left = 0;
    int right = n - 1;

    while(left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }

    // Print reversed array
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}