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
void  enqueue(struct Node *n) { queue[qRear++] = n; }
struct Node* dequeue()        { return queue[qFront++]; }
int   qEmpty()                { return qFront == qRear; }

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node *root = newNode(arr[0]);
    enqueue(root);
    int i = 1;

    while (!qEmpty() && i < n) {
        struct Node *curr = dequeue();

        // Left child
        if (i < n) {
            if (arr[i] != -1) { curr->left = newNode(arr[i]); enqueue(curr->left); }
            i++;
        }
        // Right child
        if (i < n) {
            if (arr[i] != -1) { curr->right = newNode(arr[i]); enqueue(curr->right); }
            i++;
        }
    }
    return root;
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

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node *root = buildTree(arr, n);
    inorder(root);
    printf("\n");
    freeTree(root);

    return 0;
}