#include <stdio.h>

int main() {
    int n, m;
    scanf("%d", &n);   // number of vertices
    scanf("%d", &m);   // number of edges

    int adj[n][n];

    // Initialize matrix with 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    int u, v;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;        // directed
        adj[v][u] = 1;        // comment this line for directed graph
    }

    // Print adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}