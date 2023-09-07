#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

typedef char element;

typedef struct ListNode {
	element data;
	struct ListNode *next;
    struct ListNode *pre;
}ListNode;

void Initialize(ListNode *head,ListNode *tail){
    ListNode* NodeArr[5];
    for(int i=0;i<5;i++) NodeArr[i] = (ListNode*)malloc(sizeof(ListNode));
    
    for(int i=0;i<5;i++){    
        if(i==0){
            head->next = NodeArr[i]; 
            NodeArr[i]->data = 'A';
            NodeArr[i]->pre = head;
        }
        else{
            NodeArr[i-1]->next = NodeArr[i];
            NodeArr[i]->pre = NodeArr[i-1];
            NodeArr[i]->data = 'A'+ i;   
            printf("<<NodeArr[i]->data: %c | NodeArr[i]->pre->data: %c>>\n",NodeArr[i]->data,NodeArr[i]->pre->data);  
        }     
    }   
    NodeArr[4]->next = tail; 
    tail->pre = NodeArr[4];
}



int main(){

    ListNode* head = (ListNode*)malloc(sizeof(ListNode)); //헤드 노드 생성
    ListNode* tail = (ListNode*)malloc(sizeof(ListNode)); //테일 노드 생성
    head->next = NULL; 

    Initialize(head,tail);

    /*순회용 노드*/
    printf("[기본 연결리스트의 값] "); 
    int cnt = 0;
    ListNode* chc = head->next;
	while(chc != NULL){ //연결리스트 출력
		printf("%c ", chc->data);
		chc = chc->next;
        cnt++;
	}cnt--;
    printf("\n cnt = %d",cnt);

    ListNode* prt = (ListNode*)malloc(sizeof(ListNode)); 
    prt = tail; prt = prt->pre;
    printf("[연결리스트의 반전 값] "); 
    while(cnt>0){
        printf("%c ", prt->data);
        prt = prt->pre;
        cnt--;
    }
	return 0;
}