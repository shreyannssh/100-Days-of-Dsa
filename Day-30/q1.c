#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coef;
    int exp;
    struct Node *next;
};

struct Node* newNode(int coef, int exp) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->coef = coef;
    node->exp  = exp;
    node->next = NULL;
    return node;
}

void printTerm(int coef, int exp, int first) {
    if (!first) printf(" + ");

    if (exp == 0)       printf("%d", coef);
    else if (exp == 1)  printf("%dx", coef);
    else                printf("%dx^%d", coef, exp);
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int c, e; scanf("%d %d", &c, &e);
        struct Node *node = newNode(c, e);
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }

    struct Node *curr = head;
    int first = 1;
    while (curr) {
        printTerm(curr->coef, curr->exp, first);
        first = 0;
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