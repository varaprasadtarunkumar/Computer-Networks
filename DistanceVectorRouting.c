#include <stdio.h>
#include <limits.h>

#define MAX_NODES 10

void distanceVectorRouting(int graph[MAX_NODES][MAX_NODES], int nodes) {
    int routingTable[MAX_NODES][MAX_NODES];

    // Initialize the routing table with the given graph
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            routingTable[i][j] = graph[i][j];
        }
    }

    // Perform distance vector algorithm
    for (int k = 0; k < nodes; k++) {
        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < nodes; j++) {
                if (routingTable[i][k] != INT_MAX && routingTable[k][j] != INT_MAX) {
                    int distance = routingTable[i][k] + routingTable[k][j];
                    if (distance < routingTable[i][j]) {
                        routingTable[i][j] = distance;
                    }
                }
            }
        }
    }

    // Print the routing table for each router
    for (int r = 0; r < nodes; r++) {
        printf("\nFor router %d\n\n", r + 1);
        for (int i = 0; i < nodes; i++) {
            if (i != r) {
                printf("node %d via %d Distance %d\n", i + 1, i + 1, routingTable[r][i]);
            }
        }
    }
}

int main() {
    int graph[MAX_NODES][MAX_NODES];
    int nodes;

    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    distanceVectorRouting(graph, nodes);

    return 0;
}
