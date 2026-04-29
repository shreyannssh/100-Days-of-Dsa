#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1) return;
    stack[++top] = val;
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int val; scanf("%d", &val);
        push(val);
    }

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++)
        pop();

    for (int i = top; i >= 0; i--) {
        if (i != top) printf(" ");
        printf("%d", stack[i]);
    }
    printf("\n");

    return 0;
}