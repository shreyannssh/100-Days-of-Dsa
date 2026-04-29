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
        int val;
        scanf("%d", &val);
        struct Node *node = newNode(val);
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }

    struct Node *curr = head;
    while (curr) {
        if (curr != head) printf(" ");
        printf("%d", curr->data);
        curr = curr->next;
    }
    printf("\n");

    // Free memory
    curr = head;
    while (curr) {
        struct Node *tmp = curr;
        curr = curr->next;
        free(tmp);
    }

    return 0;
}