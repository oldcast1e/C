#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

typedef char element;

typedef struct ListNode {
	element data;
	struct ListNode *next;
}ListNode;

void Initialize(){

     /*노드를 메모리 동적 할당으로 생성하기*/
    ListNode* head = (ListNode*)malloc(sizeof(ListNode)); //헤드 노드 생성
    head->next = NULL;

    ListNode* ListNode1 = (ListNode*)malloc(sizeof(ListNode)); //node1 이라는 새로운 노드를 새로 할당
    ListNode1->next = head->next;//node1의 꼬리를 (기존)헤드의 꼬리로 연결
    head->next = ListNode1;
    ListNode1->data = 'A';//node1의 데이터 업데이드

    ListNode* ListNode2 = (ListNode*)malloc(sizeof(ListNode)); //node1 이라는 새로운 노드를 새로 할당
    ListNode1->next = ListNode2;//node1의 꼬리를 (기존)헤드의 꼬리로 연결
    ListNode2->data = 'B';//node1의 데이터 업데이드

    ListNode* ListNode3 = (ListNode*)malloc(sizeof(ListNode)); //node1 이라는 새로운 노드를 새로 할당
    ListNode2->next =ListNode3;//node1의 꼬리를 (기존)헤드의 꼬리로 연결
    ListNode3->data = 'D';//node1의 데이터 업데이드
}

ListNode* Insert(ListNode *new){
    ListNode* curr = head->next; 
	while(curr->next != NULL){ //연결리스트 출력
        if((curr->next)->data > new->data){
            new->next = curr->next;
            curr->next = new;

            break;
        }
		// printf(">> %c\n", curr->data);
		curr = curr->next;
	}
    
    return head;
}


int main(){
   
    
    ListNode* new = (ListNode*)malloc(sizeof(ListNode)); //헤드 노드 생성
    new->data = 'C';
    Insert(new);

    /*순회용 노드*/
    ListNode* curr = head->next; 
	while(curr != NULL){ //연결리스트 출력
		printf("%c\n", curr->data);
		curr = curr->next;
	}

    free(head);
	free(ListNode1);
	return 0;
}