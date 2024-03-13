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

    if(cnt < rank) {
        // printf("cnt = %d | rank = %d\n",cnt,rank);
        printf("invalid position");
        return 0;
    }
    else{
        ListNode* curr = head; //순회용 노드 생성
        for(int i=0;i<rank;i++)curr= curr->next;
        // printf("[curr]:%c [curr->next]:%c\n",curr->data,curr->next->data);
        //위 반복문을  통해 이미 순위가 r인 노드까지 이동함.(ㄱ)
        ListNode *p=(ListNode *)malloc(sizeof(ListNode));//추가할 노드를 동적할당한다.

        p->data = value;
        p->next = curr->next;
        curr->next = p;

        // printf("추가된 노드의 데이터는 %c[%d]입니다.\n",p->data,cnt);
        return head; //다음 노드의 위치를 반환함.
    }

}

// delete(list, r) : list의 순위 r에 위치한 원소를 삭제한다 (주교재의 remove와 동일)
ListNode* delete(ListNode *head, int rank){//구조체 함수
   
    ListNode* rear = head; //순회용 노드 생성
    for(int i=0;i<rank-1;i++)rear= rear->next;//삭제할 노드의 뒤까지 반복
    ListNode* tmp = rear->next; 
    // printf("데이터 [%d]를 삭제합니다.\n",tmp->data);
    //삭제할 노드는 저장한 노드의 다음 노드이다. 그 노드를 임시로 저장한다. 
    rear->next = tmp->next; free(tmp);
    // (삭제할 노드-1)의 다음 노드는 (삭제할 노드의 + 1)
    return head;
}

// get(list, r) : list의 순위 r에 위치한 원소를 반환한다.
char get(ListNode *head, int rank){//구조체 함수
   
    int cnt = 0;
    ListNode* check = head->next; //순회용 노드 생성
    while(check != NULL){
	    cnt ++;
	    check = check->next;
    }free(check);
    if(cnt > rank) {printf("invalid position");return 0;}
    else{
        ListNode* curr = head; //순회용 노드 생성
        for(int i=0;i<rank;i++)curr= curr->next;
        return curr->data; //다음 노드의 위치를 반환함.
    }

}

void print(ListNode *head){
    ListNode* prt = head->next; //순회용 노드 생성
    while(prt->next != NULL){
	    printf("%c", prt->data);
	    prt = prt->next;
    }free(prt);
    // printf("\n");
}

int main(){
    /*노드를 메모리 동적 할당으로 생성하기*/
    ListNode* head = (ListNode*)malloc(sizeof(ListNode)); //헤드 노드 생성
    ListNode* end = (ListNode*)malloc(sizeof(ListNode)); //트레일 노드 생성

    head->next = end;
    end->next = NULL;

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
 */