/*
[ 문제 1 ] (DFS) 입력으로 주어지는 그래프의 DFS 순회 결과를 출력하는 프로그램을 작성하시오.
입력 그래프의 성질:
◦ n (1 ≤ n ≤ 100) 개의 정점과 m (1 ≤ m ≤ 1,000) 개의 간선으로 구성
◦ 정점은 1 ~ n 사이의 정수로 번호가 매겨져 있고, 정점의 번호는 모두 다름
◦ 모든 간선은 무방향 간선이고, 한 정점에서 임의의 다른 정점으로 가는 경로는 반드시 존재
구현 조건:
◦ 그래프는 인접리스트 구조를 사용하여 표현해야 한다.
◦ 인접 정점의 조사 순서
- 정점 u의 인접 정점(or 부착 간선)들을 번호가 작은 정점부터 조사한다.
(즉, 아래 DFS 의사 코드의 for 문(☚)에서 인접 정점들을 번호가 작은 정점부터 큰
순서대로 조사하라. 조사 순서에 따라 방문 결과가 달라질 수 있음에 유의할 것)

DFS(u)
{ 	u 방문;
	for u의 인접 정점들 w에 대해서 ☚
	if (w를 아직 방문하지 않았으면)
	DFS(w);
}

입출력:
◦ 입력
- 첫 줄에 정점의 개수 n, 간선의 개수 m, 순회 시작 정점 번호 s가 주어진다.
- 이후 m개의 줄에 한 줄에 하나씩 간선의 정보(간선의 양 끝 정점 번호)가 주어진다.
간선은 임의의 순서로 입력되고, 중복 입력되는 간선은 없다.
(무방향 간선이므로 간선 (u, v)와 (v, u)는 동일한 간선으로 취급)
◦ 출력
- 출발정점 s에서 출발하는 DFS의 방문 순서대로 정점 번호를 출력한다.
*/

#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct Node {
	int edgeNum, point;
	struct Node *next;
}Node;

typedef struct Vertex {
	int name, fresh;
	Node *in;
}Vertex;

typedef struct Edge {
	int start, end;
	int fresh;
}Edge;

typedef struct Graph {
	Vertex *vertex;
	Edge *edge;
}Graph;

void init_vertex(Graph *g, int key) {
	g->vertex[key - 1].name = key;
	g->vertex[key - 1].fresh = 1;
	g->vertex[key - 1].in = (Node *)malloc(sizeof(Node));
	g->vertex[key - 1].in->point = -1;
	g->vertex[key - 1].in->edgeNum = -1;
	g->vertex[key - 1].in->next = NULL;
}

int find_edge_num(Graph *g, int pt1, int pt2, int M) {
	int i;

	for (i = 0; i<M; i++) {
		if (g->edge[i].start == pt1 && g->edge[i].end == pt2) {
			return i;
		}
	}
}

void init_list(Graph *g, int pt1, int pt2, int M) {
	Node *node1, *node2, *insert1, *insert2;
	int edgeNum;

	edgeNum = find_edge_num(g, pt1, pt2, M);

	node1 = g->vertex[pt1 - 1].in;

	insert1 = (Node *)malloc(sizeof(Node));
	insert1->edgeNum = edgeNum;
	insert1->point = pt2;
	insert1->next = NULL;

	while (node1->next != NULL && node1->next->point < pt2) {
		node1 = node1->next;
	}

	insert1->next = node1->next;
	node1->next = insert1;

	if (pt1 != pt2) {
		node2 = g->vertex[pt2 - 1].in;

		insert2 = (Node *)malloc(sizeof(Node));
		insert2->edgeNum = edgeNum;
		insert2->point = pt1;
		insert2->next = NULL;

		while (node2->next != NULL && node2->next->point < pt1) {
			node2 = node2->next;
		}

		insert2->next = node2->next;
		node2->next = insert2;
	}
}

void rDFS(Graph *g, int index) {
	Node *now;
	printf("%d\n", g->vertex[index].name);
	g->vertex[index].fresh = 0;

	now = g->vertex[index].in->next;

	while (now != NULL) {
		if (g->edge[now->edgeNum].fresh == 1) {
			g->edge[now->edgeNum].fresh = 0;
			if (g->vertex[now->point - 1].fresh == 1) {
				rDFS(g, now->point - 1);
			}
		}
		now = now->next;
	}
}

void DFS(Graph *g, int S, int N) {
	int i;

	for (i = 0; i<N; i++) {
		if (g->vertex[(i + S) % N].fresh == 1) {
			rDFS(g, (i + S) % N);
		}
	}
}

int main() {
	int N, M, S;
	int i, j, a, b, pt1, pt2;
	Graph *g = (Graph *)malloc(sizeof(Graph));

	scanf("%d %d %d", &N, &M, &S);
	g->edge = (Edge *)malloc(sizeof(Edge)*M);
	g->vertex = (Vertex *)malloc(sizeof(Vertex)*N);

	for (i = 0; i<N; i++) {
		init_vertex(g, i + 1);
	}

	for (i = 0; i<M; i++) {
		scanf("%d %d", &a, &b);
		if (a<b) {
			pt1 = a;
			pt2 = b;
		}
		else {
			pt1 = b;
			pt2 = a;
		}
		g->edge[i].fresh = 1;
		g->edge[i].start = pt1;
		g->edge[i].end = pt2;

		init_list(g, pt1, pt2, M);
	}

	DFS(g, S - 1, N);

	return 0;
}