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
int subset(listnode* small, listnode* big) {
    listnode* p = small;
    int remain,con = 1;
    while (p->next != NULL) {//작은 집합의 순회
        int found = 0;
        listnode* q = big;
        while (q != NULL) {//큰 집합이 NULL이 아닐때까지 반복
            if (p->data == q->data) {
                found ++;
            }
            else {
                if(con == 1){remain = q->data;con=0;}
            }
            q = q->next;
        }
        if (!found) {return p->data;}// big에 포함되지 않는 원소 반환
        p = p->next;
    }
    // small이 big의 부분집합인 경우
    return 0;
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
