/*Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to 
the right to make space.*/

#include <stdio.h>

int main() {
    int n, pos, x;
    
    // Read number of elements
    scanf("%d", &n);
    
    int arr[n + 1];   // Extra space for insertion
    
    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Read position and element
    scanf("%d", &pos);
    scanf("%d", &x);
    
    // Shift elements to the right
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    
    // Insert element
    arr[pos - 1] = x;
    
    // Print updated array
    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}