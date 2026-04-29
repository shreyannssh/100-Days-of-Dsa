#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

struct Node *top = NULL;

void push(int val) {
    struct Node *node = newNode(val);
    node->next = top;
    top = node;
}

int pop() {
    struct Node *tmp = top;
    int val = tmp->data;
    top = top->next;
    free(tmp);
    return val;
}

int applyOp(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

int main() {
    char token[20];

    while (scanf("%s", token) == 1) {
        if (strlen(token) == 1 &&
            (token[0]=='+' || token[0]=='-' || token[0]=='*' || token[0]=='/')) {
            int b = pop();
            int a = pop();
            push(applyOp(a, b, token[0]));
        } else {
            push(atoi(token));
        }
    }

    printf("%d\n", pop());

    return 0;
}