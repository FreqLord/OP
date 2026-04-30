#include <stdio.h>
#define INF 9999

int main() {
    int n, e, graph[10][10], dist[10], visited[10];
    int u, v, w, src, choice;

    while(1) {
        printf("\n1. Enter Graph (Edges)\n2. Run Dijkstra\n3. Exit\nChoice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter number of vertices: ");
                scanf("%d", &n);

                // Initialize graph with 0
                for(int i=0;i<n;i++)
                    for(int j=0;j<n;j++)
                        graph[i][j] = 0;

                printf("Enter number of edges: ");
                scanf("%d", &e);

                printf("Enter edges (u v weight):\n");
                for(int i=0;i<e;i++) {
                    scanf("%d %d %d", &u, &v, &w);
                    graph[u][v] = w;   // directed graph
                    // graph[v][u] = w; // uncomment for undirected
                }
                break;

            case 2:
                printf("Enter source: ");
                scanf("%d",&src);

                for(int i=0;i<n;i++){
                    dist[i]=INF;
                    visited[i]=0;
                }
                dist[src]=0;

                for(int count=0;count<n-1;count++){
                    int min=INF, index=-1;

                    for(int i=0;i<n;i++)
                        if(!visited[i] && dist[i]<min){
                            min=dist[i];
                            index=i;
                        }

                    if(index==-1) break;
                    visited[index]=1;

                    for(int j=0;j<n;j++)
                        if(!visited[j] && graph[index][j] &&
                           dist[index]+graph[index][j]<dist[j])
                            dist[j]=dist[index]+graph[index][j];
                }

                printf("Distances:\n");
                for(int i=0;i<n;i++)
                    printf("%d ",dist[i]);
                break;

            case 3:
                return 0;
        }
    }
}
/* 3. DIJKSTRA ALGORITHM
   Using Adjacency Matrix:
      Time Complexity: O(V^2)

   Using Priority Queue (Min Heap):
      Time Complexity: O(E log V)

   Space Complexity: O(V)

   Start

Display menu

Read user choice

If choice = 1:
a) Input number of vertices and edges
b) Initialize graph with 0
c) Read edges (u, v, weight) and populate graph

If choice = 2:
a) Input source vertex
b) Run Dijkstra logic to calculate shortest paths
c) Display shortest distances from the source

If choice = 3:
a) Exit program

Repeat steps 2 to 6 until exit is selected

Stop
*/
