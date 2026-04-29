#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = 0;

void insert(int val) {
    int i = size - 1;
    while (i >= 0 && pq[i] > val) {
        pq[i + 1] = pq[i];
        i--;
    }
    pq[i + 1] = val;
    size++;
}

int delete() {
    if (size == 0) return -1;
    return pq[--size];
}

int peek() {
    if (size == 0) return -1;
    return pq[size - 1];
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char op[10];
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            int val; scanf("%d", &val);
            insert(val);
        } else if (strcmp(op, "delete") == 0) {
            int val = delete();
            if (val == -1) printf("-1\n");
            else printf("%d\n", val);
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }

    return 0;
}