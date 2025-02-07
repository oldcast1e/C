#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100
#define MAX_M 1000

int visited[MAX_N];
int tree[MAX_M];

void rdfs(int v, int g) {
    visited[v] = 1;

    for (int i = 0; i < MAX_N * 2; i++) {
        if (tree[i] == g && !visited[i / 2]) {
            rdfs(i / 2, i);
        } else if (tree[i] != g) {
            break;
        }
    }

}

int main() {

    int n, m;

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        tree[(i - 1) * 2 + 0] = 0;
        tree[(i - 1) * 2 + 1] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;

        scanf("%d %d", &u, &v);

        if (u > v) u ^= v;
        v ^= u;
        u ^= v;

        tree[(u - 1) * 2 + 0] = v;
        tree[(u - 1) * 2 + 1] = 0;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            rdfs(i, i);
        }
    }

    int result = 1;
    for (int i = 0; i < m; i++) {
        if (tree[(i - 1) * 2 + 0] == tree[(i - 1) * 2 + 1]) result = 1;
        else {result = 0;}
    }

    printf("%d",result);
    return 0;
}

/*
5 5
3 1
3 4
3 5
5 2
2 3
*/