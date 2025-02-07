/*
[ 문제 2 ] (Kruskal 알고리즘) 입력으로 주어지는 그래프를 Kruskal 알고리즘을 이용하여
최소신장트리(Minimum Spanning Tree, MST)를 생성하는 프로그램을 작성하고,
최소신장트리의 생성 과정과 총무게를 결과로 출력하시오.
입력 그래프의 성질:
◦ 문제 1의 입력 그래프의 성질과 동일하다.
구현 조건:
◦ Kruskal 알고리즘 구현 시, 우선순위 큐와 분리집합의 구현이 필요할 수 있다. 우선순위 큐는
교재의 5장, 분리집합은 4.6절을 참조하면 된다.

입출력:
◦ 입력
- 문제 1의 입력과 동일하다.
◦ 출력
- 최소신장트리(MST) 생성 과정에서 추가되는 간선의 무게를 순서대로 출력한다.
- 모든 간선의 무게를 출력한 후, 마지막 줄에 MST 간선 비용의 합 즉, 총무게를 출력한다.
*/


#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	struct node *next;
	int u, v;
	int weight;
}node;

node *getnode() {
	node *p = NULL;
	p = (node *)malloc(sizeof(node));
	p->next = 0;
	return p;
}

void make_graph(node *p, int u, int v, int w) {
	node *tmp = p->next, *tmp_prev = p;
	node *q = getnode();
	q->u = u;
	q->v = v;
	q->weight = w;
	while (tmp != NULL&&tmp->weight<w) {
		tmp = tmp->next;
		tmp_prev = tmp_prev->next;
	}
	tmp_prev->next = q;
	q->next = tmp;
}

void print_list(node *p) {
	node *tmp = p->next;
	while (tmp != NULL) {
		printf("%d %d %d\n", tmp->u, tmp->v, tmp->weight);
		tmp = tmp->next;
	}
	printf("\n");
}

void change_setnum(int *p, int n, int ori, int x) {
	for (int i = 1; i <= n; i++) {
		if (p[i] == ori) {
			p[i] = x;
		}
	}
}

void kruskal(node *p, int n, int m) {
	node *tmp;
	node **rmp = NULL;
	rmp = (node **)malloc(sizeof(node*)*n);
	int *q = NULL;
	q = (int *)malloc(sizeof(int)*(n + 1));
	for (int i = 0; i <= n; i++) {
		q[i] = i;
	}
	int a = 0;
	tmp = p->next;
	while (tmp != NULL) {
		if (q[tmp->u] != q[tmp->v]) {
			if (q[tmp->u] < q[tmp->v]) {
				change_setnum(q, n, q[tmp->v], q[tmp->u]);
				rmp[a++] = tmp;
			}
			else {
				change_setnum(q, n, q[tmp->v], q[tmp->u]);
				rmp[a++] = tmp;
			}
		}
		tmp = tmp->next;
	}
	int sum = 0;
	for (int i = 0; i < a; i++) {
		printf(" %d", rmp[i]->weight);
		sum += rmp[i]->weight;
	}
	printf("\n%d", sum);
}

int main() {
	int n, m, w, u, v;
	scanf("%d %d", &n, &m);
	node *list = getnode();

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &w);
		make_graph(list, u, v, w);
	}
	kruskal(list, n, m);
}