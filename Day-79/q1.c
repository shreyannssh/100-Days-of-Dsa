#include <stdio.h>
#include <limits.h>

#define MAX 100

// Find vertex with minimum distance
int minDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, min_index;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// Dijkstra Algorithm
void dijkstra(int graph[MAX][MAX], int n, int src) {
    int dist[n];
    int visited[n];

    // Initialize
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] &&
                graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print result
    for (int i = 0; i < n; i++) {
        printf("%d ", dist[i]);
    }
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
        graph[v][u] = w; // remove if directed
    }

    int src;
    scanf("%d", &src);
    src--;  // convert to 0-based

    dijkstra(graph, n, src);

    return 0;
}