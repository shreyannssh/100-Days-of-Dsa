#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1, size = 0;

void enqueue(int val) {
    if (size == MAX) { printf("Queue Overflow\n"); return; }
    rear = (rear + 1) % MAX;
    queue[rear] = val;
    if (front == -1) front = 0;
    size++;
}

int dequeue() {
    if (size == 0) { printf("Queue Underflow\n"); return -1; }
    int val = queue[front];
    front = (front + 1) % MAX;
    size--;
    return val;
}

void display() {
    if (size == 0) { printf("Queue Empty\n"); return; }
    for (int i = 0; i < size; i++) {
        if (i != 0) printf(" ");
        printf("%d", queue[(front + i) % MAX]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int val; scanf("%d", &val);
        enqueue(val);
    }

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
        dequeue();

    display();

    return 0;
}