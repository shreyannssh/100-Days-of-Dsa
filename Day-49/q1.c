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
    if (val < root->data)       root->left  = insert(root->left,  val);
    else if (val > root->data)  root->right = insert(root->right, val);
    return root;  // val == root->data: duplicate, ignore
}

void inorder(struct Node *root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
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

    inorder(root);
    printf("\n");
    freeTree(root);
    return 0;
}