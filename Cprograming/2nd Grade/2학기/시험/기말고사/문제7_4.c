#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100
#define MAX_M 1000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int visited[MAX_N];
int graph[MAX_N][MAX_N];

void memsetInit() {
    for (int i = 0; i < MAX_N; i++) {visited[i] = 0;}
}
void dfs(int node, int parent) {
    visited[node] = 1;
    
    for (int i = 0; i < MAX_N; i++) {
        if(graph[i][node] && !visited[i]) {dfs(i, node);}
    }
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    memsetInit(); 

    for(int i=1;i<=n;i++) graph[i][i+1]=1;
    
    for(int i=0;i<m;i++){
        int u, v;
        scanf("%d %d", &u, &v);
        if(u>v) swap(&u,&v);
        
        graph[u][v]=1;
    }
    
    int flag=1;
    
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++){
            memsetInit();
            
            dfs(i, 0); dfs(j, 0);
            
            if(!flag){
                break;
            }else if(visited[j] == 0){ // visited[j]가 null character (0)일 때
                flag = 0;
                break; // 
            }
        }
    }

    if(flag) printf("1");
    else printf("0");

    return 0;
}
