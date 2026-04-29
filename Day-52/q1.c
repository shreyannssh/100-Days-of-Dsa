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

struct Node* lca(struct Node *root, int a, int b) {
    if (!root) return NULL;
    if (root->data == a || root->data == b) return root;  // found one target

    struct Node *leftLCA  = lca(root->left,  a, b);
    struct Node *rightLCA = lca(root->right, a, b);

    if (leftLCA && rightLCA) return root;   // a and b on opposite sides → root is LCA
    return leftLCA ? leftLCA : rightLCA;    // both in same subtree → return non-NULL side
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

    int a, b;
    scanf("%d %d", &a, &b);

    struct Node *result = lca(root, a, b);
    printf("%d\n", result->data);

    freeTree(root);
    return 0;
}