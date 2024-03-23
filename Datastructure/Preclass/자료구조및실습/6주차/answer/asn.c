#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	int data;
	int exp;
	struct node* next;
}listnode;

void add(listnode* list, int r,int data,int exp) {
	listnode* p = list;
	for (int i = 0; i < r; i++) {
		p = p->next;
	}
	listnode* new = (listnode*)malloc(sizeof(listnode));
	new->data = data;
	new->exp = exp;
	new->next = NULL;

	p->next = new;
}

void print(listnode* list) {
	listnode* p = list->next;
	while (p!=NULL) {
		printf(" %d %d", p->data, p->exp);
		p = p->next;
	}
	printf("\n");
}

listnode* sum(listnode* a, listnode* b) {
	listnode* pa = (listnode*)malloc(sizeof(listnode));
	listnode* pb = (listnode*)malloc(sizeof(listnode));
	pa = a->next;
	pb = b->next;
	listnode* res = (listnode*)malloc(sizeof(listnode));
	res->next = NULL;
	int cnt = 0;

	while ((pa != NULL) && (pb != NULL)) {
		if (pa->exp > pb->exp) {
			add(res, cnt, pa->data, pa->exp);
			pa = pa->next;
			cnt++;
		}
		else if (pb->exp > pa->exp) {
			add(res, cnt, pb->data, pb->exp);
			pb = pb->next;
			cnt++;
		}
		else if (pa->exp == pb->exp) {
			int abs = pa->data + pb->data;
			if (abs != 0) {
				add(res, cnt, abs, pa->exp);
				cnt++;
			}
			pa = pa->next;
			pb = pb->next;

		}
	}
		while (pa != NULL) {
			add(res, cnt, pa->data, pa->exp);
			cnt++;
			pa = pa->next;
		}
		while (pb != NULL) {
			add(res, cnt, pb->data, pb->exp);
			cnt++;
			pb = pb->next;
		}
		return res;
	
}

int main()
{
	listnode* A = (listnode*)malloc(sizeof(listnode));
	listnode* B = (listnode*)malloc(sizeof(listnode));
	A->next = NULL;
	B->next = NULL;

	int as, bs;
	scanf("%d", &as);
	getchar();
	for (int i = 0; i < as; i++) {
		int data, exp;
		scanf("%d %d", &data, &exp);
		add(A, i, data, exp);
	}
	//print(A);
	getchar();
	scanf("%d", &bs);
	getchar();
	for (int i = 0; i < bs; i++) {
		int data, exp;
		scanf("%d %d", &data, &exp);
		add(B, i, data, exp);
	}

	listnode* res = sum(A, B);
	print(res);
	return 0;
}