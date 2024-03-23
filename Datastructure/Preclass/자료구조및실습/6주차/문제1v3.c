#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    //연결리스트 본체: 가지고 있는 데이터 값과 전/후방 연결위치 저장
	int coe; //항의 계수
    int exp; // 항의 차수
	struct Node* next; //다음 노드를 가리키는 링크

}Listnode;

typedef struct list {
    //리스트의 정보 :  리스트의 헤드노드와 테일 노드의 설정 구조체
	int size;
	Listnode* head;
}list_info;
/*

◦ 하나의 연결리스트의 각 노드는 차수의 내림차순 순으로 유지하고,
  계수가 0인 항의 노드는 유지하지 않음
*/

void appendTerm(list_info* list,int N_coe,int N_exp){
    //항의 계수:coe       제곱수:exp
	Listnode* curr = list->head;
	for (int i = 0; i < list->size ; i++) {
		curr = curr->next;
	}
	
	Listnode* new = (Listnode*)malloc(sizeof(Listnode)); //새로 추가할 노드
	
    new->coe = N_coe;	new->exp = N_exp;
	curr->next = new; new->next = NULL;
	list->size++;

	// printf("계수[%d] ^ 제곱수[%d]\n",new->coe,new->exp);
	
}

// }
void print(list_info* list) {
    // printf("loading...\n");
	Listnode* p = list->head->next;
	while (p != NULL) { 
		// printf("%d ", p->coe);
		printf("%dx^%d", p->coe,p->exp);
		if(p->next != NULL) printf(" + ");
		p = p->next;
	}
	printf("\n");
}



int main()
{
	list_info* xlist = (list_info*)malloc(sizeof(list_info));
	xlist->head = (Listnode*)malloc(sizeof(Listnode));
	xlist->head->next = NULL;
	xlist->size = 0;

	list_info* ylist = (list_info*)malloc(sizeof(list_info));
	ylist->head = (Listnode*)malloc(sizeof(Listnode));
	ylist->head->next = NULL;
	ylist->size = 0;


	int n,m,t_coe,t_exp,coe,exp;
	scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&t_exp,&t_coe);
		appendTerm(xlist,t_exp,t_coe);
    } 
	

	scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&t_exp,&t_coe);
		appendTerm(ylist,t_exp,t_coe);
    }
	print(xlist); 
	print(ylist);


    


}
/*
3
5 3 3 2 3 1
3
2 6 2 3 1 0

*/