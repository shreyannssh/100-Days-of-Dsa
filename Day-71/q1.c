#include <stdio.h>
#include <string.h>

#define EMPTY -1

int table[100];

// Initialize hash table
void init(int m) {
    for (int i = 0; i < m; i++)
        table[i] = EMPTY;
}

// Insert using quadratic probing
void insert(int key, int m) {
    int i = 0;
    int index;

    while (i < m) {
        index = (key % m + i * i) % m;

        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
        i++;
    }

    printf("Hash table full\n");
}

// Search using quadratic probing
int search(int key, int m) {
    int i = 0;
    int index;

    while (i < m) {
        index = (key % m + i * i) % m;

        if (table[index] == EMPTY)
            return 0;

        if (table[index] == key)
            return 1;

        i++;
    }

    return 0;
}

// Main
int main() {
    int m, q;
    scanf("%d", &m);   // table size
    scanf("%d", &q);   // number of operations

    init(m);

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key, m);
        }
        else if (strcmp(op, "SEARCH") == 0) {
            if (search(key, m))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}