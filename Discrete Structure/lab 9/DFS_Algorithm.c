
// DFS Algorithm Implementation in C
// This program implements a Depth-First Search (DFS) algorithm on a graph using an adjacency list representation.

/*
*************************Sample Input/Output:********************************************************
Enter number of vertices: 5
Enter number of edges: 4
Enter 4 edges (format: src dest, 0-based indexing):
0 1
0 2
1 3
2 4
Enter starting vertex for DFS (0 to 4): 0
*/

#include <stdio.h>
#include <stdlib.h>

// Graph node for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

// Create a new node for the adjacency list
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with the specified number of vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Add an edge to the graph (undirected)
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src (undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// DFS algorithm (recursive)
void DFS(struct Graph* graph, int vertex) {
    // Mark the current vertex as visited
    graph->visited[vertex] = 1;
    printf("Visited %d\n", vertex);

    // Traverse all adjacent vertices
    struct Node* temp = graph->adjLists[vertex];
    while (temp != NULL) {
        int connectedVertex = temp->vertex;
        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

// Print the graph's adjacency list
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* temp = graph->adjLists[v];
        printf("\nAdjacency list of vertex %d: ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Free graph memory
void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        while (temp) {
            struct Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph->adjLists);
    free(graph->visited);
    free(graph);
}

// Main function with user input
int main() {
    int vertices, numEdges, src, dest, startVertex;

    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    if (vertices <= 0) {
        printf("Invalid number of vertices. Must be positive.\n");
        return 1;
    }

    // Create graph
    struct Graph* graph = createGraph(vertices);

    // Input number of edges
    printf("Enter number of edges: ");
    scanf("%d", &numEdges);
    if (numEdges < 0) {
        printf("Invalid number of edges. Must be non-negative.\n");
        freeGraph(graph);
        return 1;
    }

    // Input edges
    printf("Enter %d edges (format: src dest, 0-based indexing):\n", numEdges);
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d", &src, &dest);
        if (src < 0 || src >= vertices || dest < 0 || dest >= vertices) {
            printf("Invalid edge (%d, %d). Vertices must be between 0 and %d.\n", src, dest, vertices - 1);
            freeGraph(graph);
            return 1;
        }
        addEdge(graph, src, dest);
    }

    // Input starting vertex for DFS
    printf("Enter starting vertex for DFS (0 to %d): ", vertices - 1);
    scanf("%d", &startVertex);
    if (startVertex < 0 || startVertex >= vertices) {
        printf("Invalid starting vertex. Must be between 0 and %d.\n", vertices - 1);
        freeGraph(graph);
        return 1;
    }

    // Print graph and run DFS
    printf("\nGraph adjacency list:\n");
    printGraph(graph);

    printf("\nDFS starting from vertex %d:\n", startVertex);
    DFS(graph, startVertex);

    // Free allocated memory
    freeGraph(graph);

    return 0;
}