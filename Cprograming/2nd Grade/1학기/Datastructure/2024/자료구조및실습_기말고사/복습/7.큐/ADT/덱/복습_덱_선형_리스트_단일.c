#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef char element;

#define MAX 10

typedef struct QueueNode {
    element data;
    struct QueueNode* next;
    struct QueueNode* prev;
} QueueNode;

typedef struct {
    QueueNode* rear;
    int size;
} QueueType;

void init(QueueType *Q){
    Q->size = 0;
    Q->rear = NULL;
}

int isEmpty(QueueType *Q){return (Q->size==0);}
int isFull(QueueType *Q){return (Q->size >= MAX);}


void push(QueueType* Q, element e){
    //front 위치에 원소를 삽입합니다. (→ +)
    if(isFull(Q)){ printf("Queue is Full.");exit(1);}

    QueueNode *new = (QueueNode*)malloc(sizeof(QueueNode));
    new->data = e;
    
    if(isEmpty(Q))Q->rear = new;
    else{
        new->next = Q->rear;
        Q->rear = new;
    }
    Q->size ++; 

    // QueueNode *p = Q->front;
    // for(int i= 0 ; i< Q->size ; i++){
    //     printf("(%c)",p->data);
    //     p = p->next;
    // } printf("\n");
    
    // printf("push : %c\n",Q->front->data);
}

void inject(QueueType* Q, element e){
    if(isFull(Q)){ printf("Queue is Full.");exit(1);}

    QueueNode *new = (QueueNode*)malloc(sizeof(QueueNode));
    new->data = e;
    
    if(isEmpty(Q))Q->rear = new;
    else{
        QueueNode *p = Q->rear;
        while(p->next != NULL) p = p->next;
        p->next = new;
    }
    Q->size ++; // printf("inject : %c\n",Q->rear->data);
}

element pop(QueueType *Q){
    char e;
    if(isEmpty(Q)){ printf("Queue is Empty.");exit(1);}
    else{
        e = Q->rear->data; 
        if(Q->rear->next == NULL) Q->rear = NULL;
        else Q->rear = Q->rear->next;
    }
    // printf("inject : %c\n",e);
    Q->size --;
    return e;

}

element eject(QueueType *Q){
    //rear 위치의 원소를 삭제하여 반환합니다.  (- ←)
    char e;
    if(isEmpty(Q)){ printf("Queue is Empty.");exit(1);}
    else{
        QueueNode *p = Q->rear;
        QueueNode *prev;
        while(p->next != NULL){
            prev = p;
            p = p->next;
        }prev->next = NULL;
    }
    // printf("inject : %c\n",e);
    Q->size --;
    return e;

}

void printAll(QueueType *Q){
    QueueNode *p = Q->rear;
    for(int i= 0 ; i< Q->size ; i++){
        // printf(">>");
        printf("[%c]",p->data);
        p = p->next;
    } printf("\n");
}

void injectNum(QueueType *Q, int n, char* alpha){for(int i=0;i<n;i++) {inject(Q,*alpha); *alpha = *alpha + 1;}printAll(Q); }
void popNum(QueueType *Q, int n){for(int i=0;i<n;i++) pop(Q); printAll(Q); }
void pushNum(QueueType *Q, int n, char* alpha){
    for(int i=0;i<n;i++) {
        push(Q,*alpha); 
        *alpha = *alpha + 1;
    }
    printAll(Q); 
}
void ejectNum(QueueType *Q, int n){for(int i=0;i<n;i++) eject(Q); printAll(Q); }

int main(){
    QueueType Q; init(&Q);
    char alpha = 'A';// inject(&Q,alpha++);

    /*-----------------------------------------------*/
    printf("(+ ←) "); injectNum(&Q,10,&alpha);
    printf("(→ -) "); popNum(&Q,5);//에러 확인
    printf("(→ +) "); pushNum(&Q,3,&alpha);//에러 확인
    printf("(- ←) "); ejectNum(&Q,2); //에러 확인
    /*-----------------------------------------------*/
}