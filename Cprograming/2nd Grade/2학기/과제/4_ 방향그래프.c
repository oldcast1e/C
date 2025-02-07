#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define N 20 // 도시 수

// 우선순위 큐 구조체 정의
typedef struct {
    int vertex;
    int cost;
} MinHeapNode;

// 최소 힙 구조체
typedef struct {
    MinHeapNode heap[N * N];
    int size;
} MinHeap;

// 최소 힙 초기화
void initMinHeap(MinHeap *minHeap) {
    minHeap->size = 0;
}

// 최소 힙 삽입
void push(MinHeap *minHeap, int vertex, int cost) {
    MinHeapNode newNode = {vertex, cost};
    int i = minHeap->size++;
    while (i && cost < minHeap->heap[(i - 1) / 2].cost) {
        minHeap->heap[i] = minHeap->heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->heap[i] = newNode;
}

// 최소 힙 제거
MinHeapNode pop(MinHeap *minHeap) {
    MinHeapNode root = minHeap->heap[0];
    MinHeapNode lastNode = minHeap->heap[--minHeap->size];
    int i = 0, smallest, left, right;

    while ((left = 2 * i + 1) < minHeap->size) {
        right = left + 1;
        smallest = (right < minHeap->size && minHeap->heap[right].cost < minHeap->heap[left].cost) ? right : left;
        if (lastNode.cost <= minHeap->heap[smallest].cost) break;
        minHeap->heap[i] = minHeap->heap[smallest];
        i = smallest;
    }
    minHeap->heap[i] = lastNode;
    return root;
}

// 다익스트라 알고리즘
int dijkstra(int A[], int H[], int s, int d) {
    int dist[N];
    bool visited[N];
    MinHeap minHeap;

    // 거리 및 방문 배열 초기화
    for (int i = 0; i < N; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[s] = 0;

    // 최소 힙 초기화 및 시작점 추가
    initMinHeap(&minHeap);
    push(&minHeap, s, 0);

    while (minHeap.size) {
        MinHeapNode current = pop(&minHeap);
        int u = current.vertex;

        if (visited[u]) continue;
        visited[u] = true;

        // 인접한 도시 비용 업데이트
        for (int v = u + 1; v < N; v++) {
            int cost = dist[u] + H[u] + A[v - u];
            if (!visited[v] && dist[v] > cost) {
                dist[v] = cost;
                push(&minHeap, v, dist[v]);
            }
        }
    }

    return dist[d];
}

// 메인 함수
int main() {
    int A[N], H[N];

    // 배열 A는 오름차순으로 초기화
    for (int i = 0; i < N; i++) {
        A[i] = i + 1; // A[i] = 1, 2, 3, ..., N
    }

    // 배열 H는 무작위 값으로 초기화
    srand(0); // 랜덤 시드 고정
    for (int i = 0; i < N; i++) {
        H[i] = rand() % 50 + 1; // H[i]는 1부터 50 사이의 랜덤 값
    }

    // 배열 출력
    printf("A (Flight costs): ");
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    printf("H (Hotel costs): ");
    for (int i = 0; i < N; i++) {
        printf("%d ", H[i]);
    }
    printf("\n");

    int s = 0, d = N - 1;

    // 다익스트라 실행
    int minCost = dijkstra(A, H, s, d);
    printf("Minimum cost (Dijkstra): %d\n", minCost);

    return 0;
}
