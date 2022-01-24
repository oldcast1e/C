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
