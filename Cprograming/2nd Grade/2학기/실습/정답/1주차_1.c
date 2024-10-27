#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef char element;

typedef struct ListNode{
    element data;
    struct ListNode* next;
    struct ListNode* prev;
}ListNode;

typedef struct ListType{
    int size;
    struct ListNode* Head;
    struct ListNode* Tail;
}ListType;

void init(ListType* list){

    list->Head = (ListNode*)malloc(sizeof(ListNode));
    list->Tail = (ListNode*)malloc(sizeof(ListNode));

    list->Head->next = list->Tail;
    list->Head->prev = NULL;
    list->Tail->next = NULL;
    list->Tail->prev = list->Head;

    list->size = 0;
}

void add_front(ListType* list, element data){
    ListNode *new = (ListNode*)malloc(sizeof(ListNode));
    new->data = data;

    new->next = list->Head->next;
    new->prev = list->Head;

    list->Head->next->prev = new;
    list->Head->next = new;

    list->size ++;
}

void add_middle(ListType *list, element data,int rank){
    ListNode *tmp = list->Head;
    for(int i = 0; i < rank - 1; i++) tmp = tmp->next; // 추가할 위치의 전까지 이동
    // printf("position data [%c]",tmp->data);
    ListNode * new = (ListNode*)malloc(sizeof(ListNode));
    new ->data = data;

    new->next = tmp->next;
    new->prev = tmp;

    tmp->next->prev = new;
    tmp->next = new;

    list->size++;
}

void add_rear(ListType* list, element data){
    ListNode* new = (ListNode*)malloc(sizeof(ListNode));
    new->data = data;

    new->next = list->Tail;
    new->prev = list->Tail->prev;

    list->Tail->prev->next = new;
    list->Tail->prev = new;

    list->size++;
}

element delete_front(ListType* list){
    ListNode* tmp = list->Head->next;
    element value = tmp->data;

    list->Head->next->prev = list->Head;
    list->Head->next = list->Head->next->next;

    list->size --;

    return value;
}

element delete_middle(ListType *list, int rank){
    ListNode *tmp = list->Head;
    for(int i=0; i<rank; i++) tmp = tmp->next;

    element value = tmp->data;

    tmp->next->prev = tmp->prev;
    tmp->prev->next = tmp->next;

    list->size --;

    return value;
}

element delete_rear(ListType* list){
    ListNode* tmp = list->Tail->prev;
    element value = tmp->data;

    tmp->prev->next = list->Tail;
    list->Tail->prev = tmp->prev;

    list->size --;

    return value;

}

void add(ListType* list, element data, int rank){
    if(rank < 1 || rank > (list->size+1)){printf("invalid position");return;}

    if(rank == 1) add_front(list,data);
    else if(rank == list->size + 1) add_rear(list,data);
    else add_middle(list,data,rank);
}

element delete(ListType* list, int rank){
    if( list->size <= 0 || rank < 1 || rank > list->size ){printf("invalid position");return -1;}

    if(rank == 1) return delete_front(list);
    else if(rank == list->size) return delete_rear(list);
    else return delete_middle(list,rank);
}

element get(ListType* list, int rank){
    if( list->size <= 0 || rank < 1 || rank > list->size){printf("invalid position\n");return -1;}
    ListNode *tmp = list->Head;
    for(int i=0 ;i <rank ; i++ )tmp = tmp->next;
    return tmp->data;
}

void print(ListType *list){
    ListNode * tmp = list->Head->next;
    for(int i=0; i< list->size ; i++){printf("%c",tmp->data);tmp = tmp->next;} printf("\n");
}

int main(){
    ListType list;
    init(&list);
	
	int N, rank; 
	char data, fuc, tmp;

	scanf("%d",&N); getchar();
	for(int i=0;i<N;i++){
		scanf("%c%c",&fuc,&tmp);
		if(fuc == 'A'){
			scanf("%d%c%c",&rank,&tmp,&data); getchar();
			add(&list,data,rank);
		}
		else if(fuc == 'D'){
			scanf("%d",&rank);getchar();
			int value = delete(&list,rank);
		}
		else if(fuc == 'G') {
			scanf("%d",&rank);getchar();
			int value = get(&list,rank);
			if(value != -1)printf("%c",value);
		}
		else if(fuc == 'P'){print(&list);}
	}
	// print(&list);
}
/*
9
A 1 D
A 2 a
A 3 y
D 1 
P
G 3
A 1 S
P
↦ 연산의 개수: 9
↦ add(list, 1, 'D') 
↦ add(list, 2, 'a') 
↦ add(list, 3, 'y') 
↦ delete(list, 1)
↦ print(list)
↦ get_entry(list, 3) 
↦ add(list, 1, 'S') 
↦ print(list)
↦ get_entry(list, 3)

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