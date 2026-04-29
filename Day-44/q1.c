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
        if (i < n) { if (arr[i]   != -1) { curr->left  = newNode(arr[i]);   enqueue(curr->left);  } i++; }
        if (i < n) { if (arr[i] != -1)   { curr->right = newNode(arr[i]);   enqueue(curr->right); } i++; }
    }
    return root;
}

int first;  // flag to avoid trailing space

void inorder(struct Node *root) {
    if (!root) return;
    inorder(root->left);
    if (!first) printf(" "); printf("%d", root->data); first = 0;
    inorder(root->right);
}

void preorder(struct Node *root) {
    if (!root) return;
    if (!first) printf(" "); printf("%d", root->data); first = 0;
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node *root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    if (!first) printf(" "); printf("%d", root->data); first = 0;
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

    first = 1; inorder(root);   printf("\n");
    first = 1; preorder(root);  printf("\n");
    first = 1; postorder(root); printf("\n");

    freeTree(root);
    return 0;
}