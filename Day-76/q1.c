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

// DFS
void DFS(struct Graph* graph, int v, int visited[]) {
    visited[v] = 1;

    struct Node* temp = graph->adjList[v];
    while (temp) {
        if (!visited[temp->vertex]) {
            DFS(graph, temp->vertex, visited);
        }
        temp = temp->next;
    }
}

// Count components
int countComponents(struct Graph* graph) {
    int visited[graph->V];

    for (int i = 0; i < graph->V; i++)
        visited[i] = 0;

    int count = 0;

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            DFS(graph, i, visited);
            count++;
        }
    }

    return count;
}

// Main
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Graph* graph = createGraph(n);

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        
        // If input is 1-based → convert to 0-based
        u--; v--;
        
        addEdge(graph, u, v);
    }

    int result = countComponents(graph);
    printf("%d\n", result);

    return 0;
}