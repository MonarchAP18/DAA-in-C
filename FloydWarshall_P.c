#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 1000

int dist[MAX_NODES][MAX_NODES];

void floydWarshall(int n) {
    int i, j, k;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else if (dist[i][j] == 0) {
                dist[i][j] = INT_MAX;
            }
        }
    }

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) {
                    continue;
                }
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    int n, m, u, v, w, i, j;

    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            dist[i][j] = 0;
        }
    }

    for (i = 0; i < m; i++) {
        printf("Enter the lengths of the edges %d: ", i+1);
        scanf("%d %d %d", &u, &v, &w);
        dist[u][v] = w;
    }

    floydWarshall(n);

    printf("Shortest path matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (dist[i][j] == INT_MAX) {
                printf("INF ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}