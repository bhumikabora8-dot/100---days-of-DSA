#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* newNode(int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = v;
    node->next = NULL;
    return node;
}

// DFS to detect cycle
int dfs(int v, int parent, struct Node* adj[], int visited[]) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp != NULL) {
        int neighbor = temp->data;

        if (!visited[neighbor]) {
            if (dfs(neighbor, v, adj, visited))
                return 1;
        }
        else if (neighbor != parent) {
            return 1; // cycle found
        }

        temp = temp->next;
    }
    return 0;
}

int hasCycle(int n, struct Node* adj[]) {
    int visited[n];

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // Check all components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited))
                return 1;
        }
    }
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];

    // Initialize
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    // Input edges (undirected)
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // Add edge u-v
        struct Node* node1 = newNode(v);
        node1->next = adj[u];
        adj[u] = node1;

        struct Node* node2 = newNode(u);
        node2->next = adj[v];
        adj[v] = node2;
    }

    if (hasCycle(n, adj))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}