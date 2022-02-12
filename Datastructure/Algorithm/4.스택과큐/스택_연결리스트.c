#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*연결 리스트를 구현할 구조체*/
typedef struct ListNode{
    int data;
    int max;
    int num;
    struct ListNode* next;//자가 참조 구조체
    /*다음 노드의 주소를 저장할 자기참조 구조체포인터*/
}ListNode;

int Push(ListNode *head,int val){
    int cnt = 1;
    ListNode* check = head; //순회용 노드 생성
    // printf(">val: %d\n",val);
    while(check->next != NULL){
        cnt ++;
	    check = check->next;
    }
    if(head->max <= cnt) return -1;
    ListNode* new = (ListNode *)malloc(sizeof(ListNode));
    check ->next = new;
    new->data = val;
    new-> next = NULL;

    // printf("푸시된 데이터의 개수: %d\n",cnt);
    head-> num = cnt;
    return 0;
}

int Pop(ListNode *head){
    int val;
    if(head->num <= 0) return -1;

    ListNode* check = head; //순회용 노드 생성
    while(check->next != NULL){check = check->next;}
    val = check->data;
    check = NULL;
    head->num --;
    return 0;
}

int Peek(ListNode *head){
    int pek;
    
    if(head->num <= 0) return -1;
    ListNode* check = head; //순회용 노드 생성

    pek = check->data;
    printf("pek: %d\n",pek);

    return 0;
}

void Clear(ListNode *head){
    ListNode* check = head; //순회용 노드 생성
    check->next = NULL;
}

int Capacity(ListNode *head){return head->max;}

int Size(ListNode *head){return head->num;}

int isEmpty(ListNode *head){return (head->num <= 0);}

int isFull(ListNode *head){
    return( head-> num >= head->max);
    //스택의 데이터 개수가 스택의 최대 용량보다 많으면 1 반환
    //스택의 데이터 개수가 스택의 최대 용량보다 적으면 0 반환
}

/*스택에서의 검색*/
int Search(ListNode *head,int key){
    //스택의 개수만큼 꼭대기에서 부터 선형 검색
    int cnt = 0;
    ListNode* check = head; //순회용 노드 생성
    // printf(">val: %d\n",val);
    while(check->next != NULL){
	    check = check->next;
        if(check->data == key) return cnt;
        cnt ++;
    }
    return -1;
}

void Print(ListNode *head){
    ListNode* check = head; //순회용 노드 생성
    int cnt = 0;
    // printf(">val: %d\n",val);
    while((head->num) > cnt){
	    check = check->next;
        printf("%d ",check->data);
        cnt ++;
    }printf("\n");
}

int main() {
    int tmp;
    ListNode *head =(ListNode *)malloc(sizeof(ListNode));
    head -> next = NULL;
    head->max = 1000;

    for(int i=0;i<5;i++) {
        printf("%d 번째 입력: ",i+1);
        scanf("%d",&tmp);
        Push(head,tmp);
    }
    // printf("성공여부: %d\n",Pop(head));
    // printf("스택의 용량: %d\n",Capacity(head)); 
    printf("스택의 데이터 개수: %d\n",Size(head)); 
    // Clear(head);
    // Print(head);

    // ListNode* check = head->next; //순회용 노드 생성
    // while(check != NULL){
    //     printf("%d ",check->data);
	//     check = check->next;
    // }

}	
