#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

typedef char element;

typedef struct ListNode {
	element data;
	struct ListNode *next;
}ListNode;

void Initialize(ListNode *head){
    ListNode* NodeArr[3];
    for(int i=0;i<3;i++) NodeArr[i] = (ListNode*)malloc(sizeof(ListNode));
   
    for(int i=0;i<3;i++){    
        if(i==0) head->next = NodeArr[0];
        else NodeArr[i-1]->next = NodeArr[i];//node1의 꼬리를 (기존)헤드의 꼬리로 연결
        NodeArr[i]->data = 'A'+ i;
        // if(i!=2)NodeArr[i]->data = 'A'+ i;
        // else  NodeArr[i]->data = 'A'+ i + 1;       
    }   
}
ListNode* Plus(ListNode *head, char value){
    ListNode* curr = head->next; 
	while(curr->next != NULL){ //연결리스트 출력
		// printf(">> %c\n", curr->data);
		curr = curr->next;
	}
    ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //헤드 노드 생성
    p->data = value;
    curr->next = p; p->next = NULL;
    // if(curr == NULL)printf("N U L L\n");
    return head;
}

ListNode* Insert(ListNode *head, ListNode *new){
    ListNode* curr = head->next; 
	while(curr->next != NULL){ //연결리스트 출력
        if((curr->next)->data > new->data){
            new->next = curr->next;
            curr->next = new;
            break;
        }
		printf(">> %c\n", curr->data);
		curr = curr->next;
	}
    return head;
}

int main(){
    /*노드를 메모리 동적 할당으로 생성하기*/
    ListNode* head = (ListNode*)malloc(sizeof(ListNode)); //헤드 노드 생성
    head->next = NULL;
    Initialize(head);

    ListNode* new = (ListNode*)malloc(sizeof(ListNode)); //node1 이라는 새로운 노드를 새로 할당
    new->data = 'C';

    /*순회용 노드*/
    ListNode* curr = head->next; 
	while(curr != NULL){ //연결리스트 출력
		printf("%c\n", curr->data);
		curr = curr->next;
	}

    free(head);
	return 0;
}