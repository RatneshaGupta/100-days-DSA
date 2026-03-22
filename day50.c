//Problem: BST Search

#include <stdio.h>
#include <stdlib.h>

// Definition of BST node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }

    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

// Search in BST
struct TreeNode* search(struct TreeNode* root, int key) {
    if (root == NULL || root->val == key) {
        return root;
    }

    if (key < root->val) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

int main() {
    struct TreeNode* root = NULL;
    int n, val, key, i;

    // Input number of nodes
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input elements
    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    // Input value to search
    printf("Enter value to search: ");
    scanf("%d", &key);

    // Search result
    struct TreeNode* result = search(root, key);

    if (result != NULL) {
        printf("Value found in BST\n");
    } else {
        printf("Value not found in BST\n");
    }

    return 0;
}