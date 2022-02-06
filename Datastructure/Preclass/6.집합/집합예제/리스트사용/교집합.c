#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

typedef struct ListNode {
	int data;//현재 노드가 가지고 있는 데이터(값)
	struct ListNode *next;//다음 노드의 위치
    struct ListNode *pre;//이전 노드의 위치
}ListNode;

void add(ListNode *head, int rank, int value){//구조체 함수
    ListNode* curr = head; //순회용 노드 생성
    for(int i=0;i<rank;i++)curr= curr->next;

    ListNode *p=(ListNode *)malloc(sizeof(ListNode));//추가할 노드를 동적할당한다.
    p->data = value;

    p->next = curr->next;
    curr->next = p;

    p->pre = curr;
    (p->next)->pre = p;
    // printf("추가된 노드의 데이터는 %c입니다.\n",p->data);

}

void function_arrangement(ListNode* head,ListNode* tail){

    head->next = tail;
    head->pre = NULL;

    tail->next = NULL;
    tail->pre = head;

}

int main(){
    int num,cnt = 0;
    ListNode* A_head = (ListNode*)malloc(sizeof(ListNode)); //헤드 노드 생성
    ListNode* A_trail = (ListNode*)malloc(sizeof(ListNode)); //트레일 노드 생성
    function_arrangement(A_head,A_trail);

    ListNode* B_head = (ListNode*)malloc(sizeof(ListNode)); //헤드 노드 생성
    ListNode* B_trail = (ListNode*)malloc(sizeof(ListNode)); //트레일 노드 생성
    function_arrangement(B_head,B_trail);

    ListNode* rst_head = (ListNode*)malloc(sizeof(ListNode)); //헤드 노드 생성
    ListNode* rst_trail = (ListNode*)malloc(sizeof(ListNode)); //트레일 노드 생성
    function_arrangement(rst_head,rst_trail);

    for(int i=0;i<5;i++){scanf("%d",&num);add(A_head,i,num);}
    for(int i=0;i<5;i++){scanf("%d",&num);add(B_head,i,num);}

    
    ListNode* cmp_A = A_head->next; //순회용 노드 생성
    ListNode* cmp_B = B_head->next; //순회용 노드 생성
    for (int j=0;j<5;j++) {
        cmp_A = A_head->next;
		for (int i=0;i<5;i++) {
            // printf("cmp_B->data = %d | cmp_A->data = %d\n",cmp_B->data,cmp_A->data);
			if(cmp_B->data == cmp_A->data){
                // printf("check!\n");
                add(rst_head,cnt,cmp_B->data);
                cnt ++; break;
            }
            cmp_A = cmp_A->next;
		}
        cmp_B = cmp_B->next;
	}

    ListNode* prt = rst_head->next; //순회용 노드 생성
    for(int i=0;i<cnt;i++){
        printf("%d\n", prt->data);
	    prt = prt->next;
    }free(prt);


}