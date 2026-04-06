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

// BFS function
void bfs(int s, struct Node* adj[], int n) {
    int visited[n];
    int queue[n];
    int front = 0, rear = 0;

    // Initialize visited
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // Start from source
    visited[s] = 1;
    queue[rear++] = s;

    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        struct Node* temp = adj[curr];
        while (temp != NULL) {
            int v = temp->data;
            if (!visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* adj[n];

    // Initialize
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    // Input adjacency list
    // Format:
    // For each vertex:
    // k (number of neighbors) followed by k neighbors

    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);

        for (int j = 0; j < k; j++) {
            int v;
            scanf("%d", &v);

            struct Node* node = newNode(v);
            node->next = adj[i];
            adj[i] = node;
        }
    }

    int s;
    scanf("%d", &s);

    // Perform BFS
    bfs(s, adj, n);

    return 0;
}