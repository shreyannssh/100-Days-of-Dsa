#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int V;
    struct Node** adjList;
};

// Stack
struct Stack {
    int arr[1000];
    int top;
};

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    graph->adjList = (struct Node**)malloc(V * sizeof(struct Node*));

    for (int i = 0; i < V; i++)
        graph->adjList[i] = NULL;

    return graph;
}

// Add edge (directed)
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

// Stack functions
void initStack(struct Stack* s) {
    s->top = -1;
}

void push(struct Stack* s, int value) {
    s->arr[++s->top] = value;
}

int pop(struct Stack* s) {
    return s->arr[s->top--];
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// DFS helper
void topoDFS(struct Graph* graph, int v, int visited[], struct Stack* s) {
    visited[v] = 1;

    struct Node* temp = graph->adjList[v];

    while (temp) {
        if (!visited[temp->vertex]) {
            topoDFS(graph, temp->vertex, visited, s);
        }
        temp = temp->next;
    }

    push(s, v);  // push after visiting children
}

// Topological Sort
void topologicalSort(struct Graph* graph) {
    int visited[graph->V];
    for (int i = 0; i < graph->V; i++)
        visited[i] = 0;

    struct Stack s;
    initStack(&s);

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            topoDFS(graph, i, visited, &s);
        }
    }

    while (!isEmpty(&s)) {
        printf("%d ", pop(&s));
    }
}

// Main
int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    struct Graph* graph = createGraph(n);

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    topologicalSort(graph);

    return 0;
}