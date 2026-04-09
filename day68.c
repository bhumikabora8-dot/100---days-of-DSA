#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = -1, rear = -1;

// Queue operations
void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

int main() {
    int n, e;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    // Initialize
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    // Input edges
    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    // Push all vertices with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }

    int count = 0;
    int topo[MAX];

    while (!isEmpty()) {
        int u = dequeue();
        topo[count++] = u;

        // Reduce indegree of neighbors
        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1) {
                indegree[v]--;
                if (indegree[v] == 0)
                    enqueue(v);
            }
        }
    }

    // Check for cycle
    if (count != n) {
        printf("Cycle detected! Topological sort not possible.\n");
    } else {
        printf("Topological Order:\n");
        for (int i = 0; i < count; i++) {
            printf("%d ", topo[i]);
        }
    }

    return 0;
}