#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_NODES 6
#define INF INT_MAX

typedef struct Edge {
    int dest;
    int weight;
    struct Edge *next;
} Edge;

typedef struct {
    Edge *adj[MAX_NODES];
} Graph;

void addEdge(Graph *g, int src, int dest, int weight) {
    Edge *edge1 = (Edge *)malloc(sizeof(Edge));
    edge1->dest = dest;
    edge1->weight = weight;
    edge1->next = g->adj[src];
    g->adj[src] = edge1;

    Edge *edge2 = (Edge *)malloc(sizeof(Edge));
    edge2->dest = src;
    edge2->weight = weight;
    edge2->next = g->adj[dest];
    g->adj[dest] = edge2;
}

void initGraph(Graph *g) {
    for (int i = 0; i < MAX_NODES; i++) {
        g->adj[i] = NULL;
    }

    addEdge(g, 0, 1, 8);  // A <-> B
    addEdge(g, 0, 2, 1);  // A <-> C
    addEdge(g, 0, 3, 4);  // A <-> D
    addEdge(g, 1, 2, 7);  // B <-> C
    addEdge(g, 1, 4, 4);  // B <-> E
    addEdge(g, 2, 3, 5);  // C <-> D
    addEdge(g, 2, 4, 3);  // C <-> E
    addEdge(g, 2, 5, 9);  // C <-> F
    addEdge(g, 3, 5, 4);  // D <-> F
}

void dijkstra(Graph *g, int src, int dest, int *distance, int *pathCount) {
    int dist[MAX_NODES];
    int count[MAX_NODES];
    int visited[MAX_NODES] = {0};

    for (int i = 0; i < MAX_NODES; i++) {
        dist[i] = INF;
        count[i] = 0;
    }
    dist[src] = 0;
    count[src] = 1;

    for (int i = 0; i < MAX_NODES - 1; i++) {
        int u = -1;
        int minDist = INF;

        for (int v = 0; v < MAX_NODES; v++) {
            if (!visited[v] && dist[v] < minDist) {
                u = v;
                minDist = dist[v];
            }
        }

        if (u == -1) break;
        visited[u] = 1;

        for (Edge *edge = g->adj[u]; edge != NULL; edge = edge->next) {
            int v = edge->dest;
            if (!visited[v]) {
                if (dist[v] > dist[u] + edge->weight) {
                    dist[v] = dist[u] + edge->weight;
                    count[v] = count[u];
                } else if (dist[v] == dist[u] + edge->weight) {
                    count[v] += count[u];
                }
            }
        }
    }

    *distance = dist[dest];
    *pathCount = count[dest];
}

int readpair(char *srcChar, char *destChar) {
    // printf("Enter source and target (e.g., A C) or press Enter to exit: ");
    int res = scanf(" %c %c", srcChar, destChar);
    if (res == EOF || res < 2) {
        *srcChar = '\0';
        *destChar = '\0';
        return 0;
    }
    return 1;
}

void writeHeader() {
    printf("source target 최단거리 최단경로 수\n");
}

void writeResult(char src, char dest, int distance, int pathCount) {
    if (distance == INF) {
        printf("%c %c No path exists\n", src, dest);
    } else {
        printf("%-7c%-8c%-6d%-6d\n", src, dest, distance, pathCount);
    }
}

int main() {
    Graph g;
    initGraph(&g);

    writeHeader();

    char srcChar = '\0', destChar = '\0';
    while (1) {
        if (!readpair(&srcChar, &destChar) || (srcChar == '\0' && destChar == '\0')) {
            break;
        }

        int src = srcChar - 'A';
        int dest = destChar - 'A';

        if (src < 0 || src >= MAX_NODES || dest < 0 || dest >= MAX_NODES) {
            printf("Invalid input. Try again.\n");
            continue;
        }

        int distance, pathCount;
        dijkstra(&g, src, dest, &distance, &pathCount);

        writeResult(srcChar, destChar, distance, pathCount);
    }

    return 0;
}


/*
Enter source and target (e.g., A C): C A
Enter source and target (e.g., A C): C F
Enter source and target (e.g., A C): F C
Enter source and target (e.g., A C): B D
Enter source and target (e.g., A C):
*/