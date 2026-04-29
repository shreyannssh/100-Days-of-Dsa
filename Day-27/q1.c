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

int listLength(struct Node *head) {
    int len = 0;
    while (head) { len++; head = head->next; }
    return len;
}

int main() {
    int n, m;
    scanf("%d", &n);

    struct Node *h1 = NULL, *t1 = NULL;
    for (int i = 0; i < n; i++) {
        int val; scanf("%d", &val);
        struct Node *node = newNode(val);
        if (!h1) h1 = t1 = node;
        else { t1->next = node; t1 = node; }
    }

    scanf("%d", &m);

    struct Node *h2 = NULL, *t2 = NULL;
    for (int i = 0; i < m; i++) {
        int val; scanf("%d", &val);
        struct Node *node = newNode(val);
        if (!h2) h2 = t2 = node;
        else { t2->next = node; t2 = node; }
    }

    // Find intersection by value (since lists are separate in memory)
    int len1 = listLength(h1);
    int len2 = listLength(h2);

    struct Node *p1 = h1, *p2 = h2;

    // Advance pointer of longer list
    while (len1 > len2) { p1 = p1->next; len1--; }
    while (len2 > len1) { p2 = p2->next; len2--; }

    // Traverse both until matching value found
    while (p1 && p2) {
        if (p1->data == p2->data) {
            printf("%d\n", p1->data);
            goto cleanup;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    printf("No Intersection\n");

cleanup:
    // Free both lists
    struct Node *curr = h1;
    while (curr) { struct Node *tmp = curr; curr = curr->next; free(tmp); }
    curr = h2;
    while (curr) { struct Node *tmp = curr; curr = curr->next; free(tmp); }

    return 0;
}