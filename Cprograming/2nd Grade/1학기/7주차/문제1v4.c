#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {
	int data;
    int size;
	struct node* next;
}listnode;

void print(listnode* list) {
	listnode* p = list;
    // printf(">>");
	while (p->next!= NULL) {
		printf(" %d", p->data);
		p = p->next;
	}
    printf("\n");
}

void add(listnode* list,int val) {
	
	listnode* new = (listnode*)malloc(sizeof(listnode));
    listnode* p  = list;
	new->next = NULL;
	new->data = val;
	
    if(list->size == 0){ //printf("+"); 
        list =new;}
    else{
        while (p->next != NULL) {
		    p = p->next;
	    }
	    p->next = new;
    }
    list->size ++;
}
/*
다음 함수를 작성하여 사용하시오.
◦ 함수 subset : 집합 A가 집합 B의 부분집합인지 여부 검사
- 인자: 양의 정수 집합 A, B (A, B는 각각 단일연결리스트의 헤드 노드)
- 반환값: 정수 (A ⊂ B면 0, 그렇지 않으면 집합 B에 속하지 않은 집합 A의 가장 작은 원
소)
*/
int subset(listnode* A, listnode* B) {
    //집합 B가 집합 A보다 크다고 설정한다.
    int len_A = A->size;
    
}
/**
출력: A ⊂ B이면 0을 출력하고, 
그렇지 않으면 집합 B에 속하지 않은 집합 A의 가장 작은 원 소를 표준 출력한다.
 */
int main(){
    //순환문이용
    int N,M,num,tmp;
    listnode* list_A = (listnode*)malloc(sizeof(listnode));
	list_A->next = NULL; list_A->size = 0;
	listnode* list_B = (listnode*)malloc(sizeof(listnode));
	list_B->next = NULL; list_B->size = 0;

    scanf("%d",&N);//list_A->size = N;
    for(int i=0;i<N;i++){scanf("%d",&num); if(i==0)tmp =num; add(list_A,num);}
    scanf("%d",&M);//list_B->size = M;
    for(int i=0;i<M;i++){scanf("%d",&num); add(list_B,num);}

    print(list_A);print(list_B);
    // if(list_A->size > list_B->size){ result  = subset(list_B,list_A);}
    // if(list_A->size < list_B->size){result  = subset(list_A,list_B);}

    printf("%d %d",list_A->size,list_B->size);
    //집합 A가 집합 B보다 원소의 개수가 많은 경우
    // listnode* result = subset(list_A,list_B);

} 
/*
0
3
9 20 77

3
4 6 13
6
1 3 4 6 8 13

3
7 10 53
4
7 10 15 45


0
3
9 20 77

3
9 20 77
0


*/
