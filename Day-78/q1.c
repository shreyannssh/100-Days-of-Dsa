#include <stdio.h>
#include <limits.h>

#define MAX 100

// Find minimum key vertex not yet included
int minKey(int key[], int visited[], int n) {
    int min = INT_MAX, min_index;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

// Prim's Algorithm
int primMST(int graph[MAX][MAX], int n) {
    int key[n];
    int visited[n];

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[0] = 0;  // start from node 0

    int totalWeight = 0;

    for (int count = 0; count < n; count++) {
        int u = minKey(key, visited, n);
        visited[u] = 1;

        totalWeight += key[u];

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    return totalWeight;
}

// Main
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX] = {0};

    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);

        // Convert 1-based → 0-based
        u--; v--;

        graph[u][v] = w;
        graph[v][u] = w;
    }

    int result = primMST(graph, n);
    printf("%d\n", result);

    return 0;
}