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

// Add edge (undirected)
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// DFS cycle detection
int dfsCycle(struct Graph* graph, int v, int visited[], int parent) {
    visited[v] = 1;

    struct Node* temp = graph->adjList[v];

    while (temp) {
        int adj = temp->vertex;

        if (!visited[adj]) {
            if (dfsCycle(graph, adj, visited, v))
                return 1;
        }
        else if (adj != parent) {
            return 1; // cycle found
        }

        temp = temp->next;
    }

    return 0;
}

// Check cycle for all components
int hasCycle(struct Graph* graph) {
    int visited[graph->V];

    for (int i = 0; i < graph->V; i++)
        visited[i] = 0;

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            if (dfsCycle(graph, i, visited, -1))
                return 1;
        }
    }

    return 0;
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

    if (hasCycle(graph))
        printf("YES");
    else
        printf("NO");

    return 0;
}