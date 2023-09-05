#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode *next;
}ListNode;

ListNode* plus(ListNode *head, int value){
    ListNode *p=(ListNode *)malloc(sizeof(ListNode));

    p->data=value;
    p->next=pre->next;
    pre->next=p;

    return head;
}

int main(){
    /*노드를 메모리 동적 할당으로 생성하기*/
    ListNode* head = (ListNode*)malloc(sizeof(ListNode)); //헤드 노드 생성
    head->next = NULL;
    ListNode* ListNode1 = (ListNode*)malloc(sizeof(ListNode)); //node1 이라는 새로운 노드를 새로 할당
    

    /*머리노드와 node1을 연결하기*/
    ListNode1->next = head->next;//node1의 꼬리를 (기존)헤드의 꼬리로 연결
    ListNode1->data = 10;//node1의 데이터 업데이드
    head->next = ListNode1;//헤드의 꼬리를 node1으로 업데이트

    ListNode* curr = head->next; //순회용 노드 생성
	while(curr != NULL){ //연결리스트 출력
		printf("%d\n", curr->data);
		curr = curr->next;
	}

    free(head);
	free(ListNode1);
	return 0;
}