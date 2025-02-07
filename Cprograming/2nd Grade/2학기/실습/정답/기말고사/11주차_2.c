/*
[ 문제 2 ] (BFS) 입력으로 주어지는 그래프의 BFS 순회 결과를 출력하는 프로그램을 작성하시오.
입력 그래프의 성질:
◦ 문제 1과 동일
구현 조건:
◦ 그래프는 인접행렬 구조를 사용하여 표현해야 한다.
◦ 인접 정점의 조사 순서
- 문제 1과 동일하게 정점의 인접 정점(or 부착 간선)들을 번호가 작은 정점부터 조사한다.
입출력:
◦ 입력 : 문제 1과 동일
◦ 출력 : 출발정점 s에서 출발하는 BFS의 방문 순서대로 정점 번호를 출력한다.
*/


#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
#define MAX 1001

int metrix[MAX][MAX];
int visited[MAX * MAX];

void BFS(int v, int N) {
	int front = -1, rear = -1;
	int queue[MAX * MAX] = { 0 };

	// 첫번째 추가
	rear++;
	queue[rear] = v;

	// 방문 표시
	visited[v] = 1;

	// 일단 출력
	printf("%d ", v);

	// 너비 우선 탐색
	while (front < rear) {
		// 큐에서 꺼내기
		front++;
		int nextV = queue[front];

		// 인접 정점 체크
		for (int d = 1; d <= N; d++) {
			// 방문하지 않았고, 이동이 가능하다면
			if (!visited[d] && metrix[nextV][d]) {
				rear++;
				visited[d] = 1;
				queue[rear] = d;

				printf("%d ", d);
			}
		}
	}
}

void init(int N) {
	printf("\n");
	for (int i = 1; i <= N; i++) {
		visited[i] = 0;
	}
}

int main(void) {
	int N = 0;
	int M = 0;
	int V = 0;

	scanf("%d %d %d", &N, &M, &V);

	for (int i = 0; i < M; i++) {
		int s = 0, d = 0;

		scanf("%d %d", &s, &d);

		metrix[s][d] = 1;
		metrix[d][s] = 1;
	}

	init(N);

	BFS(V, N);

	return 0;
}