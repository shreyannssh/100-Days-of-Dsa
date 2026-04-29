#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c)  { stack[++top] = c; }
char pop()         { return stack[top--]; }
char peek()        { return stack[top]; }
int  isEmpty()     { return top == -1; }

int precedence(char c) {
    if (c == '*' || c == '/' || c == '%') return 2;
    if (c == '+' || c == '-')             return 1;
    return 0;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

int main() {
    char expr[MAX];
    scanf("%s", expr);

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];

        if (c == '(') {
            push(c);
        } else if (c == ')') {
            // Pop until matching '('
            while (!isEmpty() && peek() != '(')
                printf("%c", pop());
            pop();  // discard '('
        } else if (isOperator(c)) {
            // Pop operators of >= precedence before pushing
            while (!isEmpty() && peek() != '(' && precedence(peek()) >= precedence(c))
                printf("%c", pop());
            push(c);
        } else {
            // Operand → print directly
            printf("%c", c);
        }
    }

    // Pop remaining operators
    while (!isEmpty())
        printf("%c", pop());

    printf("\n");
    return 0;
}