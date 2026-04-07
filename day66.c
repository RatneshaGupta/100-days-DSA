//Problem: Detect cycle in directed graph using DFS and recursion stack.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (directed)
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// DFS function
int dfs(int node, struct Node* adj[], int visited[], int recStack[]) {
    visited[node] = 1;
    recStack[node] = 1;

    struct Node* temp = adj[node];

    while (temp != NULL) {
        int adjNode = temp->data;

        if (!visited[adjNode]) {
            if (dfs(adjNode, adj, visited, recStack))
                return 1;
        }
        else if (recStack[adjNode]) {
            return 1; // cycle found
        }

        temp = temp->next;
    }

    recStack[node] = 0; // remove from recursion stack
    return 0;
}

// Check cycle
int hasCycle(int V, struct Node* adj[]) {
    int visited[MAX] = {0};
    int recStack[MAX] = {0};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack))
                return 1;
        }
    }
    return 0;
}

// Main
int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    struct Node* adj[MAX];

    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    int u, v;
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    if (hasCycle(V, adj))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}