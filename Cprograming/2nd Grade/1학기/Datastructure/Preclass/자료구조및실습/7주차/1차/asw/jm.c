#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct listnodede {
	int data;
	struct listnodede* next;
}listnode;

void add(listnode* list, int data, int r) {
	listnode* new = (listnode*)malloc(sizeof(listnode));
	new->data = data;
	new->next = NULL;
	listnode* p = list;
	if(r==0){
		p->data = data;
	}
	else{
	for (int i = 1; i < r; i++) {
		p = p->next;
	}
	p->next = new;
	}
}

void print(listnode* list) {
	listnode* p = list;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int subset(listnode* A,listnode* B,int as){
	listnode* pa = A;
	listnode* pb = B;
	int cnt = 0;
	
	while ((pa != NULL) && (pb != NULL)) {
		if (pa->data == pb->data) {
			pa = pa->next;
			pb = pb->next;
			cnt++;
		}
		else {
			pb = pb->next;
		}
	}
	
	if (as != cnt) {
		return pa->data;
	}
	else return 0;
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
	for (int i = 0; i < as; i++)
	{
		int data;
		scanf("%d", &data);
		add(A, data, i);
	}
	//print(A);
	getchar();
	scanf("%d", &bs);
	getchar();
	for (int i = 0; i < bs; i++)
	{
		int data;
		scanf("%d", &data);
		add(B, data, i);
	}
	//print(B);

	int res = subset(A, B, as);
	printf("%d", res);

	return 0;
}