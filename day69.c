#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

// Graph Node
typedef struct Node {
    int v, w;
    struct Node* next;
} Node;

Node* adj[MAX];

// Create Node
Node* createNode(int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->v = v;
    newNode->w = w;
    newNode->next = NULL;
    return newNode;
}

// Add Edge
void addEdge(int u, int v, int w) {
    Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Min Heap Structure
typedef struct {
    int node, dist;
} HeapNode;

HeapNode heap[MAX];
int heapSize = 0;

// Swap
void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up
void heapifyUp(int i) {
    while (i > 0 && heap[i].dist < heap[(i - 1) / 2].dist) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Heapify Down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && heap[left].dist < heap[smallest].dist)
        smallest = left;
    if (right < heapSize && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Push into heap
void push(int node, int dist) {
    heap[heapSize].node = node;
    heap[heapSize].dist = dist;
    heapifyUp(heapSize);
    heapSize++;
}

// Pop min
HeapNode pop() {
    HeapNode root = heap[0];
    heap[0] = heap[--heapSize];
    heapifyDown(0);
    return root;
}

// Dijkstra
void dijkstra(int n, int src) {
    int dist[MAX];

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    push(src, 0);

    while (heapSize > 0) {
        HeapNode curr = pop();
        int u = curr.node;

        Node* temp = adj[u];

        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // Print result
    for (int i = 0; i < n; i++) {
        printf("Distance from %d to %d = %d\n", src, i, dist[i]);
    }
}