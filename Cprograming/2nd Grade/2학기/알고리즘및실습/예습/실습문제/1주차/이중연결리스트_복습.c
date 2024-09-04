#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    ListNode* new  = (ListNode*)malloc(sizeof(ListNode));
    new->data = data;

    new->next = list->Head->next;
    new->prev = list->Head->next->prev;

    list->Head->next = new;
    list->Head->next->prev = new;

    list->size ++;
}

void add_middle(ListType* list,int rank, element data){
    if(rank >= (list->size+1) || rank < 1){
        printf("Invaild Connect."); return ;
    }
    ListNode *tmp = list->Head;

    ListNode* new  = (ListNode*)malloc(sizeof(ListNode));
    // ListNode* pre  = (ListNode*)malloc(sizeof(ListNode));
    
    new->data = data;

    for(int i=0;i<rank-1;i++){tmp = tmp->next;}

    new->next = tmp->next;
    new->prev = tmp;

    tmp->next->prev = new;
    tmp->next = new;

    // printf("rank[%d] data = %c\n",rank,tmp->data);
    
    // new->prev = tmp->prev;
    // new->next = tmp;

    // tmp->prev->next = new;
    // tmp->prev =  new;    

    list->size ++;
}

void print(ListType *list){
    // printf("data : %c",list->Head->next->data);
    ListNode *tmp = list->Head;
    // printf("first data : %c",tmp->next->data);
    while(tmp->next->next != NULL){
        printf("[%c]",tmp->next->data);
        tmp = tmp->next;
    }printf("\n");
}

int main(){
    ListType list;
    init(&list);

    add_front(&list,'A');
    add_front(&list,'B');
    add_front(&list,'C');
    add_middle(&list,2,'D');
    print(&list);
}