#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct ListNode {
	int data;//현재 노드가 가지고 있는 데이터(값)
    int rank;
	struct ListNode *next;//다음 노드의 위치
    struct ListNode *pre;//이전 노드의 위치
}ListNode;

// add(list, r, e) : list의 순위 r에 원소 e를 추가한다.
ListNode* add(ListNode *head, int rank, char value){//구조체 함수
    /*인자로는 
    head: 처음 노드의 위치
    pre: 이전노드의 위치
    value: 값
    */
    ListNode* curr = head->next; //순회용 노드 생성
    while(curr != NULL){
		if(rank == curr->rank){

            break;
        }
	}
    ListNode *p=(ListNode *)malloc(sizeof(ListNode));//p라는 임의의 구조체 포인터를 동적할당

    p->data = value;//입력받은 데이터를 생성한 구조체의 값 저장 멤버에 저장
    // p->next = pre->next;//생성한 구조체의 다음 노드 위치를 업데이트함.
    
    // pre->next = p;//이전 노드의 <다음노드위치>를 생성한 구조체의 위치로 업데이트함.

    return head; //다음 노드의 위치를 반환함.

    /*다시 말해 인자로 받은 노드와 그 다음 노드 사이에 새로운 노드를 추가하는 것!*/
}

//delete(list, r) : list의 순위 r에 위치한 원소를 삭제한다 (주교재의 remove와 동일)
ListNode* delete(ListNode *head, ListNode *pre){
    /*인자
    head: 다음 노드의 위치
    pre: 이전노드의 위치
    */

    ListNode *removed=(ListNode *)malloc(sizeof(ListNode));//(제거 할)구조체 포인터 선언 
    removed = pre->next;//pre구조체의 다음 노트 방향 포인터를 removed(구조체 포인터)에 저장
    pre->next = removed->next; //pre포인터의 다음 노드를 향하는 방향을 pre포인터의 다다음번째로 저장
    //즉,pre포인터의 다음 노드를 건너뜀 = 삭제

    free(removed);//메모리 해제

    return head;
}

//print(list) : list의 모든 원소를 저장 순위대로 공백없이 출력한다.
ListNode* print(ListNode* list){
    
    
    ListNode* curr = list->next; //순회용 노드 생성
	while(curr != NULL){
		printf("%d\n", curr->data);
		curr = curr->next;
	}
}

//get(list, r) : list의 순위 r에 위치한 원소를 반환한다.
ListNode* get(ListNode *list, ListNode *r){

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
    int N,rank;scanf("%d",&N);
    //rank: 순위
    //elm: 원소
    char cal_word,elm;
    ListNode* head = (ListNode*)malloc(sizeof(ListNode)); //헤드 노드 생성
    head->next = NULL;
    head->pre = NULL;
    for(int i=0;i<N;i++){
        scanf("%c %d %c",&cal_word,&rank,&elm);getchar();
        switch (cal_word){
        case 'A':
            add(head->next,rank,elm);
            //add(ListNode *head, ListNode *pre, int value)
            break;
        case 'D':

            break;
        case 'G':

            break;
        case 'P':

            break;
        default:

            break;
        }
    }
    

}
