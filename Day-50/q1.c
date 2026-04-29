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

int search(struct Node *root, int key) {
    if (!root) return 0;                    // not found
    if (key == root->data) return 1;        // found
    if (key < root->data) return search(root->left,  key);
    else                  return search(root->right, key);
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

    int key;
    scanf("%d", &key);

    printf("%s\n", search(root, key) ? "Found" : "Not Found");

    freeTree(root);
    return 0;
}