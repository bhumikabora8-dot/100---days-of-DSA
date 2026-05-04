#include <stdio.h>
#include <stdlib.h>

// Node for linked list (bucket)
struct Node {
    float data;
    struct Node* next;
};

// Insert in sorted order (for bucket)
struct Node* insertSorted(struct Node* head, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // Insert at beginning
    if (head == NULL || value < head->data) {
        newNode->next = head;
        return newNode;
    }

    // Insert in middle/end
    struct Node* curr = head;
    while (curr->next != NULL && curr->next->data < value) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}

void bucketSort(float arr[], int n) {
    // Step 1: Create buckets
    struct Node* buckets[n];
    for (int i = 0; i < n; i++)
        buckets[i] = NULL;

    // Step 2: Distribute elements
    for (int i = 0; i < n; i++) {
        int index = (int)(n * arr[i]);  // bucket index
        buckets[index] = insertSorted(buckets[index], arr[i]);
    }

    // Step 3: Concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        struct Node* curr = buckets[i];
        while (curr != NULL) {
            arr[k++] = curr->data;
            curr = curr->next;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}