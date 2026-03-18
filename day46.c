//Problem: Level Order Traversal

#include <stdio.h>
#include <stdlib.h>

// Define Tree Node
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build tree from level order input
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct TreeNode* root = createNode(arr[0]);

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct TreeNode* current = queue[front++];

        // Left child
        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    return root;
}

// Level Order Traversal
void levelOrder(struct TreeNode* root) {
    if (root == NULL) {
        printf("[]\n");
        return;
    }

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    printf("[\n");

    while (front < rear) {
        int levelSize = rear - front;

        printf("  [");
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];

            printf("%d", node->val);
            if (i < levelSize - 1)
                printf(", ");

            if (node->left)
                queue[rear++] = node->left;

            if (node->right)
                queue[rear++] = node->right;
        }
        printf("]\n");
    }

    printf("]\n");
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    levelOrder(root);

    return 0;
}