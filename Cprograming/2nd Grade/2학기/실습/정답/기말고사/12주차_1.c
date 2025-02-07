/*
[ 문제 1 ] (위상순서 찾기) 주어진 방향그래프 G에 대해 다음과 같이 수행하는 프로그램을
작성하라.
1) G가 방향 비싸이클 그래프(directed acyclic graph: DAG)면 위상순서(topological
order)를 구해 인쇄.
2) G에 방향 싸이클(directed cycle)이 존재하면 위상순서를 구할 수 없으므로 0을 인쇄.
힌트:
1. 이 문제의 경우 그래프를 인접리스트 구조로 표현하는 것이 시간 성능 면에서
유리하며 배열로 구현하는 편이 코딩에 용이하다. 아래의 “알고리즘 설계 팁” 역시
이 기준으로 제공된다.
2. 위상 정렬 알고리즘에는 두 가지 버전이 있다. 첫째 깊이우선탐색(DFS)을 응용하는
버전, 둘째 각 정점의 진입차수(in-degree)를 이용하는 버전이다. 이 가운데 둘째
버전은 그래프 G가 DAG면 위상순서를 구하고 그렇지 않으면(즉, 방향싸이클이
존재하면) 일부 정점에 대해 순위를 매기지 않은 채로 정지하므로 DAG가 아님을 알
수 있다. 본 문제 해결을 위해 이 버전을 사용할 것. 상세 내용은 아래의 “알고리즘
설계 팁”을 참고할 것.
주의:
1. 방향싸이클의 존재여부 검사와 위상순서 구하기를 별도 작업으로 수행하면 전체
실행시간이 늘어나므로, 위상순서를 구하는 과정에서 방향싸이클의 존재 여부를
확인할 수 있도록 작성해야 한다.
2. 원래 어떤 그래프에 대한 위상순서는 여러 개 있을 수 있다. 하지만 채점편의 상, 이
문제는 그 가운데 단 한 개의 위상순서만 출력 가능하도록 다음 사항을 준수해야
한다. 아래의 “알고리즘 설계 팁”도 이에 맞게 작성되어 있다.
1) 그래프의 부착리스트 구축 시, 새로 입력되는 간선에 대한 노드를 리스트의 맨
앞에 삽입해야 한다(이전 실습에서는 정점번호의 오름차순으로 부착리스트 유지).
2) 위상 정렬 알고리즘에서 최초로 진입간선의 개수가 0인 정점을 찾을 때, 정점번호
순서대로 조사해야 한다.

입출력 형식:
1) main 함수는 아래 형식으로 방향그래프를 표준입력 받는다.
입력 : 첫 번째 라인 : 정점 수(n)
두 번째 라인 : 정점들의 이름(단순 문자 - 예: 영문자, 숫자 등)
세 번째 라인 : 방향간선 수(m)
이후 m개의 라인 : 방향간선 정보
2) main 함수는 다음을 표준출력한다.
출력 : 위상순서(정점들의 이름을 인쇄)
*/


#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct Edge {
	int start, end;
	int flag;
}Edge;

typedef struct Node {
	struct Node *next;
	Edge *pedge;
}Node;

typedef struct Vertex {
	char name;
	int in_n, out_n;
	Node *in_head, *out_head;

}Vertex;

typedef struct Graph {
	Vertex *vertex;
	Edge *edge;

	int v_n, e_n;
}Graph;

typedef struct Queue {
	int start, end;
	char *arr;
}Queue;

Node* getNode() {
	Node *new = (Node *)malloc(sizeof(Node));
	new->next = NULL;
	new->pedge = NULL;
	return new;
}

int search_ver_index(Graph g, char name) {

	int i;

	for (i = 0; i < g.v_n; i++) {
		if (g.vertex[i].name == name) {
			return i;
		}
	}

}

void enqueue(Queue *q, char data) {

	q->arr[q->end] = data;

	(q->end)++;
}

char deQueue(Queue *q) {
	char data = q->arr[q->start];
	(q->start)++;
	return data;
}

void printQueue(Queue q) {
	int i;

	for (i = 0; i < q.start; i++) {
		printf("%c ", q.arr[i]);
	}

}

void topologicalSort(Graph *g, Queue *q) {
	int i, index, index2;
	Node *now;

	q->arr = (char *)malloc(sizeof(char)*(g->v_n));

	for (i = 0; i < (g->v_n); i++) {

		if (g->vertex[i].in_n == 0) {

			enqueue(q, g->vertex[i].name);

		}

	}



	while (1) {

		if (q->start == q->end) {
			break;
		}

		index = search_ver_index(*g, deQueue(q));


		now = g->vertex[index].out_head;

		while (1) {

			now = now->next;

			if (now == NULL) {
				break;
			}

			index2 = search_ver_index(*g, now->pedge->end);

			(g->vertex[index2].in_n)--;

			if (g->vertex[index2].in_n == 0) {

				enqueue(q, g->vertex[index2].name);

			}

		}
	}

	if (q->start == g->v_n) {
		printQueue(*q);
	}
	else {
		printf("0");
	}
}

void createGraph(Graph *g, Queue *q) {
	int n, m;
	int i, index1, index2;
	char data, a, b;
	Node *New1, *New2, *now;

	scanf("%d", &n);
	q->arr = (char *)malloc(sizeof(char)*n);
	q->start = 0;
	q->end = 0;
	g->v_n = n;
	g->vertex = (Vertex *)malloc(sizeof(Vertex)*n);

	for (i = 0; i < n; i++) {
		getchar();

		scanf("%c", &data);

		g->vertex[i].name = data;

		g->vertex[i].in_head = getNode();

		g->vertex[i].out_head = getNode();

		g->vertex[i].in_n = 0;

		g->vertex[i].out_n = 0;

	}

	scanf("%d", &m);

	g->e_n = m;

	g->edge = (Edge *)malloc(sizeof(Edge)*m);

	for (i = 0; i < m; i++) {
		getchar();

		scanf("%c %c", &a, &b);

		g->edge[i].start = a;

		g->edge[i].end = b;

		g->edge[i].flag = 0;

		index1 = search_ver_index(*g, a);

		New1 = getNode();

		New1->pedge = &(g->edge[i]);

		New1->next = g->vertex[index1].out_head->next;

		g->vertex[index1].out_head->next = New1;

		(g->vertex[index1].out_n)++;



		New2 = getNode();

		New2->pedge = &(g->edge[i]);

		index2 = search_ver_index(*g, b);

		New2->next = g->vertex[index2].in_head->next;

		g->vertex[index2].in_head->next = New2;

		(g->vertex[index2].in_n)++;
	}
}


int main() {
	Graph g;
	Queue q;

	createGraph(&g, &q);

	topologicalSort(&g, &q);

	return 0;
}