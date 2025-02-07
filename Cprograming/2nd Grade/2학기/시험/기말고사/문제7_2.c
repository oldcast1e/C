#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100
#define MAX_M 1000

int visited[MAX_N];
int graph[MAX_N][MAX_N];

void dfs(int node, int parent) {
    visited[node] = 1;
    
    for (int i = 0; i < MAX_N; i++) {
        if (graph[i][node] != -1 && !visited[i]) {
            dfs(i, node);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; i++) {
        graph[i][i] = -1; // 自己와의 간선은 없도록
    }
    
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        
        graph[u][v] = 1;
    }
    
    int result = 0;
    
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        dfs(i, -1);
        
        // 강연결성에 해당하는 정점이 있는지 확인
        bool isStronglyConnected = true;
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                isStronglyConnected = false;
                break;
            }
        }
        
        result += isStronglyConnected ? 1 : 0;
    }
    
    printf("%d\n", result);
    
    return 0;
}
