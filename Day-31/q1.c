#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1) { printf("Stack Overflow\n"); return; }
    stack[++top] = val;
}

int pop() {
    if (top == -1) { printf("Stack Underflow\n"); return -1; }
    return stack[top--];
}

void display() {
    if (top == -1) { printf("Stack Empty\n"); return; }
    for (int i = top; i >= 0; i--) {
        if (i != top) printf(" ");
        printf("%d", stack[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int op; scanf("%d", &op);
        if (op == 1) {
            int val; scanf("%d", &val);
            push(val);
        } else if (op == 2) {
            int val = pop();
            if (val != -1) printf("%d\n", val);
        } else if (op == 3) {
            display();
        }
    }

    return 0;
}