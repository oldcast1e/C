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
    if(rank < 1 || rank > (list->size+1)){printf("Invaild position.");return;}

    if(rank == 1) add_front(list,data);
    else if(rank == list->size + 1) add_rear(list,data);
    else add_middle(list,data,rank);
}

element delete(ListType* list, int rank){
    if( list->size <= 0 || rank < 1 || rank > list->size ){printf("Invaild position.");return -1;}

    if(rank == 1) return delete_front(list);
    else if(rank == list->size) return delete_rear(list);
    else return delete_middle(list,rank);
}

element get(ListType* list, int rank){
    if( list->size <= 0 || rank < 1 || rank > list->size){printf("Invaild position.");return -1;}
    ListNode *tmp = list->Head;
    for(int i=0 ;i <rank ; i++ )tmp = tmp->next;
    return tmp->data;
}

void print(ListType *list){
    ListNode * tmp = list->Head->next;
    for(int i=0; i< list->size ; i++){printf("[%c]",tmp->data);tmp = tmp->next;} printf("\n");
}

int main(){
    ListType list;
    init(&list);


    add(&list,'A',1);print(&list);
    add(&list,'B',2);print(&list);
    add(&list,'C',3);print(&list);
    add(&list,'D',2);print(&list);
    add(&list,'E',5);print(&list);

    delete(&list,1);printf("[After Delete] "); print(&list);
    delete(&list,3);printf("[After Delete] "); print(&list);
    delete(&list,3);printf("[After Delete] "); print(&list);

    // printf("rank %d data is [%c]",0,get(&list,0));
    printf("rank %d data is [%c].\n",1,get(&list,1));
    printf("rank %d data is [%c].\n",2,get(&list,2));

    // add(&list,'B',0);print(&list);

    // add_front(&list,'A');print(&list);
    // add_front(&list,'B');print(&list);
    // add_front(&list,'C');print(&list);

    // add_middle(&list,'D',2);print(&list);
    // add_middle(&list,'E',3);print(&list);

    // add_rear(&list,'F');print(&list);
    // add_rear(&list,'G');print(&list);


    // printf("[%c] is deleted(front).\n",delete_front(&list));
    // printf("[list] "); print(&list);

    // printf("[%c] is deleted(miidle).\n",delete_middle(&list,3));
    // printf("[list] "); print(&list);

    // printf("[%c] is deleted(rear).\n",delete_rear(&list));
    // printf("[list] "); print(&list);
}