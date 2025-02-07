#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

// 그래프의 정점 구조체 정의
typedef struct {
    char name;              // 정점의 이름
    int inDegree;           // 진입 차수
    int outEdges[MAX_VERTICES]; // 진출 간선 리스트 (연결된 정점의 인덱스를 저장)
    int outEdgeCount;       // 진출 간선의 개수
} Vertex;

// 전역 변수 정의
Vertex G[MAX_VERTICES];      // 그래프의 정점 배열
int n, m;                    // 정점 수, 간선 수
int in[MAX_VERTICES];        // 각 정점의 진입 차수를 저장하는 배열
int topOrder[MAX_VERTICES + 1]; // 위상 정렬 순서 배열
int queue[MAX_VERTICES];     // 큐 배열
int front = 0, rear = 0;     // 큐의 앞과 뒤 인덱스

// 큐 관련 함수 정의
int isEmpty() { return front == rear; }
void enqueue(int v) { queue[rear++] = v; }
int dequeue() { return queue[front++]; }

// 정점 이름으로 인덱스를 찾는 함수
int findIndex(char vName) {
    for (int i = 0; i < n; i++) {
        if (G[i].name == vName) return i;
    }
    return -1; // 정점이 없을 경우 -1 반환
}

// 정점을 그래프에 추가하는 함수
void insertVertex(char vName, int i) {
    G[i].name = vName;        // 정점 이름 설정
    G[i].inDegree = 0;        // 진입 차수 초기화
    G[i].outEdgeCount = 0;    // 진출 간선 개수 초기화
}

// 방향 간선을 그래프에 추가하는 함수
void insertDirectedEdge(char uName, char wName) {
    int u = findIndex(uName);     // 시점 정점 인덱스
    int w = findIndex(wName);     // 종점 정점 인덱스

    // 시점의 진출 간선 리스트에 종점을 추가하고, 종점의 진입 차수를 증가
    G[u].outEdges[G[u].outEdgeCount++] = w;
    G[w].inDegree++;
}

// 그래프 구축 함수
void buildGraph() {
    scanf("%d\n", &n); // 정점 수 입력
    for (int i = 0; i < n; i++) {
        char vName;
        scanf(" %c", &vName); // 각 정점의 이름 입력
        insertVertex(vName, i);
    }

    scanf("%d\n", &m); // 간선 수 입력
    for (int i = 0; i < m; i++) {
        char uName, wName;
        scanf(" %c %c", &uName, &wName); // 각 방향 간선 정보 입력
        insertDirectedEdge(uName, wName);
    }
}

// 위상 정렬 함수
void topologicalSort() {
    // 초기화: 모든 정점의 진입 차수를 배열 `in`에 저장
    for (int i = 0; i < n; i++) {
        in[i] = G[i].inDegree;
        if (in[i] == 0) { // 진입 차수가 0인 정점은 큐에 삽입
            enqueue(i);
        }
    }

    int t = 1; // 위상 정렬 순서 인덱스

    // 큐가 빌 때까지 반복
    while (!isEmpty()) {
        int u = dequeue();     // 진입 차수가 0인 정점을 큐에서 꺼냄
        topOrder[t++] = u;     // 위상 순서 배열에 추가

        // `u`의 모든 진출 간선에 대해
        for (int i = 0; i < G[u].outEdgeCount; i++) {
            int w = G[u].outEdges[i]; // 종점 정점
            in[w]--;                 // 진입 차수 감소
            if (in[w] == 0) {        // 진입 차수가 0이 되면 큐에 삽입
                enqueue(w);
            }
        }
    }

    // 위상 정렬이 완료되지 않았다면 싸이클이 존재
    if (t <= n) {
        topOrder[0] = 0; // 싸이클 존재 표시
    } else {
        topOrder[0] = 1; // DAG임을 표시
    }
}

// main 함수
int main() {
    buildGraph();       // 그래프 구축
    topologicalSort();  // 위상 정렬 수행

    // 출력: 위상 정렬 결과 또는 싸이클 여부
    if (topOrder[0] == 0) {
        printf("0\n"); // 싸이클이 존재하여 위상 정렬 불가
    } else {
        for (int i = 1; i <= n; i++) {
            printf("%c ", G[topOrder[i]].name); // 위상 정렬 순서 출력
        }
        printf("\n");
    }

    return 0;
}
/*
3
A B C
3
A B
C A
C B
*/