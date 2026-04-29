#include <stdio.h>
#include <string.h>

#define MAX 100

int heap[MAX];
int sz = 0;

void swap(int i, int j) {
    int tmp = heap[i]; heap[i] = heap[j]; heap[j] = tmp;
}

void heapifyUp(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] > heap[i]) { swap(parent, i); i = parent; }
        else break;
    }
}

void heapifyDown(int i) {
    while (1) {
        int left  = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left  < sz && heap[left]  < heap[smallest]) smallest = left;
        if (right < sz && heap[right] < heap[smallest]) smallest = right;

        if (smallest != i) { swap(i, smallest); i = smallest; }
        else break;
    }
}

void insert(int val) {
    heap[sz++] = val;
    heapifyUp(sz - 1);
}

int extractMin() {
    if (sz == 0) return -1;
    int min = heap[0];
    heap[0] = heap[--sz];
    heapifyDown(0);
    return min;
}

int peek() {
    return sz == 0 ? -1 : heap[0];
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char op[20];
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            int val; scanf("%d", &val);
            insert(val);
        } else if (strcmp(op, "extractMin") == 0) {
            printf("%d\n", extractMin());
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }

    return 0;
}