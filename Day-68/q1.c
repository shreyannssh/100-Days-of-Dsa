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

// Queue
struct Queue {
    int arr[1000];
    int front, rear;
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

// Add directed edge
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

// Queue functions
void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, int val) {
    if (q->rear == 999) return;
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = val;
}

int dequeue(struct Queue* q) {
    int val = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return val;
}

// Kahn's Algorithm
void topologicalSort(struct Graph* graph) {
    int indegree[graph->V];

    // Initialize indegree
    for (int i = 0; i < graph->V; i++)
        indegree[i] = 0;

    // Calculate indegree
    for (int i = 0; i < graph->V; i++) {
        struct Node* temp = graph->adjList[i];
        while (temp) {
            indegree[temp->vertex]++;
            temp = temp->next;
        }
    }

    struct Queue q;
    initQueue(&q);

    // Enqueue nodes with indegree 0
    for (int i = 0; i < graph->V; i++) {
        if (indegree[i] == 0)
            enqueue(&q, i);
    }

    int count = 0;

    while (!isEmpty(&q)) {
        int curr = dequeue(&q);
        printf("%d ", curr);
        count++;

        struct Node* temp = graph->adjList[curr];
        while (temp) {
            indegree[temp->vertex]--;

            if (indegree[temp->vertex] == 0)
                enqueue(&q, temp->vertex);

            temp = temp->next;
        }
    }

    // Cycle check
    if (count != graph->V) {
        printf("\nCycle exists! Topological sort not possible.");
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