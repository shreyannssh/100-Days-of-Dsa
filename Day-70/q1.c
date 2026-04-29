#include <stdio.h>
#include <limits.h>

#define MAX 100

// Edge structure
struct Edge {
    int u, v, w;
};

void bellmanFord(struct Edge edges[], int n, int m, int src) {
    int dist[MAX];

    // Initialize distances
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    // Relax edges V-1 times
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycle
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            return;
        }
    }

    // Print shortest distances
    for (int i = 0; i < n; i++) {
        printf("Distance from %d to %d = %d\n", src, i, dist[i]);
    }
}

// Main
int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    struct Edge edges[MAX];

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int src;
    scanf("%d", &src);

    bellmanFord(edges, n, m, src);

    return 0;
}