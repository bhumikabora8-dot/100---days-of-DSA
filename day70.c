#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

struct Edge {
    int u, v, w;
};

void bellmanFord(int n, int m, struct Edge edges[], int src) {
    int dist[n];

    // Step 1: Initialize distances
    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[src] = 0;

    // Step 2: Relax edges (n-1) times
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 3: Detect negative cycle
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            return;
        }
    }

    // Step 4: Print shortest distances
    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("Vertex %d: INF\n", i);
        else
            printf("Vertex %d: %d\n", i, dist[i]);
    }
}