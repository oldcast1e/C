#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct ListNode {
	char data;//현재 노드가 가지고 있는 데이터(값)
	struct ListNode *next;//다음 노드의 위치
    struct ListNode *pre;//이전 노드의 위치
}ListNode;

//※ 순위 정보가 유효하지 않으면 화면에 에러 메시지 "invalid position" 출력하고, 해당 연산을 무시한다.
/*
순위 정보가 유효하지 않다는 것을 어떻게 판단할 수 있을까
- 해당 순위까지 반복했을 때, 해당 위치에 값이 없는 경우
- 해당 순위까지 반복하며 반복횟수를 셋을때 가능한 반복횟수보다 rank값이 더 큰 경우 / 혹은 0
-> 함수가 실행되기 전까지 가능한 반복횟수 cnt를 세고, 입력받은 rank의 값이 cnt보다 더 큰 경우 문장을 출력하고 종료!
*/
// add(list, r, e) : list의 순위 r에 원소 e를 추가한다.
ListNode* add(ListNode *head, int rank, char value){//구조체 함수
    /*list의 순위 r에 원소 e를 추가해야함으로 순위r까지 반복한 후 해당 위치에 원소 e를 추가하도록한다.*/
    int cnt = 0;
    ListNode* check = head->next; //순회용 노드 생성
    while(check != NULL){
	    cnt ++;
	    check = check->next;
    }free(check);

    printf("cnt = %d\n",cnt);
    if(cnt > rank) {printf("invalid position");return 0;}
    else{
        ListNode* curr = head; //순회용 노드 생성
        for(int i=0;i<rank;i++)curr= curr->next;
        //위 반복문을  통해 이미 순위가 r인 노드까지 이동함.(ㄱ)
        ListNode *p=(ListNode *)malloc(sizeof(ListNode));//추가할 노드를 동적할당한다.

        /*
        동적할당한 노드의 데이터에 인자로 불러온 값을 저장하고, 

        1.(ㄱ)의 다음노드 링크를 동적할당한 p로 설정 : p노드가 중간에 설정되기때문
        2.(ㄱ)노드의 다음 노드를 동적할당한 p로 설정
        
        */
        p->data = value;

        p->next = curr->next;
        curr->next = p;

        p->pre = curr;
        (p->next)->pre = p;
        // printf("추가된 노드의 데이터는 %c입니다.\n",p->data);
        return head; //다음 노드의 위치를 반환함.
    }
    

    /*다시 말해 인자로 받은 노드와 그 다음 노드 사이에 새로운 노드를 추가하는 것!*/
}
// delete(list, r) : list의 순위 r에 위치한 원소를 삭제한다 (주교재의 remove와 동일)
ListNode* delete(ListNode *head, int rank){//구조체 함수
    int cnt = 0;
    ListNode* check = head->next; //순회용 노드 생성
    while(check != NULL){
	    cnt ++;
	    check = check->next;
    }free(check);

    if(cnt > rank) {printf("invalid position");return head;}
    else{
        ListNode* removed = head; //삭제용 노드 생성
        /*
        만약 3번째 노드를 삭제해야한다면,
        삭제용노드를 헤드 노드로 초기화했으므로
        <ㅁ> -> ㅁ -> A -> (ㅁ) -> B 
        */
        for(int i=0;i<=rank;i++)removed= removed->next;
        /*
        삭제할 노드를 찾았다면
        1. 삭제할 노드의 다음 노드_B의 위치를 삭제할 노드의 전 노드의 다음 노드_A 위치로 변경한다. : 이전 노드의 위치를 저장해야함!

        */
        (removed->next)->pre = removed->pre;
        (removed->pre)->next = removed->next;
        free(removed);
        return head;
    }
    
}

//get(list, r) : list의 순위 r에 위치한 원소를 반환한다.
char get(ListNode *head, int rank){
    int cnt = 0;
    ListNode* check = head->next; //순회용 노드 생성
    while(check != NULL){
	    cnt ++;
	    check = check->next;
    }free(check);
    if(cnt > rank) {printf("invalid position");return 0;}
    else{
        ListNode* getting = head; //삭제용 노드 생성
        for(int i=0;i<=rank;i++)getting= getting->next;
        return getting->data;
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
/**
◦ 다음 네 가지 연산을 지원해야 함 (순위는 1부터 시작한다고 가정)


※ 순위 정보가 유효하지 않으면 화면에 에러 메시지 "invalid position" 출력하고, 해당 연산을
무시한다.
◦ 입력에 대한 설명 (아래 입출력 예시 참조)
- 각 연산의 내용이 한 줄에 한 개씩 입력되고, 한 개의 줄에는 연산의 종류, 순위, 원소 순서 로 입력된다.
- 연산의 종류: 연산 이름의 맨 앞 영문자가 대문자 A, D, G, P로 주어진다.
- 순위: 양의 정수
- 원소: 영문자(대문자, 소문자 모두 가능)
 */
int main(void){
    int N,rank;scanf("%d",&N);getchar();
    //rank: 순위
    //elm: 원소
    char cal_word,elm,tmp;
    ListNode* head = (ListNode*)malloc(sizeof(ListNode)); //헤드 노드 생성
    ListNode* trail = (ListNode*)malloc(sizeof(ListNode)); //트레일 노드 생성

    head->next = trail;
    head->pre = NULL;

    trail->next = NULL;
    trail->pre = head;

    for(int i=0;i<N;i++){
        scanf("%c%c",&cal_word,&tmp);
        // scanf("%c %d %c",&cal_word,&rank,&elm);getchar();
        switch (cal_word){
        case 'A':
            scanf("%d %c",&rank,&elm);getchar();
            // printf("A를 선택하셨습니다.rank: %d\n",rank);
            add(head,rank,elm);
            break;
        case 'D':
            scanf("%d",&rank);getchar();
            // printf("D를 선택하셨습니다. rank: %d\n",rank);
            // delete(head,rank);
            break;
        case 'G':
            scanf("%d",&rank);getchar();
            // printf("G를 선택하셨습니다. rank: %d\n",rank);
            printf("output: %c\n",get(head,rank));
            break;
        case 'P':
            print(head);
            break;
        }
    }
    /*
    ListNode* curr = head->next; //순회용 노드 생성
    while(curr != NULL){
	    printf("%c", curr->data);
	    curr = curr->next;
    }free(curr);

    6
    A 1 S
    A 2 T
    A 3 A
    A 4 R
    D 6
    P
    */
    
    

}
