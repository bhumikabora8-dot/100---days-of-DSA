#include <stdio.h>
#include <stdlib.h>

// Structure of Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Insert into BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Find LCA in BST
struct Node* findLCA(struct Node* root, int p, int q) {
    if (root == NULL)
        return NULL;

    // If both values are smaller, go left
    if (p < root->data && q < root->data)
        return findLCA(root->left, p, q);

    // If both values are greater, go right
    if (p > root->data && q > root->data)
        return findLCA(root->right, p, q);

    // Otherwise, this is LCA
    return root;
}

// Main function
int main() {
    int n, p, q;
    scanf("%d", &n);

    struct Node* root = NULL;

    // Build BST
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }

    scanf("%d %d", &p, &q);

    struct Node* lca = findLCA(root, p, q);

    if (lca != NULL)
        printf("%d\n", lca->data);

    return 0;
}