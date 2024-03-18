#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

/*연결 리스트를 구현할 구조체*/
typedef struct ListNode{
    int data;
    struct ListNode* next;//자가 참조 구조체
    struct ListNode* pre;//자가 참조 구조체
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

    if(cnt < rank) {
        // printf("cnt = %d | rank = %d\n",cnt,rank);
        printf("invalid position");
        return 0;
    }
    else{
        ListNode* curr = head; //순회용 노드 생성
        for(int i=0;i<rank;i++)curr= curr->next;//t
        ListNode *p=(ListNode *)malloc(sizeof(ListNode));//추가할 노드를 동적할당한다.
        // printf("curr로 확인한 %c번째 노도의 값:[%c]\n",rank,curr->data);
        p->data = value;//a
        curr = p->pre;
        
        p->next = (curr->next);
        (curr->pre)= p;
        
        p->pre = curr; 
        curr->next = p;
        /*
        u -> p 에서 u -> v -> p
        Algorithm add(p, e) : {insert e before p}
        Create a new node v
        v -> element = e
        u = p->prev
        v -> next = p; p -> prev = v; {linke in v befoer p}
        v -> prev = u; u -> next = v; {linked in after u}
        */
        return head; //다음 노드의 위치를 반환함.
    }

}

// delete(list, r) : list의 순위 r에 위치한 원소를 삭제한다 (주교재의 remove와 동일)
ListNode* delete(ListNode *head, int rank){//구조체 함수
    int cnt = 0;
    ListNode* check = head->next; //순회용 노드 생성
    while(check != NULL){
        cnt ++;
        check = check->next;
    }
/*
Algorithm remove(p):
   u = p->prev
   w = p->next
   u->next = w {linking out p}
   w->prev = u

*/
    if(cnt < rank) {
        printf("cnt = %d | rank = %d\n",cnt,rank);
        printf("invalid position");
        return 0;
    }
    else{
        ListNode* removed = head->next; //삭제용 노드 생성
        for(int i=0;i<rank;i++)removed= removed->next;
        printf("data: %c를 삭제합니다.\n",removed->data);

        ListNode* connect = removed->pre;
        connect->next = removed->next;
        (removed->next)->pre = connect;

        free(removed);
        return head;
    }
    
}

// get(list, r) : list의 순위 r에 위치한 원소를 반환한다.
char get(ListNode *head, int rank){//구조체 함수
   
    int cnt = 0;
    ListNode* check = head->next; //순회용 노드 생성
    while(check != NULL){
	    cnt ++;
	    check = check->next;
    }free(check);
    
    printf("cnt = %d | rank = %d\n",cnt,rank);
    
    if(cnt < rank) {printf("invalid position");return 0;}
    else{
        ListNode* curr = head; //순회용 노드 생성
        for(int i=0;i<rank;i++)curr= curr->next;
        return curr->data; //다음 노드의 위치를 반환함.
    }

}

void print(ListNode *head){
    ListNode* prt = head->next; //순회용 노드 생성
    while(prt != NULL){
	    printf("%c", prt->data);
	    prt = prt->next;
    }free(prt);
    printf("\n");
}

int main(){
    /*노드를 메모리 동적 할당으로 생성하기*/
    ListNode* head = (ListNode*)malloc(sizeof(ListNode)); //헤드 노드 생성
    ListNode* end = (ListNode*)malloc(sizeof(ListNode)); //트레일 노드 생성

    // head = NULL;
    head->next = end;
    head->pre = NULL;

    end->next = NULL;
    end->pre = head;

    int N,rank;
    char fuc,ipt,tmp;
    scanf("%d",&N); getchar();

    for(int i=0;i<N;i++){
        scanf("%c%c",&fuc,&tmp);
        // scanf("%c %d %c",&fuc,&rank,&ipt); getchar();
        switch (fuc){
            case 'A'://add 함수 실행
                scanf("%d %c",&rank,&ipt); getchar();
                /* code */
                // printf("case 1 실행 %c %d %c\n",fuc,rank,ipt);
                add(head,rank,ipt);
                break;
            case 'D': //delete함수 실행
                scanf("%d",&rank); getchar();
                // printf("case 2 실행\n");
                delete(head,rank);
                /* code */
                break;
            case 'G': //get 함수 실행
                /* code */
                scanf("%d",&rank); getchar();
                // printf("case 3 실행\n");
                printf("%c",get(head,rank));
                break;
            case 'P'://print 함수 실행
                /* code */
                // printf("case 4 실행\n");
                print(head);
                break;
        
        // default:
        //     break;
        }
    }

}
/*
5
A 1 S
A 2 t
A 3 r
A 3 a
P

↦ 연산의 개수: 5
↦ add(list, 1, 'S') 
↦ add(list, 2, 't') 
↦ add(list, 3, 'r') 
↦ add(list, 3, 'a') 
↦ print(list)

9
A 1 D
A 2 a
A 3 y
D 1
P
G 3
A 1 S
P
G 3
 */