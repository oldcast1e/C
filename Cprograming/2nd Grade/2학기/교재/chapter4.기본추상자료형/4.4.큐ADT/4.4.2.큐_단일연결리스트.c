#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef int element;
//큐는 선입선출 -> 이중연결리스트로 구현 필요

typedef struct QueType{
    struct QueNode* front;
    struct QueNode* rear;
    int size;
}QueType;

typedef struct QueNode{
    struct QueNode* next;
    element data;
}QueNode;

void init(QueType* Q){
    Q->front = (QueNode*)malloc(sizeof(QueNode));
    Q->rear = (QueNode*)malloc(sizeof(QueNode));

    Q->front->next = Q->rear;
    Q->rear->next = NULL;
    Q->size = 0;
}

void inQue(QueType* Q,element e){
    QueNode* new = (QueNode*)malloc(sizeof(QueNode));
    new->data = e;
    if(Q->size ==0){
        Q->front->next = new;
        new->next = Q->rear;
    }
    else{
        new->next = Q->front->next;
        Q->front ->next = new;
    }
    // printf("(%d)\n",e);
    Q->size++;
}

element deQue(QueType* Q){
    if(Q->size <=0 ){printf("Invaild Error.");return-1;}
    QueNode* del = Q->front->next;
    QueNode* tmp = (QueNode*)malloc(sizeof(QueNode));
    while(del->next->next != NULL){
        tmp = del;
        del=del->next;
    }

    element rtv = del->data;
    tmp ->next = tmp->next->next;

    Q->size --;
    return rtv;
}

element front(QueType* Q){
    if(Q->size <=0 ){printf("Invaild Error.");return-1;}
    else return(Q->front->next->data);
}

element rear(QueType* Q){
    if(Q->size <=0 ){printf("Invaild Error.");return-1;}
    else{
        QueNode* tmp = Q->front->next;
        while(tmp->next->next != NULL) tmp=tmp->next;
        return tmp->data;
    }
}

int size(QueType* Q){return Q->size;}

element* elements(QueType* Q){
    QueNode* tmp = Q->front->next;
    int* num = (int*)malloc(sizeof(int)*Q->size);
    for(int i=0;i<Q->size;i++){num[i]= tmp->data; tmp=tmp->next;}
    return num;
}

void printQue(QueType* Q){
    int *num = elements(Q);
    for(int i=0;i<Q->size;i++) printf("[%d] ",num[i]); printf("\n");
}

int main(){
    QueType queue;
    init(&queue);

    srand(time(NULL));
    for(int i=0;i<10;i++) inQue(&queue,rand()%10);
    printQue(&queue);
    printf("[%d] is deQued.\n",deQue(&queue));
    printf("[%d] is deQued.\n",deQue(&queue));
    printf("[%d] is deQued.\n",deQue(&queue));
    printf("[%d] is deQued.\n",deQue(&queue));
    printf("[%d] is deQued.\n",deQue(&queue));
    printQue(&queue);
    // printf("front data: [%d]\n",front(&queue));
    // printf("rear data: [%d]\n",rear(&queue));
}