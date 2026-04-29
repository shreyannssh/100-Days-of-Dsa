#include <stdio.h>
#include <stdlib.h>

// ── Stack (array-based) ──────────────────────────────
#define MAX 100
int stack[MAX];
int top = -1;

void push(int val) { stack[++top] = val; }
int  pop()         { return stack[top--]; }
int  isEmpty()     { return top == -1; }

// ── Queue (linked list) ──────────────────────────────
struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int val) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->next = NULL;
    if (!rear) { front = rear = node; return; }
    rear->next = node;
    rear = node;
}

int dequeue() {
    if (!front) return -1;
    struct Node *tmp = front;
    int val = tmp->data;
    front = front->next;
    if (!front) rear = NULL;
    free(tmp);
    return val;
}

// ── Reverse ──────────────────────────────────────────
void reverseQueue() {
    // Step 1: dequeue all → push to stack
    while (front)
        push(dequeue());

    // Step 2: pop all → enqueue back
    while (!isEmpty())
        enqueue(pop());
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int val; scanf("%d", &val);
        enqueue(val);
    }

    reverseQueue();

    struct Node *curr = front;
    while (curr) {
        if (curr != front) printf(" ");
        printf("%d", curr->data);
        curr = curr->next;
    }
    printf("\n");

    while (front) {
        struct Node *tmp = front;
        front = front->next;
        free(tmp);
    }

    return 0;
}