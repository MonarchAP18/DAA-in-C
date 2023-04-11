#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 1000

int dist[MAX_NODES];
int parent[MAX_NODES];

void bellmanFord(int n, int m, int s, int edges[][3]) {
    int i, j, u, v, w;

    for (i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
    dist[s] = 0;

    for (i = 1; i < n; i++) {
        for (j = 0; j < m; j++) {
            u = edges[j][0];
            v = edges[j][1];
            w = edges[j][2];
            if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }

    for (i = 0; i < n; i++) {
        printf("%d %d\n", i, dist[i]);
    }
}

int main() {
    int n, m, s, i;

    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    int edges[m][3];
    for (i = 0; i < m; i++) {
        printf("Enter edge's length of edge %d: ", i+1);
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    printf("Enter the starting node: ");
    scanf("%d", &s);

    bellmanFord(n, m, s, edges);

    return 0;
}