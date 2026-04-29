#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = 0;

void enqueue(int val) {
    if (rear == MAX) { printf("Queue Overflow\n"); return; }
    queue[rear++] = val;
}

int dequeue() {
    if (front == rear) { printf("Queue Underflow\n"); return -1; }
    return queue[front++];
}

void display() {
    if (front == rear) { printf("Queue Empty\n"); return; }
    for (int i = front; i < rear; i++) {
        if (i != front) printf(" ");
        printf("%d", queue[i]);
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

    display();

    return 0;
}