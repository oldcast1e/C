/*
주의:
1) 프로그램 작성 시 사용 데이터구조의 간편성과 효율성은 모두 중요하다. 이 점에서 문제해결을
위해 사용한 데이터구조가 최선의 선택인지 여부는 채점 시 평가에 고려될 수 있다.
2) 예를 들어 그래프 알고리즘 구현 시, 그래프의 인접 정보(즉, 부착간선리스트 또는 인접행렬)
없이도 수행 가능한 문제라고 판단되면 교재 13.4절의 간선리스트 구조로 그래프를 간편하게
구현할 것을 우선적으로 고려하라. 그렇지 않고, 인접 정보가 있어야 수행한다고 판단되면
인접리스트 구조 또는 인접행렬 구조 중에 해당 문제 해결에 효율성 면에서 유리하다고
판단되는 것을 선택하여 구현하라.
[ 문제 1 ] (Prim-Jarnik 알고리즘) 입력으로 주어지는 그래프를 Prim-Jarnik 알고리즘을 이용하여
최소신장트리(Minimum Spanning Tree, MST)를 생성하는 프로그램을 작성하고,
최소신장트리의 생성 과정과 총무게를 결과로 출력하시오.
입력 그래프의 성질:
◦ n (1 ≤ n ≤ 100) 개의 정점과 m (1 ≤ m ≤ 1,000) 개의 간선으로 구성된다.
◦ 정점은 1 ~ n 사이의 정수로 번호가 매겨져 있고, 정점의 번호는 모두 다르다.
◦ 모든 간선은 무방향간선이고, 한 정점에서 임의의 다른 정점으로 가는 경로는 반드시
존재한다.
◦ 간선의 무게는 중복이 없는 양의 정수다.
주의:
◦ 알고리즘 수행의 출발정점은 번호가 가장 빠른 정점인 1부터 시작한다.
- Prim-Jarnik 알고리즘의 첫 출발정점은 그래프 내 아무 정점이라도 무방하지만, 이번
실습에서는 번호가 가장 빠른 정점인 1에서 출발해야 OJ 시스템의 정답과 일치시킬 수
있다.
입출력:
◦ 입력
- 첫 줄에 정점의 개수 n, 간선의 개수 m이 주어진다.
- 이후 m개의 줄에 한 줄에 하나씩 간선의 정보(간선의 양끝 정점 번호와 무게)가 주어진다.
간선은 임의의 순서로 입력되고, 중복 입력되는 간선은 없다.
(무방향간선이므로 간선 (u, v)와 (v, u)는 동일한 간선으로 취급)
- 무게로는 양의 정수가 입력되고, 중복되는 무게는 없다.
◦ 출력
- 모든 정점의 번호를 출력한 후, 마지막 줄에 MST 간선 무게의 합 즉, 총무게를 출력한다.

*/


#pragma warning(disable:4996)
#define MAX 2147483647
#include<stdio.h>
#include<stdlib.h>
//prim_jarnik 하려면 visit 배열 하나 만들고
//거기서 방문하지 않은 정점에서 거리를 바꿔줘야함

typedef struct node {
	struct node *next;
	int elem;
	int weight;
}node;

node *getnode() {
	node *p = NULL;
	p = (node *)malloc(sizeof(node));
	p->next = NULL;
	return p;
}

typedef struct vertex {
	node *arr;
	int elem;
	int distance;
}vertex;

vertex *getvertex(int i) {
	vertex *p = NULL;
	p = (vertex *)malloc(sizeof(vertex));
	p->arr = getnode();
	p->elem = i;
	p->distance = MAX;
	return p;
}

void make_graph(vertex *u, vertex *v, int w) {
	node *tmp = u->arr->next, *tmp_prev = u->arr;
	node *q = getnode();
	q->elem = v->elem;
	q->weight = w;
	while (tmp != NULL&&tmp->elem < v->elem) {
		tmp = tmp->next;
		tmp_prev = tmp_prev->next;
	}
	tmp_prev->next = q;
	q->next = tmp;
}

void print_graph(vertex **p, int n) {
	node *tmp = p[0]->arr->next;
	for (int i = 0; i < n; i++) {
		tmp = p[i]->arr->next;
		while (tmp != NULL) {
			printf("e %d w %d //", tmp->elem, tmp->weight);
			tmp = tmp->next;
		}
		printf("\n");
	}
}

int min_vertex(int *visit, int n, vertex **p) {
	int *tmp = NULL;
	int a = 0;
	tmp = (int *)malloc(sizeof(int)*n);
	int min;
	for (int i = 1; i <= n; i++) {
		if (visit[i] == 0) {
			tmp[a++] = i;
		}
	}
	int k;
	min = tmp[0] - 1;
	for (int i = 1; i < a; i++) {
		k = tmp[i] - 1;
		if (p[k]->distance < p[min]->distance) {
			min = k;
		}
	}
	return min;// distance가 가장 작은 정점의 index 반환
}

void prim(vertex **p, int n) {
	int *visit = NULL;
	int cnt = 0;
	int u;
	node *e;
	visit = (int *)malloc(sizeof(int)*(n + 1));
	for (int i = 0; i <= n; i++) {
		visit[i] = 0;
	}
	p[0]->distance = 0;
	while (cnt < n) {
		u = min_vertex(visit, n, p);
		visit[u + 1] = 1;
		printf(" %d", u + 1);
		cnt++;
		for (node *e = p[u]->arr->next; e != NULL; e = e->next) {
			if (visit[e->elem] == 0 && p[e->elem - 1]->distance > e->weight) {
				p[e->elem - 1]->distance = e->weight;
			}
		}
	}
}

int main() {
	int n, m, u, v, w;
	scanf("%d %d", &n, &m);
	vertex **p = NULL;
	p = (vertex **)malloc(sizeof(vertex)*n);
	for (int i = 0; i < n; i++) {
		p[i] = getvertex(i + 1);
	}
	for (int i = 0; i < m; i++) {// 간선받기
		scanf("%d %d %d", &u, &v, &w);
		make_graph(p[u - 1], p[v - 1], w);
		if (u != v) {
			make_graph(p[v - 1], p[u - 1], w);
		}
	}
	prim(p, n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += p[i]->distance;
	}
	printf("\n%d", sum);
}