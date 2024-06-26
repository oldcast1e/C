#include <stdio.h>
#include <stdlib.h>

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
		if (fir->exp > sec->exp) {
			appendTerm(rst, fir->coef, fir->exp);
			fir = fir->next;
		}
		else if (fir->exp < sec->exp) {
			appendTerm(rst, sec->coef, sec->exp);
			sec = sec->next;
		}
		else {
			sum_coef = sec->coef + fir->coef;
			if ((sum_coef != 0) && (fir->exp != 0)) //계수의 합이 0이 아니고 차수가 0이 아닌 경우
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

int main(){

	listnode* list1 = (listnode*)malloc(sizeof(listnode));
	list1->next = NULL;
	listnode* list2 = (listnode*)malloc(sizeof(listnode));
	list2->next = NULL;


	int c, e,N,M;
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

}