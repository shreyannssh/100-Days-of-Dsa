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

struct Node* deleteKey(struct Node *head, int key) {
    if (!head) return NULL;

    // Key is at head
    if (head->data == key) {
        struct Node *tmp = head;
        head = head->next;
        free(tmp);
        return head;
    }

    // Search for key in rest of list
    struct Node *prev = head, *curr = head->next;
    while (curr) {
        if (curr->data == key) {
            prev->next = curr->next;
            free(curr);
            return head;
        }
        prev = curr;
        curr = curr->next;
    }

    return head;  // key not found, list unchanged
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

    int key; scanf("%d", &key);
    head = deleteKey(head, key);

    struct Node *curr = head;
    while (curr) {
        if (curr != head) printf(" ");
        printf("%d", curr->data);
        curr = curr->next;
    }
    printf("\n");

    curr = head;
    while (curr) {
        struct Node *tmp = curr;
        curr = curr->next;
        free(tmp);
    }

    return 0;
}