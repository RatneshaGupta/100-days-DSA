//Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack
int stack[MAX];
int top = -1;

// Graph
int adj[MAX][MAX];
int visited[MAX];

// Push to stack
void push(int v) {
    stack[++top] = v;
}

// DFS function
void dfs(int v, int n) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }

    // push after visiting all neighbors
    push(v);
}

// Topological Sort
void topoSort(int n) {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n);
        }
    }

    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

// Main function
int main() {
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // initialize
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // directed edge
    }

    topoSort(n);

    return 0;
}