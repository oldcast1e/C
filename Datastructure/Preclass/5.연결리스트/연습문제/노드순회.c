#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

/*연결 리스트를 구현할 구조체*/
typedef struct ListNode{
    int data;
    struct ListNode* next;//자가 참조 구조체
    /*다음 노드의 주소를 저장할 자기참조 구조체포인터*/
}ListNode;
int main(){
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	ListNode* curr = head->next; //순회용 노드 생성
	while(curr != NULL){
		printf("%d\n", curr->data);
		curr = curr->next;
	}
}
