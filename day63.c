//Problem: Perform DFS starting from a given source vertex using recursion.

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Add edge (undirected)
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// DFS function
void dfs(struct Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node* temp = graph->adjLists[vertex];

    while (temp) {
        int adjVertex = temp->vertex;

        if (!visited[adjVertex]) {
            dfs(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    struct Graph* graph = createGraph(n);

    // Input adjacency list manually
    // For each vertex, input number of neighbors then neighbors
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k); // number of adjacent vertices

        for (int j = 0; j < k; j++) {
            int v;
            scanf("%d", &v);
            addEdge(graph, i, v);
        }
    }

    int s;
    scanf("%d", &s); // starting vertex

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    dfs(graph, s, visited);

    return 0;
}