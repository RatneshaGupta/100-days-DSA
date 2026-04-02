//Problem: Build a graph with n vertices and m edges using adjacency matrix representation.The graph may be directed or undirected.

#include <stdio.h>

int main() {
    int n, m;

    // Input number of vertices and edges
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    int adj[n][n];

    // Step 1: Initialize matrix with 0
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    int u, v;

    // Step 2: Input edges
    printf("Enter edges (u v):\n");
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // For directed graph
        adj[u][v] = 1;

        // Uncomment below for undirected graph
        // adj[v][u] = 1;
    }

    // Step 3: Print adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}