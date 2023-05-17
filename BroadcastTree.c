#include <stdio.h>
#include <limits.h>

#define MAX_NODES 100

int main() {
    int n, adj_matrix[MAX_NODES][MAX_NODES], i, j, visited[MAX_NODES], min_cost = 0;

    printf("Enter the no of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }

    // Initialize visited array to 0
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Start with node 0
    visited[0] = 1;
    int count = 1;

    printf("The edges of minimum cost spanning tree are:\n");
    while (count < n) {
        int min = INT_MAX, x = 0, y = 0;
        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (!visited[j] && adj_matrix[i][j]) {
                        if (adj_matrix[i][j] < min) {
                            min = adj_matrix[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        visited[y] = 1;
        printf("%d edge(%d,%d)=%d\n", count, x + 1, y + 1, min);
        min_cost += min;
        count++;
    }

    printf("Minimum cost = %d\n", min_cost);

    return 0;
}
