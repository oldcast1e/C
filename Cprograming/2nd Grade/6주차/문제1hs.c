#include <stdio.h>
#include <stdlib.h>
/*
실행 가능 확인 24.03.27
*/
typedef struct Node {
    //연결리스트 본체: 가지고 있는 데이터 값과 전/후방 연결위치 저장
	int data;
	struct Node* next;
	struct Node* pre;
}Listnode;

typedef struct list {
    //리스트의 정보 :  리스트의 헤드노드와 테일 노드의 설정 구조체
	int size;
	Listnode* head;
	Listnode* tail;
}list_info;

void inset_last(list_info* list,int rank,char data){
	Listnode* curr = list->head;
	for (int i = 0; i < rank; i++) {
		curr = curr->next;
	}
	Listnode* new = (Listnode*)malloc(sizeof(Listnode)); //새로 추가할 노드
	
    new->data = data;

	new->next = curr;
	new->pre = curr->pre;
	(curr->pre)->next = new;
	curr->pre = new;
	list->size++;

}

void inset_first(list_info* list, char data){
	Listnode* new_node = (Listnode*)malloc(sizeof(Listnode)); // 새로운 노드 생성
    if (new_node == NULL) {
        // 메모리 할당 실패 처리
        return;
    }
    
    new_node->data = data;
    new_node->next = NULL; // 새로운 노드의 다음 노드를 NULL로 설정

    if (list->head == NULL) {
        // 리스트가 비어있을 경우 새로운 노드를 리스트의 head로 설정
        list->head = new_node;
        list->tail = new_node;
    } else {
        // 리스트가 비어있지 않을 경우, 새로운 노드를 리스트의 head로 설정하고 기존의 head를 새로운 노드의 다음 노드로 설정
        new_node->next = list->head;
        list->head->pre = new_node;
        list->head = new_node;
    }

    list->size++;
}

// void inset_first(list_info* list,int rank,char data){
	
// 	list_info* new_list;
// 	(new_list->head)->next = (list->head->next);
// 	Listnode* new = new_list->head;
// 	// printf("(list->head)->next = %c\n",(list->head)->next->data);

// 	// new->pre = NULL;
// 	// new->pre = list->head;
// 	new->data = data;
// 	// // list->head->pre = new;
// 	// new->next = list->head->next;
// 	// printf("new ->next->data = %c\n",new->next->data);
// 	// printf("new ->data = %c\n",new->data);
	

// 	// printf("new->data = %c\n",new->data);
// 	// new->pre = list->head;

	
// 	list->size++;
// }
/*
5
A 1 D
F 1 A
F 2 B
F 3 C
P
*/
void delete(list_info* list,int rank)
{
	Listnode* del = list->head;
	for (int i = 0; i < rank; i++) {
		del = del->next; // rank의 위치까지 반복
	}
    /*
    1. "지울 노드의 뒷 노드"의 다음 노드는 "지울 노드의 다음 노드"가 되어야함.
    2. " '지울 노드의 다음 노드'의 '뒷 노드'"는 "지울 노드의 이전 노드"가 되어야함
    */
	(del->pre)->next = del->next;
	(del->next)->pre = del->pre;
	list->size--;
}

void get(list_info* list,int rank) {
	Listnode* p = list->head;
	for (int i = 0; i < rank; i++) {
		p = p->next; // rank 위치의 노드로 이동
	}
	printf("%c", p->data);
}

void print(list_info* list) {
	Listnode* p = list->head->next;
	while (p != list->tail) { 
		printf("%c", p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	list_info* list = (list_info*)malloc(sizeof(list_info));
	list->head = (Listnode*)malloc(sizeof(Listnode));
	list->tail = (Listnode*)malloc(sizeof(Listnode));
	list->head->pre = NULL;
	list->head->next = list->tail;
	list->tail->pre = list->head;
	list->tail->next = NULL;
	list->size = 0;

	int n;
	scanf("%d",&n);getchar();

	char operator ;
	for (int i = 0; i < n; i++) {
		scanf("%c", &operator);
		if (operator=='A') {
			int r;char data;
			scanf("%d %c", &r, &data);getchar();
			if ((r > list->size + 1) || (r < 1)) {printf("invalid position\n");}
            else inset_last(list,r, data);
		}
		else if (operator=='D') {
			int r;
			scanf("%d", &r);getchar();
			if ((r > list->size) || (r < 1)) {printf("invalid position\n");}
			else delete(list, r);
		}
		else if (operator=='G') {
			int r;
			scanf("%d", &r); getchar();
			if (r > list->size) {printf("invalid position\n");}
			else get(list, r);
		}
		else if (operator=='P') {
			getchar();
			print(list);
		}
		else if (operator=='F') {
			int r;char data;
			scanf("%d %c", &r, &data);getchar();
			if ((r > list->size + 1) || (r < 1)) {printf("invalid position\n");}
            else inset_first(list, data);
		}
	}
	return 0;
}
/*
9
A 1 D
A 2 a
A 3 Y
D 1 
P
G 3 
A 1 S
P
G 3


*/