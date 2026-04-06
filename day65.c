//Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected)
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// DFS function
int dfs(int node, int parent, struct Node* adj[], int visited[]) {
    visited[node] = 1;

    struct Node* temp = adj[node];

    while (temp != NULL) {
        int adjNode = temp->data;

        if (!visited[adjNode]) {
            if (dfs(adjNode, node, adj, visited))
                return 1;
        }
        else if (adjNode != parent) {
            return 1; // cycle found
        }

        temp = temp->next;
    }

    return 0;
}

// Cycle detection
int hasCycle(int V, struct Node* adj[]) {
    int visited[MAX] = {0};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited))
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