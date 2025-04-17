
// Dijkstra's Algorithm Implementation in C
// This program finds the shortest paths from a source node to all other nodes in a weighted graph using Dijkstra's algorithm.
// The graph is represented using an adjacency matrix, and the program allows the user to input the number of nodes and the cost matrix.
// The program then computes and displays the shortest paths and their costs.

#include <stdio.h>

#define INFINITY 999
#define MAX 10

void dij(int n, int v, int cost[MAX][MAX], int dist[], int pred[]);
void print_path(int v, int i, int pred[]);

int main() {
    int n, cost[MAX][MAX], dist[MAX], pred[MAX];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Number of nodes must be between 1 and %d.\n", MAX);
        return 1;
    }

    printf("\nEnter the cost matrix (use 0 for no edge):\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j) {
                cost[i][j] = INFINITY;
            }
        }
    }

    for (int v = 1; v <= n; v++) {
        dij(n, v, cost, dist, pred);
        printf("\nShortest Paths from Node %d:\n", v);
        printf("Node | Cost     | Path\n");
        printf("-----|----------|----------------\n");
        for (int i = 1; i <= n; i++) {
            if (i != v) {
                printf("%4d |", i);
                if (dist[i] >= INFINITY) {
                    printf("%9s | No path\n", "INF");
                } else {
                    printf("%9d | ", dist[i]);
                    print_path(v, i, pred);
                    printf("\n");
                }
            }
        }
    }

    return 0;
}

void dij(int n, int v, int cost[MAX][MAX], int dist[], int pred[]) {
    int visited[MAX], count, min, u, w;

    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        dist[i] = cost[v][i];
        pred[i] = v;
        if (dist[i] >= INFINITY && i != v) {
            pred[i] = 0;
        }
    }
    visited[v] = 1;
    dist[v] = 0;
    pred[v] = 0;
    count = 1;

    while (count < n) {
        min = INFINITY;
        u = 0;

        for (w = 1; w <= n; w++) {
            if (dist[w] < min && !visited[w]) {
                min = dist[w];
                u = w;
            }
        }

        if (u == 0) break;

        visited[u] = 1;
        count++;

        for (w = 1; w <= n; w++) {
            if (!visited[w] && dist[u] + cost[u][w] < dist[w]) {
                dist[w] = dist[u] + cost[u][w];
                pred[w] = u;
            }
        }
    }
}

void print_path(int v, int i, int pred[]) {
    int path[MAX], len = 0;
    int curr = i;

    while (curr != 0) {
        path[len++] = curr;
        curr = pred[curr];
    }

    for (int j = len - 1; j >= 0; j--) {
        printf("%d", path[j]);
        if (j > 0) {
            printf("->");
        }
    }
}