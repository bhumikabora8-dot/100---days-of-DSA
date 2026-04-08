#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];     // Adjacency matrix
int visited[MAX];      // Visited array
int stack[MAX];        // Stack to store result
int top = -1;
int n;                 // Number of vertices

// Push to stack
void push(int v) {
    stack[++top] = v;
}

// DFS function
void dfs(int v) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }

    push(v);  // Push after visiting all neighbors
}

// Topological sort
void topoSort() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    printf("Topological Ordering:\n");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    topoSort();

    return 0;
}