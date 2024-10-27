#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int element;

typedef struct listType{
    struct listNode* head;
    int size;
}listType;

typedef struct listNode{
    struct listNode* next;
    element data;
}listNode;

void init(listType* L){
    L->head = (listNode*)malloc(sizeof(listNode));
    L->size = 0;
}

void add(listType* L,element e){
    listNode* new = (listNode*)malloc(sizeof(listNode));
    new->data = e;

    if(L->size == 0) L->head = new;
    else{
        new->next = L->head;
        // L->head->next = new;
        L->head= new;
        // listNode* tmp = L->head;
        // for(int i=0;i<L->size;i++) tmp= tmp->next;
        // tmp->next = new;
        // printf("[%d] ",new->data);
    }
    L->size ++;
}

void printL(listType* L){
    listNode* tmp = L->head;
    for(int i=0;i<L->size;i++) {
        printf("[%d] ",tmp->data);
        tmp= tmp->next;
    }printf("\n");
}

// element delete(listType* L){

// }

int candle(int n, int k){
    int remaining = n;
    listType list; init(&list);
    for(int i=0;i<n;i++) add(&list,n-i);
    printL(&list);

    listNode* tmp = list.head;
    for(int i=0;i<list.size-1;i++) tmp= tmp->next;
    tmp->next = list.head;


    listNode* node = list.head;
    while(remaining>1){
        // while(num[now] == 0){now = (now+1)%n;}

        while(node->data == 0) node = node->next;
        printf(">>delete [%d]\n",node->data);
        node->data = 0;
        remaining--;
        
        // if(remaining == 1){printf("<%d>",node->data);}
        // node = node->next;

        for(int i=0;i<k;i++){
            if(node->data == 0) {i--; node= node->next;}
            else {node= node->next;}
        }
    }
    while(node->data == 0) node = node->next;
    printf("<%d>",node->data);
    

}

int main(){
    int n = 10;
    int k = 3;
    // int remaining = 
    candle(n,k);
    // printf("%d",remaining);
}