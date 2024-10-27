#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node* next;
	int data;
}node;

typedef struct tmp {
	node* L1;
	node* L2;
}tmp;

void addList(node** L, int data);
void mergeSort(node** L, int size);
tmp partition(node*L, int key);
node* merge(node* L1, node*L2);
void printheap(node* L);


void main()
{
	int n;
	scanf("%d", &n);
	node* head = NULL;
	for (int i = 0; i < n; i++) {
		int key;
		scanf("%d", &key);
		addList(&head, key);
	}
	//printheap(n, head);
	mergeSort(&head, n);
	printheap(head);
	return 0;
}

void addList(node** L, int data) {
	node* new;
	new = (node*)malloc(sizeof(node));
	new->data = data;
	new->next = NULL;
	if (*L == NULL) *L = new;
	else {
		node* p = *L;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = new;
	}
}

void mergeSort(node** L, int size) {
	node* L1=NULL;
	node*L2=NULL;
	tmp split;
	node* p = *L;
	if (p != NULL && size > 1) { //size> 1 !!!
		split = partition(*L, size / 2); // p 까먹지 말기!!!
		L1=split.L1;
		L2=split.L2;

		mergeSort(&L1, size / 2);
		mergeSort(&L2, (int)(size / 2.0+0.5));

		*L = merge(L1, L2);
	}

}
tmp partition(node*L, int key) {
	node* L1;
	node* L2;
	tmp split;
	node* p = L;
	L1 = p;
	for (int i = 0; i < key - 1; i++) {
		p = p->next;
	}
	L2 = p->next;
	p->next = NULL;
	split.L1 = L1;
	split.L2 = L2;

	return split;
}

node* merge(node* L1, node*L2) {
	node* p;
	p = NULL;
	if (L1 == NULL) return L2;
	else if (L2 == NULL) return L1;

	if (L1->data < L2->data) {
		p = L1;
		p->next = merge(L1->next, L2);
	}
	else {
		p = L2;
		p->next = merge(L1, L2->next);
	}

	return p;
}


void printheap( node* L)
{
	node* p = L;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}