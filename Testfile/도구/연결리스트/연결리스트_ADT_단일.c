#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

/*연결 리스트를 구현할 구조체*/
typedef struct ListNode{
    int data;
    struct ListNode* next;//자가 참조 구조체
    /*다음 노드의 주소를 저장할 자기참조 구조체포인터*/
}ListNode;

ListNode* add(ListNode *head, int rank, int value){//구조체 함수
    /*list의 순위 r에 원소 e를 추가해야함으로 순위r까지 반복한 후 해당 위치에 원소 e를 추가하도록한다.*/
    int cnt = 0;
    ListNode* check = head->next; //순회용 노드 생성
    while(check != NULL){
	    cnt ++;
	    check = check->next;
    }free(check);

    //printf("cnt = %d\n",cnt);
    if(cnt > rank) {printf("invalid position");return 0;}
    else{
        ListNode* curr = head; //순회용 노드 생성
        for(int i=0;i<rank;i++)curr= curr->next;
        //위 반복문을  통해 이미 순위가 r인 노드까지 이동함.(ㄱ)
        ListNode *p=(ListNode *)malloc(sizeof(ListNode));//추가할 노드를 동적할당한다.

        p->data = value;

        p->next = curr->next;
        curr->next = p;

        // printf("추가된 노드의 데이터는 %d입니다.\n",p->data);
        return head; //다음 노드의 위치를 반환함.
    }

}

// delete(list, r) : list의 순위 r에 위치한 원소를 삭제한다 (주교재의 remove와 동일)
ListNode* delete(ListNode *head, int rank){//구조체 함수
   
    ListNode* rear = head; //순회용 노드 생성
    for(int i=0;i<rank-1;i++)rear= rear->next;//삭제할 노드의 뒤까지 반복
    // free(rear->next);
    (rear->next) = (rear->next)->next;
    // (삭제할 노드-1)의 다음 노드는 (삭제할 노드의 + 1)
    return head;
    
}

void print(ListNode *head){
    ListNode* prt = head->next; //순회용 노드 생성
    while(prt != NULL){
	    printf("%d ", prt->data);
	    prt = prt->next;
    }free(prt);
    printf("\n");
}

int main(){
    /*노드를 메모리 동적 할당으로 생성하기*/
    ListNode* head = (ListNode*)malloc(sizeof(ListNode)); //헤드 노드 생성
    ListNode* end = (ListNode*)malloc(sizeof(ListNode)); //엔드 노드 생성
    end = NULL;// end->next = end; 
    head->next = end; 

    int rank=0,value;
    for(int i=0;i<5;i++){
        add(head,rank,10* (i+1)); rank++;
    }
    delete(head,3);
    


    print(head);

    free(head);free(end);
	return 0;
}
