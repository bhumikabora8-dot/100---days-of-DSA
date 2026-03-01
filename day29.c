#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);

    if(n <= 0) return 0;

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int value;

    // Create Linked List
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    int k;
    scanf("%d", &k);

    k = k % n;   // Important

    if(k == 0) {
        temp = head;
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    // Find length and last node
    struct Node* last = head;
    int count = 1;

    while(last->next != NULL) {
        last = last->next;
        count++;
    }

    // Make circular
    last->next = head;

    // Move to (n-k)th node
    struct Node* newTail = head;
    for(int i = 1; i < count - k; i++) {
        newTail = newTail->next;
    }

    // New head
    head = newTail->next;

    // Break circle
    newTail->next = NULL;

    // Print rotated list
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}