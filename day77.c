//Problem Statement Using BFS or DFS, check if the entire graph is connected.

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// adjacency list node
struct Node {
    int val;
    struct Node* next;
};

// add edge
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

// DFS function
void dfs(int node, int visited[], struct Node* adj[]) {
    visited[node] = 1;

    struct Node* temp = adj[node];
    while (temp != NULL) {
        if (!visited[temp->val]) {
            dfs(temp->val, visited, adj);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[MAX] = {NULL};

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int visited[MAX] = {0};

    // start DFS from node 1
    dfs(1, visited, adj);

    // check if all nodes are visited
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");

    return 0;
}