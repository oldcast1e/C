#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode *next;
    struct ListNode *pre;
}ListNode;

ListNode* add(ListNode *head, int rank, int value){//구조체 함수
    /*list의 순위 r에 원소 e를 추가해야함으로 순위r까지 반복한 후 해당 위치에 원소 e를 추가하도록한다.*/
    int cnt = 0;
    ListNode* check = head->next; //순회용 노드 생성
    while(check != NULL){
	    cnt ++;
	    check = check->next;
    }free(check);

    printf("cnt = %d\n",cnt);

    if(cnt < rank) {printf("invalid position");return 0;}
    else{
        ListNode* curr = head; //순회용 노드 생성
        for(int i=0;i<rank;i++) curr = curr->next;
        //위 반복문을  통해 이미 순위가 r인 노드까지 이동함.(ㄱ)
        ListNode *p =(ListNode *)malloc(sizeof(ListNode));//추가할 노드를 동적할당한다.

        p->data = value;
        (curr->pre)->next = p;
        p->next = curr;
       
        printf("랭크 %d의 추가된 노드의 데이터는 %d입니다.\n",rank,p->data);
        // return head; //다음 노드의 위치를 반환함.
    }
    
    return head;
}

int main(){
    /*노드를 메모리 동적 할당으로 생성하기*/
    ListNode* head = (ListNode*)malloc(sizeof(ListNode)); //헤드 노드 생성
    head->next = NULL;    

    ListNode* NewNode[100];
    for(int i=0;i<100;i++) NewNode[i] = (ListNode*)malloc(sizeof(ListNode));
    head->next = NewNode[0];
    // NewNode[0] ->data = 10;//node1의 데이터 업데이드

    for(int i=0;i<9;i++) NewNode[i]->next = NewNode[i+1];
    for(int i=1;i<9;i++) NewNode[i+1]->pre = NewNode[i];
    for(int i=0;i<10;i++) NewNode[i]->data = (i+1);
    NewNode[9]->next = NULL;
   
    add(head,5,150);

    ListNode* curr = head->next; //순회용 노드 생성
	while(curr != NULL){ //연결리스트 출력
		printf("%d\n", curr->data);
		curr = curr->next;
	}

    free(head);
	return 0;
}