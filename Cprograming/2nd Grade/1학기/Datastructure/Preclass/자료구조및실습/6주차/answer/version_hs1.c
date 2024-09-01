#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	int coef;
	int exp;
	struct node* next;
}listnode;


void appendTerm(listnode* list,int c,int e) {
	
	listnode* new = (listnode*)malloc(sizeof(listnode));
	new->coef = c;
	new->exp = e;
	new->next = NULL;
	
	while (list->next != NULL) {
		list = list->next;
	}
	list->next = new;

}

void print(listnode* list) {
	listnode* p = list->next;
	while (p != NULL) {
		printf("%d %d ", p->coef, p->exp);
		p = p->next;
	}
}

listnode* addPoly(listnode* list1, listnode* list2) {
	listnode* fir = list1->next;
	listnode* sec = list2->next;

	listnode* rst = (listnode*)malloc(sizeof(listnode));
	rst->next = NULL;

	int sum_coef;
	while ((fir != NULL) && (sec != NULL)) {
		//fir>sec
		if (fir->exp > sec->exp) {
			appendTerm(rst, fir->coef, fir->exp);
			fir = fir->next;
		}
		//sec>fir
		else if (fir->exp < sec->exp) {
			appendTerm(rst, sec->coef, sec->exp);
			sec = sec->next;
		}
		//fir==sec
		else {
			sum_coef = sec->coef + fir->coef;
			if ((sum_coef != 0) && (fir->exp != 0)) 
				appendTerm(rst, sum_coef, fir->exp);
			fir = fir->next;
			sec = sec->next;
			
		}
	}

	while (fir != NULL) {
		appendTerm(rst, fir->coef, fir->exp);
		fir = fir->next;
	}
	while (sec != NULL) {
		appendTerm(rst, sec->coef, sec->exp);
		sec = sec->next;
	}
	return rst;
}

int main()
{

	listnode* list1 = (listnode*)malloc(sizeof(listnode));
	list1->next = NULL;
	listnode* list2 = (listnode*)malloc(sizeof(listnode));
	list2->next = NULL;


	int c, e;
	int N,M;
	scanf("%d", &N);getchar();
	for (int i = 0; i < N; i++) {
		scanf("%d", &c);
		scanf("%d", &e);
		appendTerm(list1, c, e);
	}
	scanf("%d", &M);getchar();
	for (int i = 0; i < M; i++) {
		scanf("%d", &c);
		scanf("%d", &e);
		appendTerm(list2, c, e);
	}

	listnode* rst;
	rst = addPoly(list1, list2);
	print(rst);

	return 0;
}
/*
3
5 3 3 2 3 1
3
2 6 2 3 1 0

>>2 6 7 3 3 2 3 1 1 0 

2
2 7 3 0
3
-3 10 3 7 -3 0

>>-3 10 5 7
*/