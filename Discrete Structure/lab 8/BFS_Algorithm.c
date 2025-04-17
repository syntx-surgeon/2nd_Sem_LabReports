
// BFS Algorithm Implementation in C
// This program implements the Breadth-First Search (BFS) algorithm on a graph using an adjacency list representation.
// It includes user input for the number of vertices, edges, and the edges themselves. 


/*
**************************Sample Input/Output:************************************************

Enter number of vertices: 6
Enter number of edges: 6
Enter 6 edges (format: src dest, 0-based indexing):
0 1
0 2
1 2
1 3
2 3
3 4
Enter starting vertex for BFS (0 to 5): YOUR STARTING VERTEX
*/


#include <stdio.h>
#include <stdlib.h>

#define SIZE 40

// Queue structure
struct Queue {
    int items[SIZE];
    int front;
    int rear;
};

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

// Queue functions
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

// Graph functions
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

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

// BFS algorithm
void bfs(struct Graph* graph, int startVertex) {
    struct Queue* q = createQueue();

    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("Visited %d\n", currentVertex);

        struct Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
    free(q);
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
    if (vertices <= 0 || vertices > SIZE) {
        printf("Invalid number of vertices. Must be between 1 and %d.\n", SIZE);
        return 1;
    }

    // Create graph
    struct Graph* graph = createGraph(vertices);

    // Input number of edges
    printf("Enter number of edges: ");
    scanf("%d", &numEdges);
    if (numEdges < 0) {
        printf("Invalid number of edges.\n");
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

    // Input starting vertex for BFS
    printf("Enter starting vertex for BFS (0 to %d): ", vertices - 1);
    scanf("%d", &startVertex);
    if (startVertex < 0 || startVertex >= vertices) {
        printf("Invalid starting vertex. Must be between 0 and %d.\n", vertices - 1);
        freeGraph(graph);
        return 1;
    }

    // Run BFS
    printf("\nBFS starting from vertex %d:\n", startVertex);
    bfs(graph, startVertex);

    // Free allocated memory
    freeGraph(graph);

    return 0;
}