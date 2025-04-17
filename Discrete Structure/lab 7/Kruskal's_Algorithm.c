
// Kruskal's Algorithm for Minimum Spanning Tree
// This program finds the minimum spanning tree of a connected, undirected graph using Kruskal's algorithm.
// The graph is represented using an adjacency matrix, and the program allows the user to input the number of vertices and the cost matrix.
// The program then computes and displays the edges of the minimum spanning tree and its total cost.

#include <stdio.h>

#define MAX 100
#define INF 999

int parent[MAX], cost[MAX][MAX], n, ne = 1, mincost = 0;

int find(int);
int uni(int, int);

int main() {
    int i, j, min, a, b, u, v;

    printf("\nImplementation of Kruskal's Algorithm\n");
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix (0 for no edge):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = INF; // No edge
            }
        }
    }

    printf("The edges of the Minimum Spanning Tree are:\n");
    while (ne < n) { // Need n-1 edges
        for (i = 1, min = INF; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (uni(u, v)) {
            printf("Edge %d: (%d, %d) = %d\n", ne++, a, b, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = INF; // Remove edge
    }

    printf("\nMinimal cost = %d\n", mincost);
    return 0;
}

int find(int i) {
    while (parent[i]) {
        i = parent[i];
    }
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i; // Union by making i the parent of j
        return 1;
    }
    return 0; // Cycle detected
}