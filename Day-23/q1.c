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

struct Node* buildList(int n) {
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int val; scanf("%d", &val);
        struct Node *node = newNode(val);
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }
    return head;
}

struct Node* mergeSorted(struct Node *a, struct Node *b) {
    struct Node dummy;
    struct Node *tail = &dummy;
    dummy.next = NULL;

    while (a && b) {
        if (a->data <= b->data) { tail->next = a; a = a->next; }
        else                    { tail->next = b; b = b->next; }
        tail = tail->next;
    }
    tail->next = a ? a : b;  // attach remaining nodes
    return dummy.next;
}

int main() {
    int n, m;
    scanf("%d", &n);  struct Node *l1 = buildList(n);
    scanf("%d", &m);  struct Node *l2 = buildList(m);

    struct Node *merged = mergeSorted(l1, l2);

    struct Node *curr = merged;
    while (curr) {
        if (curr != merged) printf(" ");
        printf("%d", curr->data);
        curr = curr->next;
    }
    printf("\n");

    curr = merged;
    while (curr) {
        struct Node *tmp = curr;
        curr = curr->next;
        free(tmp);
    }

    return 0;
}