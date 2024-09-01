#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	int data;
	struct node* next;
}node;

void add(node* head, int data,int n) {
	node* new = (node*)malloc(sizeof(node));
	new->next = NULL;
	new->data = data;
	node* p = head;
	for (int i = 0; i < n; i++) {
		p = p->next;
	}
	p->next = new;
}

node* union_f(node* h,node* h2) {
	node* uh = (node*)malloc(sizeof(node));
	uh->next = NULL;
	int cnt = 0;
	node* p1 = h->next;
	node* p2 = h2->next;
	while ((p1 != NULL) && (p2 != NULL)) {
		if (p1->data < p2->data) {
			add(uh, p1->data, cnt);
			cnt++;
			p1 = p1->next;
		}else if (p1->data > p2->data) {
			add(uh, p2->data, cnt);
			cnt++;
			p2 = p2->next;
		}
		else if (p1->data == p2->data) {
			add(uh, p1->data, cnt);
			cnt++;
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	while (p1 != NULL) {
		add(uh, p1->data, cnt);
		cnt++;
		p1 = p1->next;
	}
	while (p2 != NULL) {
		add(uh, p2->data, cnt);
		cnt++;
		p2 = p2->next;
	}
	return uh;
}

node* inter_f(node* h, node* h2) {
	node* uh = (node*)malloc(sizeof(node));
	uh->next = NULL;
	int cnt = 0;
	node* p1 = h->next;
	node* p2 = h2->next;
	while ((p1 != NULL) && (p2 != NULL)) {
		if (p1->data < p2->data) {
			
			p1 = p1->next;
		}
		else if (p1->data > p2->data) {
			
			p2 = p2->next;
		}
		else if (p1->data == p2->data) {
			add(uh, p1->data, cnt);
			cnt++;
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	
	return uh;
}


void print(node* head) {
	node* p = head->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	node* head = (node*)malloc(sizeof(node));
	head->next = NULL;
	node* head2 = (node*)malloc(sizeof(node));
	head2->next = NULL;
	int N, M;
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		getchar();
		int data;
		scanf("%d", &data);
		add(head, data, i);
	}
	//print(head);

	getchar();
	scanf("%d", &M);
	
	for (int i = 0; i < M; i++) {
		getchar();
		int data;
		scanf("%d", &data);
		add(head2, data, i);
	}
	//print(head2);

	if ((N == 0) && (M == 0)) {
		printf("0\n0");
	}
	else if (N == 0) {
		print(head2);
		printf("0");
	}
	else if(M == 0) {
		print(head);
		printf("0");
	}
	else {
		node* uni = union_f(head, head2);
		print(uni);
		node* in = inter_f(head, head2);
		print(in);
	}
	

	return 0;
}