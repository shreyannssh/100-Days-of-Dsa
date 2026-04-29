#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data  = data;
    node->left  = NULL;
    node->right = NULL;
    return node;
}

// Queue for level-order construction
struct Node* queue[100];
int qFront = 0, qRear = 0;
void         enqueue(struct Node *n) { queue[qRear++] = n; }
struct Node* dequeue()               { return queue[qFront++]; }
int          qEmpty()                { return qFront == qRear; }

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node *root = newNode(arr[0]);
    enqueue(root);
    int i = 1;
    while (!qEmpty() && i < n) {
        struct Node *curr = dequeue();
        if (i < n) { if (arr[i] != -1) { curr->left  = newNode(arr[i]); enqueue(curr->left);  } i++; }
        if (i < n) { if (arr[i] != -1) { curr->right = newNode(arr[i]); enqueue(curr->right); } i++; }
    }
    return root;
}

// Store (node, hd) pairs for BFS traversal
struct Pair { struct Node *node; int hd; };
struct Pair bfsQueue[100];
int bFront = 0, bRear = 0;

// Column buckets: hd range [-n, +n]
#define OFFSET 50
#define BUCKETS 101
int cols[BUCKETS][100];   // cols[hd+OFFSET] = list of node values
int colSize[BUCKETS];     // number of nodes in each column

void verticalOrder(struct Node *root) {
    if (!root) return;

    for (int i = 0; i < BUCKETS; i++) colSize[i] = 0;

    bfsQueue[bRear++] = (struct Pair){root, 0};

    while (bFront < bRear) {
        struct Pair p = bfsQueue[bFront++];
        struct Node *curr = p.node;
        int hd = p.hd;

        cols[hd + OFFSET][colSize[hd + OFFSET]++] = curr->data;

        if (curr->left)  bfsQueue[bRear++] = (struct Pair){curr->left,  hd - 1};
        if (curr->right) bfsQueue[bRear++] = (struct Pair){curr->right, hd + 1};
    }

    // Print columns left to right
    for (int i = 0; i < BUCKETS; i++) {
        if (colSize[i] == 0) continue;
        for (int j = 0; j < colSize[i]; j++) {
            if (j != 0) printf(" ");
            printf("%d", cols[i][j]);
        }
        printf("\n");
    }
}

void freeTree(struct Node *root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node *root = buildTree(arr, n);
    verticalOrder(root);
    freeTree(root);
    return 0;
}