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

struct Node* insert(struct Node *root, int val) {
    if (!root) return newNode(val);
    if (val < root->data)      root->left  = insert(root->left,  val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

struct Node* lca(struct Node *root, int a, int b) {
    if (!root) return NULL;

    // Both nodes are smaller → LCA is in left subtree
    if (a < root->data && b < root->data)
        return lca(root->left, a, b);

    // Both nodes are larger → LCA is in right subtree
    if (a > root->data && b > root->data)
        return lca(root->right, a, b);

    // Nodes are on different sides (or one equals root) → root is LCA
    return root;
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

    struct Node *root = NULL;
    for (int i = 0; i < n; i++) {
        int val; scanf("%d", &val);
        root = insert(root, val);
    }

    int a, b;
    scanf("%d %d", &a, &b);

    struct Node *result = lca(root, a, b);
    printf("%d\n", result->data);

    freeTree(root);
    return 0;
}