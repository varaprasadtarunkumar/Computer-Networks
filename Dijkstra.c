#include <stdio.h>
#include <limits.h>

// Number of vertices in the graph
#define V 5

// Function to find the vertex with minimum distance value
int minDistance(int dist[], int sptSet[]) {
   int min = INT_MAX, min_index;
   for (int v = 0; v < V; v++)
      if (sptSet[v] == 0 && dist[v] <= min)
         min = dist[v], min_index = v;
   return min_index;
}

// Function to print the final solution
void printSolution(int dist[]) {
   printf("Vertex \t Distance from Source\n");
   for (int i = 0; i < V; i++)
      printf("%d \t %d\n", i, dist[i]);
}

// Function that implements Dijkstra's single source shortest path algorithm
void dijkstra(int graph[V][V], int src) {
   int dist[V]; // Stores the shortest distance from src to i
   
   // sptSet[i] is true if vertex i is included in shortest path tree or shortest distance from src to i is finalized
   int sptSet[V] = { 0 };

   // Initialize all distances as INFINITE and sptSet[] as false
   for (int i = 0; i < V; i++)
      dist[i] = INT_MAX;

   // Distance of source vertex from itself is always 0
   dist[src] = 0;

   // Find shortest path for all vertices
   for (int count = 0; count < V - 1; count++) {
      int u = minDistance(dist, sptSet); // Pick the minimum distance vertex from the set of vertices not yet processed
      sptSet[u] = 1; // Mark the picked vertex as processed

      // Update dist[v] only if it's not in sptSet, there is an edge from u to v, and the total weight of path from src to v through u is smaller than current value of dist[v]
      for (int v = 0; v < V; v++)
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
   }

   // Print the shortest path to all the vertices
   printSolution(dist);
}

// Driver program to test above function
int main() {
   int graph[V][V];
   
   printf("Enter the graph matrix (%d x %d):\n", V, V);
   for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
         scanf("%d", &graph[i][j]);
      }
   }

   int src;
   printf("Enter the source vertex: ");
   scanf("%d", &src);

   dijkstra(graph, src);

   return 0;
}
