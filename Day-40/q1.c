#include <stdio.h>

void swap(int arr[], int i, int j) {
    int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
}

void heapifyDown(int arr[], int n, int i) {
    while (1) {
        int left    = 2 * i + 1;
        int right   = 2 * i + 2;
        int largest = i;

        if (left  < n && arr[left]  > arr[largest]) largest = left;
        if (right < n && arr[right] > arr[largest]) largest = right;

        if (largest != i) { swap(arr, i, largest); i = largest; }
        else break;
    }
}

void buildMaxHeap(int arr[], int n) {
    // Start from last non-leaf node and heapify down each
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyDown(arr, n, i);
}

void heapSort(int arr[], int n) {
    buildMaxHeap(arr, n);

    for (int i = n - 1; i > 0; i--) {
        swap(arr, 0, i);       // move max to end
        heapifyDown(arr, i, 0); // restore heap on reduced array
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    heapSort(arr, n);

    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");

    return 0;
}