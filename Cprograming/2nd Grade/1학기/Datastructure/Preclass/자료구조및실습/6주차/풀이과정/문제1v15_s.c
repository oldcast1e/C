#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coef;  // Coefficient of the term
    int exp;  // Exponent of the term
    struct Node* next;  // Pointer to the next term
} listnode;

void appendTerm(listnode* result, int c, int e) {
    
    listnode* new = (listnode*)malloc(sizeof(listnode));
	new->coef = c;
	new->exp = e;
	new->next = NULL;
    while (result->next != NULL) {
		result = result->next;
	}
	result->next = new;
}

// Function to add two polynomials
listnode* addPoly(listnode* list1, listnode* list2) {
    listnode* xploy = list1->next;
	listnode* ypoly = list2->next;

    listnode* rst = (listnode*)malloc(sizeof(listnode));
	rst->next = NULL;

    int sum_coef;
    while ((xploy != NULL) && (ypoly != NULL)) {// 첫 번째 다항식과 두 번째 다항식둘다 빈 노드가 아닌 경우
        if (xploy->exp > ypoly->exp) {// x에서 더 높은 지수를 갖는 항을 추가합니다.
            appendTerm(rst, xploy->coef, xploy->exp);
            xploy = xploy->next;//더 차수가 높은 항을 다음 항으로 이동
        } 
        else if (xploy->exp < ypoly->exp) {//더 낮은 지수를 사용하여 y에 항 추가
            appendTerm(rst, ypoly->coef, ypoly->exp);//더 차수가 높은 항을 다음 항으로 이동
            ypoly = ypoly->next;
        } 
        else {//항의 지수가 동일한 경우: 계수의 합을 가지는 항 추가
            sum_coef = xploy->coef + ypoly->coef;
			if ((sum_coef != 0) && (xploy->exp != 0)) //계수의 합이 0이 아니고 차수가 0이 아닌 경우
				appendTerm(rst, sum_coef, xploy->exp);
			xploy = xploy->next;
			ypoly = ypoly->next;
        }
    }

    while(xploy != NULL){
        appendTerm(rst, xploy->coef, xploy->exp);
        xploy = xploy->next;
    }
    while(ypoly != NULL){
        appendTerm(rst, ypoly->coef, ypoly->exp);
        ypoly = ypoly->next;
    }
    return rst;  // Return the resulting polynomial
}


void printNode(listnode* head) {
    listnode* p = head->next;
	while (p != NULL) {
		printf("%d %d ", p->coef, p->exp);
		p = p->next;
	}
}

int main() {
    int n,m,t_coe,t_exp;
    listnode* xlist = (listnode*)malloc(sizeof(listnode));
	xlist->next = NULL;
	listnode* ylist = (listnode*)malloc(sizeof(listnode));
	ylist->next = NULL;

    scanf("%d",&n);getchar();
    for(int i=0;i<n;i++){
        // scanf("%d %d",&t_exp,&t_coe); 
        scanf("%d", &t_exp);
		scanf("%d", &t_coe);
        appendTerm(xlist,t_exp,t_coe);
    } 

    scanf("%d",&m);getchar();
    for(int i=0;i<m;i++){
        // scanf("%d %d",&t_exp,&t_coe); 
        scanf("%d", &t_exp);
		scanf("%d", &t_coe);
        appendTerm(ylist,t_exp,t_coe);
    }


    listnode* result = addPoly(xlist, ylist);
    printNode(result);
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

2
0 7 0 0
3
0 10 0 7 0 0
*/