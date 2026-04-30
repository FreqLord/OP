#include <stdio.h>
#define INF 9999

struct Edge {
    int u, v, w;
};

int main() {
    int n, e, choice, src;
    struct Edge edges[50];
    int dist[10];

    while(1) {
        printf("\n1. Enter Graph (Edges)\n2. Run Bellman-Ford\n3. Exit\nChoice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter number of vertices: ");
                scanf("%d", &n);

                printf("Enter number of edges: ");
                scanf("%d", &e);

                printf("Enter edges (u v weight):\n");
                for(int i = 0; i < e; i++) {
                    scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
                }
                break;

            case 2:
                printf("Enter source: ");
                scanf("%d", &src);

                // Initialize distances
                for(int i = 0; i < n; i++)
                    dist[i] = INF;

                dist[src] = 0;

                // Relax edges V-1 times
                for(int i = 1; i <= n-1; i++) {
                    for(int j = 0; j < e; j++) {
                        int u = edges[j].u;
                        int v = edges[j].v;
                        int w = edges[j].w;

                        if(dist[u] != INF && dist[u] + w < dist[v])
                            dist[v] = dist[u] + w;
                    }
                }

                // Check negative cycle
                int flag = 0;
                for(int j = 0; j < e; j++) {
                    int u = edges[j].u;
                    int v = edges[j].v;
                    int w = edges[j].w;

                    if(dist[u] != INF && dist[u] + w < dist[v]) {
                        flag = 1;
                        break;
                    }
                }

                if(flag) {
                    printf("Negative weight cycle detected!\n");
                } else {
                    printf("Shortest distances:\n");
                    for(int i = 0; i < n; i++)
                        printf("%d ", dist[i]);
                }
                break;

            case 3:
                return 0;
        }
    }
}
/* 5. BELLMAN-FORD ALGORITHM
   Time Complexity: O(V * E)
   Space Complexity: O(V)

   Note: Can detect negative weight cycles

Start

Display menu

Read user choice

If choice = 1:
a) Input number of vertices and edges
b) Read edges (u, v, weight)

If choice = 2:
a) Input source vertex
b) Relax all edges V-1 times to find shortest paths
c) Iterate one more time to check for negative weight cycles
d) Display shortest distances, or display warning if negative cycle is detected

If choice = 3:
a) Exit program

Repeat steps 2 to 6 until exit is selected

Stop
*/
