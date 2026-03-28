#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int isMirror(struct Node* a, struct Node* b) {
    if (a == NULL && b == NULL)
        return 1;

    if (a == NULL || b == NULL)
        return 0;

    if (a->data != b->data)
        return 0;

    return isMirror(a->left, b->right) &&
           isMirror(a->right, b->left);
}

int isSymmetric(struct Node* root) {
    if (root == NULL)
        return 1;

    return isMirror(root->left, root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    struct Node* nodes[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

        if(arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    int j = 1;
    for(int i = 0; i < n && j < n; i++) {
        if(nodes[i] != NULL) {
            if(j < n) nodes[i]->left = nodes[j++];
            if(j < n) nodes[i]->right = nodes[j++];
        }
    }

    if(isSymmetric(nodes[0]))
        printf("YES");
    else
        printf("NO");

    return 0;
}