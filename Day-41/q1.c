#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    if (!front) rear = NULL;  // queue became empty
    free(tmp);
    return val;
}

void display() {
    if (!front) { printf("Queue Empty\n"); return; }
    struct Node *curr = front;
    while (curr) {
        if (curr != front) printf(" ");
        printf("%d", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char op[10];
        scanf("%s", op);

        if (strcmp(op, "enqueue") == 0) {
            int val; scanf("%d", &val);
            enqueue(val);
        } else if (strcmp(op, "dequeue") == 0) {
            printf("%d\n", dequeue());
        } else if (strcmp(op, "display") == 0) {
            display();
        }
    }

    // Free remaining nodes
    while (front) {
        struct Node *tmp = front;
        front = front->next;
        free(tmp);
    }

    return 0;
}