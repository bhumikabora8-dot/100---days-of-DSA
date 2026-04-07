#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 2000

// DFS function
bool dfs(int node, int adj[MAX][MAX], int visited[], int recStack[], int V) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {
            if (!visited[i] && dfs(i, adj, visited, recStack, V))
                return true;
            else if (recStack[i])
                return true;
        }
    }

    recStack[node] = 0; // remove from recursion stack
    return false;
}

// Function to detect cycle
bool hasCycle(int V, int adj[MAX][MAX]) {
    int visited[MAX] = {0};
    int recStack[MAX] = {0};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack, V))
                return true;
        }
    }
    return false;
}

int main() {
    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    int adj[MAX][MAX] = {0};

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // directed edge
    }

    if (hasCycle(V, adj))
        printf("YES (Cycle exists)\n");
    else
        printf("NO (No cycle)\n");

    return 0;
}