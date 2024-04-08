#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

typedef char element;

typedef struct ListNode {
	element data;
	struct ListNode *next;
}ListNode;

void Initialize(){
    ListNode* head = (ListNode*)malloc(sizeof(ListNode)); //헤드 노드 생성
    head->next = NULL;

    ListNode* NodeArr[6];
    for(int i=0;i<6;i++) NodeArr[i] = (ListNode*)malloc(sizeof(ListNode));
   
    for(int i=0;i<5;i++){    
        if(i==0) head->next = NodeArr[0];
        else NodeArr[i-1]->next = NodeArr[i];//node1의 꼬리를 (기존)헤드의 꼬리로 연결
        NodeArr[i]->data = 'A'+ i;      
    }   
    NodeArr[5]->next = NULL;
}

void Print(ListNode *head){
    ListNode* cnt = head->next; 
    // printf("연결리스트의 함수 실행 후"); 
	while(cnt != NULL){ //연결리스트 출력
		printf("%c ", cnt->data);
		cnt = cnt->next;
	}printf("\n");
}



int main(){
    /*노드를 메모리 동적 할당으로 생성하기*/
    

    /*순회용 노드*/
    ListNode* cnt = head->next;
    printf("[기본 연결리스트의 값] "); 
	while(cnt != NULL){ //연결리스트 출력
		printf("%c ", cnt->data);
		cnt = cnt->next;
	}printf("\n");

    ListNode* new = (ListNode*)malloc(sizeof(ListNode)); //node1 이라는 새로운 노드를 새로 할당
    new->data = 'C';
    Delete(new);
    // Insert(head,new);
    free(head);
	return 0;
}