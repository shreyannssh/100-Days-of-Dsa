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

// Queue for both construction and traversal
struct Node* queue[100];
int qFront = 0, qRear = 0;
void         enqueue(struct Node *n) { queue[qRear++] = n; }
struct Node* dequeue()               { return queue[qFront++]; }
int          qEmpty()                { return qFront == qRear; }
int          qSize()                 { return qRear - qFront; }

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

void levelOrder(struct Node *root) {
    if (!root) return;

    // Reset queue
    qFront = qRear = 0;
    enqueue(root);

    while (!qEmpty()) {
        int levelSize = qSize();  // number of nodes at current level

        for (int i = 0; i < levelSize; i++) {
            struct Node *curr = dequeue();
            if (i != 0) printf(" ");
            printf("%d", curr->data);

            if (curr->left)  enqueue(curr->left);
            if (curr->right) enqueue(curr->right);
        }
        printf("\n");  // newline after each level
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
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node *root = buildTree(arr, n);
    levelOrder(root);
    freeTree(root);

    return 0;
}