#include <stdio.h>

#define MAX 20
#define INF 999

// Structure to hold vertex info
struct vertex {
    int color;     // 0 = unvisited, 1 = visited, 2 = traversed
    int distance;  // distance from source
    int parent;    // parent node
};

int main() {
    int n, adj[MAX][MAX];
    int i, j, start;
    struct vertex v[MAX];
    int queue[MAX], front = 0, rear = 0;

    // Input section
    printf("Enter number of nodes  graph: ");
    scanf("%d", &n);

    printf("Enter start node: ");
    scanf("%d", &start);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Initialize vertices
    for (i = 0; i < n; i++) {
        v[i].color = 0;
        v[i].distance = INF;
        v[i].parent = -1;
    }

    // Initialize source
    v[start].color = 1;
    v[start].distance = 0;
    queue[rear++] = start;

    printf("\nBFS Traversal Order: ");

    // BFS algorithm
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        for (i = 0; i < n; i++) {
            if (adj[u][i] == 1 && v[i].color == 0) {
                v[i].color = 1;
                v[i].distance = v[u].distance + 1;
                v[i].parent = u;
                queue[rear++] = i;
            }
        }
        v[u].color = 2;
    }

    // Output the BFS results
    printf("\n\nNode\tDistance\tParent\n");
    for (i = 0; i < n; i++) {
        if (v[i].distance == INF)
            printf("%d\tINF\t\t%d\n", i, v[i].parent);
        else
            printf("%d\t%d\t\t%d\n", i, v[i].distance, v[i].parent);
    }

    return 0;
}