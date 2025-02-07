#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 6
#define INF 10000 // 가중치가 없는 상태를 표시하기 위한 값

// 인접 행렬 초기화
void initializeGraph(int graph[MAX_VERTICES][MAX_VERTICES]) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            graph[i][j] = INF; // 모든 값 INF로 초기화 (간선 없음)
        }
    }
}

// 간선 추가 또는 가중치 수정 함수
void modifyEdge(int graph[MAX_VERTICES][MAX_VERTICES], int a, int b, int weight) {
    if (weight == 0) {
        // 가중치가 0이면 간선 삭제
        graph[a][b] = INF;
        graph[b][a] = INF;
    } else {
        // 가중치가 0이 아니면 간선 추가 또는 수정
        graph[a][b] = weight;
        graph[b][a] = weight;
    }
}

// 인접 노드 출력 함수
void printAdjacent(int graph[MAX_VERTICES][MAX_VERTICES], int vertex) {
    int found = 0;
    for (int j = 0; j < MAX_VERTICES; j++) {
        if (graph[vertex][j] != INF) {
            printf("%d %d ", j + 1, graph[vertex][j]);
            found = 1;
        }
    }
    if (!found) printf("-1");
    printf("\n");
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];
    char command;
    int a, b, w;

    initializeGraph(graph); // 그래프 초기화

    while (1) {
        scanf(" %c", &command);
        if (command == 'a') {
            scanf("%d", &a);
            printAdjacent(graph, a - 1); // 정점 a의 인접 정점 출력
        } else if (command == 'm') {
            scanf("%d %d %d", &a, &b, &w);
            modifyEdge(graph, a - 1, b - 1, w); // 간선 가중치 수정 또는 삭제
        } else if (command == 'q') {
            break; // 프로그램 종료
        }
    }

    return 0;
}
