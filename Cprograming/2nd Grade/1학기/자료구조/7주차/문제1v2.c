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
    //연결리스트에 값을 추가하는 함수 : 맨 뒤부터 입력해야함.
    listnode* new = (listnode*)malloc(sizeof(listnode));
    new ->data = val;

    if(list == NULL) list->data = val;
    else{
        listnode* p = list;
	    while (p->next != NULL) {p = p->next;}
        //p가 맨 마지막 노드에 도달할 때까지 순회
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
int subset(listnode* small,listnode* big){
    printf("<<subset size:%d>>\n",big->size);
    // printf("B : ");print(big);
    // printf("A : ");print(small);
    int cnt = 0, status = 1, rtv;

    for(int i=0;i<big->size;i++){
        printf("B[%d] A[%d]\n",small->data,small->data);
        if(big->data == small->data){
            cnt ++; 
            small = small->next;
            // printf("Same\n");
        }
        else {
            if(status){
                rtv = small->data;
                status = 0;
            }
        }
        big = big->next;
    }
    if(cnt == small->size) return 0;
    else return rtv;    
}
/**
출력: A ⊂ B이면 0을 출력하고, 
그렇지 않으면 집합 B에 속하지 않은 집합 A의 가장 작은 원 소를 표준 출력한다.
 */
int main(){
    //순환문이용
    int N,M,num,tmp,result;//N: 집합 A의 크기,M: 집합 B의 크기
    listnode* list_A = (listnode*)malloc(sizeof(listnode));
	list_A->next = NULL;
	listnode* list_B = (listnode*)malloc(sizeof(listnode));
	list_B->next = NULL;
    
    scanf("%d",&N); for(int i=0;i<N;i++){scanf("%d",&tmp);add(list_A,tmp);} //print(list_A);
    scanf("%d",&M); for(int i=0;i<M;i++){scanf("%d",&tmp);add(list_B,tmp);} //print(list_B);

    if(list_A->size > list_B->size){ result  = subset(list_B,list_A);}
    if(list_A->size < list_B->size){result  = subset(list_A,list_B);}

    // printf("%d",result);
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
