#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int value;

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
    return head;
}

// Function to merge two sorted linked lists
struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    struct Node *merged = NULL, *tail = NULL;

    while(head1 != NULL && head2 != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

        if(head1->data <= head2->data) {
            newNode->data = head1->data;
            head1 = head1->next;
        } else {
            newNode->data = head2->data;
            head2 = head2->next;
        }

        newNode->next = NULL;

        if(merged == NULL) {
            merged = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Add remaining elements
    while(head1 != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = head1->data;
        newNode->next = NULL;

        if(merged == NULL) {
            merged = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        head1 = head1->next;
    }

    while(head2 != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = head2->data;
        newNode->next = NULL;

        if(merged == NULL) {
            merged = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        head2 = head2->next;
    }

    return merged;
}

// Function to print list
void printList(struct Node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m;

    scanf("%d", &n);
    struct Node* list1 = createList(n);

    scanf("%d", &m);
    struct Node* list2 = createList(m);

    struct Node* mergedList = mergeLists(list1, list2);

    printList(mergedList);

    return 0;
}