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
    QueueNode* front;
    QueueNode* rear;
    int size;
} QueueType;

void init(QueueType *Q){
    Q->size = 0;
    Q->front = Q->rear = NULL;
}

int isEmpty(QueueType *Q){return (Q->size==0);}
int isFull(QueueType *Q){return (Q->size >= MAX);}


void enqueue(QueueType* Q, element e){
    if(isFull(Q)){ printf("Queue is Full.");exit(1);}

    QueueNode *new = (QueueNode*)malloc(sizeof(QueueNode));
    new->data = e;
    
    if(isEmpty(Q))Q->rear = new;
    else{
        QueueNode *p = Q->rear;
        while(p->next != NULL) p = p->next;
        p->next = new;
    }
    Q->size ++; // printf("enqueue : %c\n",Q->rear->data);
}

element dequeue(QueueType *Q){
    char e;
    if(isEmpty(Q)){ printf("Queue is Empty.");exit(1);}
    else{
        e = Q->rear->data; 
        if(Q->rear->next == NULL) Q->rear = NULL;
        else Q->rear = Q->rear->next;
    }
    // printf("enqueue : %c\n",e);
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

void enqueueNum(QueueType *Q, int n, char* alpha){
    for(int i=0;i<n;i++) {enqueue(Q,*alpha); *alpha = *alpha + 1;}
    printAll(Q); 
}
void dequeueNum(QueueType *Q, int n){for(int i=0;i<n;i++) dequeue(Q); printAll(Q); }

int main(){
    QueueType Q; init(&Q);
    char alpha = 'A';// enqueue(&Q,alpha++);

    enqueueNum(&Q,10,&alpha);
    dequeueNum(&Q,5);
    enqueueNum(&Q,4,&alpha);
    dequeueNum(&Q,1);
    // enqueueNum(&Q,2,&alpha);
}