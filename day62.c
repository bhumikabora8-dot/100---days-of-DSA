#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
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

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Array of pointers to Node
    struct Node* adj[n];

    // Initialize all lists as empty
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    int u, v;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // Undirected graph:

        // Add v to u's list
        struct Node* node1 = newNode(v);
        node1->next = adj[u];
        adj[u] = node1;

        // Add u to v's list
        struct Node* node2 = newNode(u);
        node2->next = adj[v];
        adj[v] = node2;

        // For directed graph, comment above and use only:
        // struct Node* node = newNode(v);
        // node->next = adj[u];
        // adj[u] = node;
    }

    // Print adjacency list
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        struct Node* temp = adj[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    return 0;
}