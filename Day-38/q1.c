#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200

int deque[MAX];
int front = MAX / 2;  // start in the middle to allow growth both ways
int rear  = MAX / 2 - 1;
int sz = 0;

void push_front(int val) {
    if (sz == MAX) { printf("Deque Overflow\n"); return; }
    deque[--front] = val;
    sz++;
}

void push_back(int val) {
    if (sz == MAX) { printf("Deque Overflow\n"); return; }
    deque[++rear] = val;
    sz++;
}

int pop_front() {
    if (sz == 0) { printf("Deque Underflow\n"); return -1; }
    int val = deque[front++];
    sz--;
    return val;
}

int pop_back() {
    if (sz == 0) { printf("Deque Underflow\n"); return -1; }
    int val = deque[rear--];
    sz--;
    return val;
}

int get_front() { return sz == 0 ? -1 : deque[front]; }
int get_back()  { return sz == 0 ? -1 : deque[rear];  }
int empty()     { return sz == 0; }
int size()      { return sz; }

void display() {
    if (sz == 0) { printf("Deque Empty\n"); return; }
    for (int i = front; i <= rear; i++) {
        if (i != front) printf(" ");
        printf("%d", deque[i]);
    }
    printf("\n");
}

void reverse_deque() {
    int l = front, r = rear;
    while (l < r) {
        int tmp = deque[l]; deque[l] = deque[r]; deque[r] = tmp;
        l++; r--;
    }
}

void sort_deque() {
    // Bubble sort on active range
    for (int i = front; i <= rear; i++)
        for (int j = front; j < rear - (i - front); j++)
            if (deque[j] > deque[j+1]) {
                int tmp = deque[j]; deque[j] = deque[j+1]; deque[j+1] = tmp;
            }
}

int main() {
    char op[20];

    while (scanf("%s", op) == 1) {
        if      (strcmp(op, "push_front") == 0) { int v; scanf("%d",&v); push_front(v); }
        else if (strcmp(op, "push_back")  == 0) { int v; scanf("%d",&v); push_back(v);  }
        else if (strcmp(op, "pop_front")  == 0) { int v = pop_front();  if (v!=-1) printf("%d\n",v); }
        else if (strcmp(op, "pop_back")   == 0) { int v = pop_back();   if (v!=-1) printf("%d\n",v); }
        else if (strcmp(op, "front")      == 0) { printf("%d\n", get_front()); }
        else if (strcmp(op, "back")       == 0) { printf("%d\n", get_back());  }
        else if (strcmp(op, "empty")      == 0) { printf("%s\n", empty() ? "true" : "false"); }
        else if (strcmp(op, "size")       == 0) { printf("%d\n", size()); }
        else if (strcmp(op, "reverse")    == 0) { reverse_deque(); }
        else if (strcmp(op, "sort")       == 0) { sort_deque();    }
        else if (strcmp(op, "display")    == 0) { display();       }
    }

    return 0;
}