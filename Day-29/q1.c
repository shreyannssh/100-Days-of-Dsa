#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* newNode(int data) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int val; scanf("%d", &val);
        struct Node *node = newNode(val);
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }

    int k; scanf("%d", &k);
    k = k % n;

    if (k == 0) {
        // No rotation needed
        struct Node *curr = head;
        while (curr) {
            if (curr != head) printf(" ");
            printf("%d", curr->data);
            curr = curr->next;
        }
        printf("\n");
        return 0;
    }

    // Step 1: Form circular list
    tail->next = head;

    // Step 2: Find new tail — (n-k)th node from original head
    struct Node *newTail = head;
    for (int i = 1; i < n - k; i++)
        newTail = newTail->next;

    // Step 3: New head is one step ahead of new tail
    struct Node *newHead = newTail->next;
    newTail->next = NULL;  // break the circle

    // Traverse and print
    struct Node *curr = newHead;
    while (curr) {
        if (curr != newHead) printf(" ");
        printf("%d", curr->data);
        curr = curr->next;
    }
    printf("\n");

    // Free memory
    curr = newHead;
    while (curr) {
        struct Node *tmp = curr;
        curr = curr->next;
        free(tmp);
    }

    return 0;
}