//Problem Statement: Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Queue structure (node + horizontal distance)
struct QNode {
    struct TreeNode* node;
    int hd;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Build tree from level order input
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode* root = newNode(arr[0]);

    struct TreeNode* queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct TreeNode* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

// Vertical Order Traversal
void verticalOrder(struct TreeNode* root) {
    if (!root) return;

    struct QNode queue[MAX];
    int front = 0, rear = 0;

    // Store nodes for each HD
    int map[MAX][MAX];
    int count[MAX] = {0};

    int offset = MAX / 2;  // to handle negative HD

    queue[rear++] = (struct QNode){root, 0};

    int minHD = 0, maxHD = 0;

    while (front < rear) {
        struct QNode temp = queue[front++];
        struct TreeNode* node = temp.node;
        int hd = temp.hd;

        int index = hd + offset;

        map[index][count[index]++] = node->val;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (node->left)
            queue[rear++] = (struct QNode){node->left, hd - 1};

        if (node->right)
            queue[rear++] = (struct QNode){node->right, hd + 1};
    }

    // Print vertical order
    for (int i = minHD; i <= maxHD; i++) {
        int idx = i + offset;
        for (int j = 0; j < count[idx]; j++) {
            printf("%d ", map[idx][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct TreeNode* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}