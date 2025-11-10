#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter number of cities (nodes): ");
    scanf("%d", &n);

    int graph[n][n];

    printf("Enter adjacency matrix (0/1) for the graph:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}

PART (B): Display Reachable Nodes Using DFS and BFS
Algorithm (DFS & BFS)
DFS:
1. Start from source node.
2. Mark node as visited.
3. Recursively visit all connected unvisited nodes.

BFS:
1. Insert start node into queue.
2. Visit and mark it.
3. Insert all unvisited neighbors into queue.
4. Continue until queue is empty.
Program Code (Part B)

#include <stdio.h>

int graph[20][20], visited[20], queue[20];
int n, front = 0, rear = 0;

void DFS(int v){
    int i;
    visited[v] = 1;
    printf("%d ", v);
    for(i = 0; i < n; i++){
        if(graph[v][i] == 1 && !visited[i])
            DFS(i);
    }
}

void BFS(int v){
    int i;
    visited[v] = 1;
    queue[rear++] = v;

    while(front < rear){
        v = queue[front++];
        printf("%d ", v);

        for(i = 0; i < n; i++){
            if(graph[v][i] == 1 && !visited[i]){
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main(){
    int i, j, start;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting node: ");
    scanf("%d", &start);

    printf("\nNodes reachable using DFS: ");
    for(i = 0; i < n; i++) visited[i] = 0;
    DFS(start);

    printf("\nNodes reachable using BFS: ");
    for(i = 0; i < n; i++) visited[i] = 0;
    BFS(start);

    return 0;
}