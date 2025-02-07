/*
[ 문제 1 ] (분리연쇄법 해시테이블) 크기 M인 해시테이블에 여러 개의 키 값을 입력받아
저장하고, 분리연쇄법을 이용하여 충돌을 처리하는 해시테이블 프로그램을 작성하시오.

◦ 구현 조건
- 해시테이블은 크기가 M인 배열로 동적 할당한다.
- 입력 키는 중복이 없는 자연수다.
- 키 x에 대한 해시함수 h(x) = x % M 을 사용한다.
- 삽입 시 충돌이 발생하는 경우, 해당 버켓 리스트의 맨 앞에 삽입한다.
◦ 입력
- 해시테이블의 크기 M을 입력받는다.
- 삽입(i), 탐색(s), 삭제(d), 인쇄(p) 명령어를 순서에 상관없이 반복하여 입력받는다.
i <x> : 키 x를 해시테이블에 삽입
s <x> : 키 x가 해시테이블에 존재하는지 탐색
d <x> : 키 x가 해시테이블에 존재하면 삭제
p : 해시테이블에 저장된 키들을 순서대로 인쇄(입출력 예시 참조)
e : 프로그램 종료
◦ 출력
- 키를 삽입하였을 때 아무 출력을 하지 않는다.
- 탐색 또는 삭제할 때, 키가 존재하면 리스트에서 해당 키가 저장된 순위(1부터 시작)를
인쇄하고 없다면 0을 인쇄한다(해시테이블의 주소가 아닌 리스트에서의 순위를 인쇄함에
유의).
- 해시테이블을 인쇄할 때, 0번 주소부터 마지막 주소까지 순회하면서 저장된 키들을
방문하는 순으로 인쇄한다.
*/

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	int key;
	struct node* next;
}node;

void getnode(node **p, int k) {
	(*p) = (node*)malloc(sizeof(node));
	(*p)->key = k;
	(*p)->next = NULL;
}

void addlink(node* h, node* p) {
	if (h->next == NULL) h->next = p;
	else {
		p->next = h->next;
		h->next = p;
	}
}

void insert(node**h, int k, int m) {
	int idx = k % m;
	node* p; getnode(&p, k);
	addlink(h[idx], p);
}

void select(node** h,int k,int m) {
	int idx = k % m;
	if (h[idx]->next == NULL) {
		printf("0\n"); return;
	}
	node * p = h[idx]->next;
	int cnt = 1;
	while (1)
	{
		if (p == NULL) {
			printf("0\n"); return;
		}
		if (p->key == k) {
			printf("%d", cnt);
			return;
		}
		cnt++;
		p = p->next;
	}
}

void dellink(node* tmp, node* before) {
	if (tmp->next == NULL) before->next = NULL;
	before->next = tmp->next;
	free(tmp);
}

void del(node**h, int k, int m) {
	int idx = k % m;
	if (h[idx]->next == NULL) {
		printf("0\n"); return;
	}
	node * tmp = h[idx]->next;
	node * before = h[idx];
	int cnt = 1;
	while (1) {
		if (tmp == NULL) {
			printf("0\n"); return;
		}
		if (tmp->key == k) {
			dellink(tmp, before);
			printf("%d", cnt); return;
		}
		cnt++;
		tmp = tmp->next;
		before = before->next;
	}
	printf("\n");
}

void print(node** h, int m) {
	for (int i = 0; i < m; i++) {
		if (h[i]->next != NULL) {
			node* p = h[i]->next;
			while (1) {
				if (p == NULL) break;
				printf(" %d", p->key);

				p = p->next;
			}
		}
	}
	printf("\n");
}

int main()
{
	int **h, m, k;
	char or ;
	scanf("%d", &m);
	getchar();
	h = (node**)malloc(sizeof(node*)*m);
	for (int i = 0; i < m; i++) {
		getnode(&h[i], i);
	}
	while (1) {
		scanf("%c", &or );
		if (or=='i') {
			scanf("%d", &k); getchar();
			insert(h, k, m);
		}else if (or=='s') {
			scanf("%d", &k); getchar();
			select(h, k, m);
		}else if (or=='d') {
			scanf("%d", &k); getchar();
			del(h, k, m);
		}else if (or=='p') {
			print(h, m);
		}
		else if (or =='e') break;
	}
}