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

int countLeaves(struct Node *root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;  // leaf node
    return countLeaves(root->left) + countLeaves(root->right);
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
    printf("%d\n", countLeaves(root));
    freeTree(root);
    return 0;
}