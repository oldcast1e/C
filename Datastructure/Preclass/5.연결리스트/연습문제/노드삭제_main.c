#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;

typedef struct Node {
	element data;//노드가 저장하고 있는 값
	struct Node *next;//다음 노드의 포인터 (자가참조)
}Node;

Node* delete(Node *head, Node *pre){
    /*인자
    head 포인터: 출발지(현재) 포인터
    pre 포인터: 현재 노드의 앞에 해당하는 포인터
    */

    Node *removed;//(제거 할)구조체 포인터 선언
    removed = pre->next;
    //pre구조체의 다음 노트 방향 포인터를 removed(구조체 포인터)에 저장

    pre->next = removed->next;
    //pre포인터의 다음 노드를 향하는 방향을 pre포인터의 다다음번째로 저장
    //즉,pre포인터의 다음 노드를 건너뜀 = 삭제

    free(removed);//메모리 해제

    return head;
}
int main(){
    /*노드를 메모리 동적 할당으로 생성하기*/
    Node* head = (Node*)malloc(sizeof(Node)); //헤드 노드 생성
    head->next = NULL;

    Node* Node1 = (Node*)malloc(sizeof(Node)); //Node1 이라는 새로운 노드를 새로 할당
    

    /*머리노드와 Node1을 연결하기*/
    Node1->next = head->next;//Node1의 꼬리를 (기존)헤드의 꼬리로 연결
    Node1->data = 10;//Node1의 데이터 업데이드
    head->next = Node1;//헤드의 꼬리를 Node1으로 업데이트

    /*Node1와 Node2을 연결하기*/
    Node* Node2 = (Node*)malloc(sizeof(Node)); //Node2 이라는 새로운 노드를 새로 할당

    Node2->next = Node1->next;//Node1의 꼬리를 (기존)헤드의 꼬리로 연결
    Node2->data = 20;//Node1의 데이터 업데이드
    Node1->next = Node2;//헤드의 꼬리를 Node1으로 업데이트

    Node* curr = head->next; //순회용 노드 생성1
    
    printf("1차 순회\n");
	while(curr != NULL){
		printf("%d ", curr->data);
		curr = curr->next;
	}printf("\n");
    Node2 = delete(head,Node1); // node2가 삭제됨

    Node* curr2 = head->next; //순회용 노드 생성2
    printf("2차 순회\n");
	while(curr2 != NULL){
		printf("%d ", curr2->data);
		curr2 = curr2->next;
	}printf("\n");
    

    free(head);
	free(Node1);
	// free(Node2);
	return 0;
}